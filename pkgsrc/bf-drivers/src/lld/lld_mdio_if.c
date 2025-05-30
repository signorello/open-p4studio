/*******************************************************************************
 *  Copyright (C) 2024 Intel Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing,
 *  software distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions
 *  and limitations under the License.
 *
 *
 *  SPDX-License-Identifier: Apache-2.0
 ******************************************************************************/


/*!
 * @file lld_mdio_if.c
 * @date
 *
 */

/**
 * @addtogroup lld-mdio-api
 * @{
 * This is a description of MDIO APIs.
 */

#include <target-sys/bf_sal/bf_sys_intf.h>
#include <dvm/bf_drv_intf.h>
#include <lld/lld_err.h>
#include <lld/lld_gpio_if.h>
#include <lld/lld_reg_if.h>
#include <sched.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <tof2_regs/tof2_reg_drv.h>
#include <tof3_regs/tof3_reg_drv.h>
#include <tofino_regs/tofino.h>

#include <target-sys/bf_sal/bf_sys_intf.h>
#include "lld.h"
#include "lld_dev.h"

/* MDIO for TF3  differs a lot from TF1/2 */
typedef struct {
  uint8_t period_reg[BF_IO_NUM_PIN_PAIR]; /* period programmed in register */
  /* mdio period (32 bits) on wire in microsec, precomputed */
  uint16_t period_4B[BF_IO_NUM_PIN_PAIR];
} bf_mdio_setting_t;

/* this structure caches current MDIO settings */
static bf_mdio_setting_t bf_mdio_setting[BF_MAX_DEV_COUNT][BF_MAX_SUBDEV_COUNT];

static bf_status_t lld_mdio_reg_wr(bf_dev_id_t dev_id,
                                   bf_subdev_id_t subdev_id,
                                   uint32_t reg,
                                   uint32_t data) {
  if (lld_subdev_write_register(dev_id, subdev_id, reg, data) == LLD_OK) {
    return BF_SUCCESS;
  } else {
    return BF_HW_COMM_FAIL;
  }
}

static bf_status_t lld_mdio_reg_rd(bf_dev_id_t dev_id,
                                   bf_subdev_id_t subdev_id,
                                   uint32_t reg,
                                   uint32_t *data) {
  if (lld_subdev_read_register(dev_id, subdev_id, reg, data) == LLD_OK) {
    return BF_SUCCESS;
  } else {
    return BF_HW_COMM_FAIL;
  }
}

/**
 * @brief  bf_io_is_mdio_mode
 *  check if the configured mode is mdio
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 *
 * @return bool
 *   true if mdio mode
 *   false if not mdio mode
 *
 */
static bool bf_io_is_mdio_mode(bf_dev_id_t dev_id,
                               bf_subdev_id_t subdev_id,
                               bf_io_pin_pair_t pin_pair) {
  bf_io_mode_t mode;

  bf_io_get_mode(dev_id, subdev_id, pin_pair, &mode);
  if (mode != BF_IO_MODE_MDIO) {
    return false;
  } else {
    return true;
  }
}

/**
 * @brief  bf_mdio_set_clk:
 *   set the mdio clock
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param clock_period: uint8_t
 *  clock period in multiples of 10ns
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio_set_clk(bf_dev_id_t dev_id,
                            bf_subdev_id_t subdev_id,
                            bf_io_pin_pair_t pin_pair,
                            uint8_t clock_period) {
  uint32_t offset;
  uint32_t data;
  uint16_t clk_div = clock_period;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio_tof3_set_clk(dev_id, subdev_id, pin_pair, clock_period));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }
  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }
  /* TOF2 clock is 156.25 Mhz and TOF1 is 100 Mhz */
  if (lld_dev_is_tof2(dev_id)) {
    if (clock_period < 2) {
      return BF_INVALID_ARG;
    }
    /* convert for 10ns * clock _period to 6.4 period clock */
    clk_div = (100 * clock_period) / 64;
    /* clkdiv must be even */
    clk_div = clk_div & 0xFFFE;
  }
  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_clkdiv);
  lld_mdio_reg_rd(dev_id, subdev_id, offset, &data);
  setp_gpio_pair_regs_mdio_clkdiv_mdio_clkdiv(&data, clk_div);
  lld_mdio_reg_wr(dev_id, subdev_id, offset, data);
  bf_mdio_setting[dev_id][subdev_id].period_reg[pin_pair] = clock_period;
  /* this is a convenience precomputed number used in mdio delays */
  /* in microseconds */
  if (lld_dev_is_tof2(dev_id)) {
    bf_mdio_setting[dev_id][subdev_id].period_4B[pin_pair] =
        (((clk_div + 1) * 64) / 10000) +
        2; /* 2 us seconds added to cover round of */
  } else {
    bf_mdio_setting[dev_id][subdev_id].period_4B[pin_pair] =
        (clk_div * 32) / 100;
  }
  return BF_SUCCESS;
}

/**
 * @brief :bf_mdio_issue_addr
 *   issue clause-45 MDIO address operation
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param phy_addr: uint8_t
 *  5 bit phy device address on mdio bus
 * @param dev_type: uint8_t
 *  5 bit dev_type field
 * @param  address: uint16_t
 *  16 bit address of address-type MDIO transaction
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio_issue_addr(bf_dev_id_t dev_id,
                               bf_subdev_id_t subdev_id,
                               bf_io_pin_pair_t pin_pair,
                               uint8_t phy_addr,
                               uint8_t dev_type,
                               uint16_t address) {
  uint32_t offset;
  uint32_t data;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio_tof3_issue_addr(
        dev_id, subdev_id, pin_pair, phy_addr, dev_type, address));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }

  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }

  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_ctrl);
  lld_mdio_reg_rd(dev_id, subdev_id, offset, &data);
  if (getp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data)) {
    return BF_IN_USE; /* mdio operation is currently going on */
  }
  /* program addr_data register */
  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_addrdata);
  data = 0;
  setp_gpio_pair_regs_mdio_addrdata_mdio_data(&data, address);
  lld_mdio_reg_wr(dev_id, subdev_id, offset, data);

  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_ctrl);
  data = 0;
  setp_gpio_pair_regs_mdio_ctrl_mdio_portaddr(&data, phy_addr);
  setp_gpio_pair_regs_mdio_ctrl_mdio_devaddr(&data, dev_type);
  /* address type mdio transaction */
  setp_gpio_pair_regs_mdio_ctrl_mdio_code(&data, 0);
  /* clause-45 type mdio transaction */
  setp_gpio_pair_regs_mdio_ctrl_mdio_type(&data, 1);
  /* set mdio-execute bit */
  setp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data, 1);

  lld_mdio_reg_wr(dev_id, subdev_id, offset, data);
  return BF_SUCCESS;
}

/**
 * @brief :bf_mdio_issue_wr
 *   issue clause-45 MDIO write operation
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param phy_addr: uint8_t
 *  5 bit phy device address on mdio bus
 * @param dev_type: uint8_t
 *  5 bit dev_type field
 * @param  mdio_data: uint16_t
 *  16 bit data of writea-type MDIO transaction
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio_issue_wr(bf_dev_id_t dev_id,
                             bf_subdev_id_t subdev_id,
                             bf_io_pin_pair_t pin_pair,
                             uint8_t phy_addr,
                             uint8_t dev_type,
                             uint16_t mdio_data) {
  uint32_t offset;
  uint32_t data;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio_tof3_issue_wr(
        dev_id, subdev_id, pin_pair, phy_addr, dev_type, mdio_data));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }

  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }

  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_ctrl);
  lld_mdio_reg_rd(dev_id, subdev_id, offset, &data);
  if (getp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data)) {
    return BF_IN_USE; /* mdio operation is currently going on */
  }
  /* program addr_data register */
  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_addrdata);
  data = 0;
  setp_gpio_pair_regs_mdio_addrdata_mdio_data(&data, mdio_data);
  lld_mdio_reg_wr(dev_id, subdev_id, offset, data);

  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_ctrl);
  data = 0;
  setp_gpio_pair_regs_mdio_ctrl_mdio_portaddr(&data, phy_addr);
  setp_gpio_pair_regs_mdio_ctrl_mdio_devaddr(&data, dev_type);
  /* write type mdio transaction */
  setp_gpio_pair_regs_mdio_ctrl_mdio_code(&data, 1);
  /* clause-45 type mdio transaction */
  setp_gpio_pair_regs_mdio_ctrl_mdio_type(&data, 1);
  /* set mdio-execute bit */
  setp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data, 1);

  lld_mdio_reg_wr(dev_id, subdev_id, offset, data);
  return BF_SUCCESS;
}

/**
 * @brief :bf_mdio_issue_rd
 *   issue clause-45 MDIO read operation
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param phy_addr: uint8_t
 *  5 bit phy device address on mdio bus
 * @param dev_type: uint8_t
 *  5 bit dev_type field
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio_issue_rd(bf_dev_id_t dev_id,
                             bf_subdev_id_t subdev_id,
                             bf_io_pin_pair_t pin_pair,
                             uint8_t phy_addr,
                             uint8_t dev_type) {
  uint32_t offset;
  uint32_t data;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (
        bf_mdio_tof3_issue_rd(dev_id, subdev_id, pin_pair, phy_addr, dev_type));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }

  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }

  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_ctrl);
  lld_mdio_reg_rd(dev_id, subdev_id, offset, &data);
  if (getp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data)) {
    return BF_IN_USE; /* mdio operation is currently going on */
  }

  data = 0;
  setp_gpio_pair_regs_mdio_ctrl_mdio_portaddr(&data, phy_addr);
  setp_gpio_pair_regs_mdio_ctrl_mdio_devaddr(&data, dev_type);
  /* read type mdio transaction */
  setp_gpio_pair_regs_mdio_ctrl_mdio_code(&data, 3);
  /* clause-45 type mdio transaction */
  setp_gpio_pair_regs_mdio_ctrl_mdio_type(&data, 1);
  /* set mdio-execute bit */
  setp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data, 1);

  lld_mdio_reg_wr(dev_id, subdev_id, offset, data);
  return BF_SUCCESS;
}

/**
 * @brief : bf_mdio_issue_rd_and_incr_addr
 *   issue clause-45 MDIO operation : read with address post increment
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param phy_addr: uint8_t
 *  5 bit phy device address on mdio bus
 * @param dev_type: uint8_t
 *  5 bit dev_type field
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio_issue_rd_and_incr_addr(bf_dev_id_t dev_id,
                                           bf_subdev_id_t subdev_id,
                                           bf_io_pin_pair_t pin_pair,
                                           uint8_t phy_addr,
                                           uint8_t dev_type) {
  uint32_t offset;
  uint32_t data;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio_tof3_issue_rd_and_incr_addr(
        dev_id, subdev_id, pin_pair, phy_addr, dev_type));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }

  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }

  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_ctrl);
  lld_mdio_reg_rd(dev_id, subdev_id, offset, &data);
  if (getp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data)) {
    return BF_IN_USE; /* mdio operation is currently going on */
  }

  data = 0;
  setp_gpio_pair_regs_mdio_ctrl_mdio_portaddr(&data, phy_addr);
  setp_gpio_pair_regs_mdio_ctrl_mdio_devaddr(&data, dev_type);
  /* read and address ipost increment type mdio transaction */
  setp_gpio_pair_regs_mdio_ctrl_mdio_code(&data, 2);
  /* clause-45 type mdio transaction */
  setp_gpio_pair_regs_mdio_ctrl_mdio_type(&data, 1);
  /* set mdio-execute bit */
  setp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data, 1);

  lld_mdio_reg_wr(dev_id, subdev_id, offset, data);
  return BF_SUCCESS;
}

/**
 * @brief :bf_mdio22_issue_wr
 *   issue clause-22 MDIO write operation
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param phy_addr: uint8_t
 *  5 bit phy device address on mdio bus
 * @param reg_addr: uint8_t
 *  5 bit reg_addr field
 * @param  mdio_data: uint16_t
 *  16 bit data of writea-type MDIO transaction
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio22_issue_wr(bf_dev_id_t dev_id,
                               bf_subdev_id_t subdev_id,
                               bf_io_pin_pair_t pin_pair,
                               uint8_t phy_addr,
                               uint8_t reg_addr,
                               uint16_t mdio_data) {
  uint32_t offset;
  uint32_t data;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio22_tof3_issue_wr(
        dev_id, subdev_id, pin_pair, phy_addr, reg_addr, mdio_data));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }

  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }

  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_ctrl);
  lld_mdio_reg_rd(dev_id, subdev_id, offset, &data);
  if (getp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data)) {
    return BF_IN_USE; /* mdio operation is currently going on */
  }

  /* program addr_data register */
  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_addrdata);
  data = 0;
  setp_gpio_pair_regs_mdio_addrdata_mdio_data(&data, mdio_data);
  lld_mdio_reg_wr(dev_id, subdev_id, offset, data);

  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_ctrl);
  data = 0;
  setp_gpio_pair_regs_mdio_ctrl_mdio_portaddr(&data, phy_addr);
  setp_gpio_pair_regs_mdio_ctrl_mdio_devaddr(&data, reg_addr);
  /* write type mdio transaction */
  setp_gpio_pair_regs_mdio_ctrl_mdio_code(&data, 1);
  /* clause-22 type mdio transaction */
  setp_gpio_pair_regs_mdio_ctrl_mdio_type(&data, 0);
  /* set mdio-execute bit */
  setp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data, 1);

  lld_mdio_reg_wr(dev_id, subdev_id, offset, data);
  return BF_SUCCESS;
}

/**
 * @brief :bf_mdio22_issue_rd
 *   issue clause-22 MDIO read operation
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param phy_addr: uint8_t
 *  5 bit phy device address on mdio bus
 * @param reg_addr: uint8_t
 *  5 bit reg_addr field
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio22_issue_rd(bf_dev_id_t dev_id,
                               bf_subdev_id_t subdev_id,
                               bf_io_pin_pair_t pin_pair,
                               uint8_t phy_addr,
                               uint8_t reg_addr) {
  uint32_t offset;
  uint32_t data;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio22_tof3_issue_rd(
        dev_id, subdev_id, pin_pair, phy_addr, reg_addr));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }

  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }

  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_ctrl);
  lld_mdio_reg_rd(dev_id, subdev_id, offset, &data);
  if (getp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data)) {
    return BF_IN_USE; /* mdio operation is currently going on */
  }

  data = 0;
  setp_gpio_pair_regs_mdio_ctrl_mdio_portaddr(&data, phy_addr);
  setp_gpio_pair_regs_mdio_ctrl_mdio_devaddr(&data, reg_addr);
  /* read type mdio transaction */
  setp_gpio_pair_regs_mdio_ctrl_mdio_code(&data, 2);
  /* clause-22 type mdio transaction */
  setp_gpio_pair_regs_mdio_ctrl_mdio_type(&data, 0);
  /* set mdio-execute bit */
  setp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data, 1);

  lld_mdio_reg_wr(dev_id, subdev_id, offset, data);
  return BF_SUCCESS;
}

/**
 * @brief bf_mdio_get_completion_status
 *  returns the ccurrent mdio completion status
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param complete: bool
 *  true:complete, false: incomplete (on-going)
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio_get_completion_status(bf_dev_id_t dev_id,
                                          bf_subdev_id_t subdev_id,
                                          bf_io_pin_pair_t pin_pair,
                                          bool *complete) {
  uint32_t offset;
  uint32_t data;

  if ((dev_id >= BF_MAX_DEV_COUNT) || (subdev_id >= BF_MAX_SUBDEV_COUNT) ||
      !complete) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio_tof3_get_completion_status(
        dev_id, subdev_id, pin_pair, complete));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }
  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_ctrl);
  lld_mdio_reg_rd(dev_id, subdev_id, offset, &data);
  *complete = !getp_gpio_pair_regs_mdio_ctrl_mdio_exec(&data);
  return BF_SUCCESS;
}

/**
 * @brief bf_mdio_get_rd_data
 *  get the mdio_read data from a previously completed mdio-45 read operation
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param mdio_data: uint16_t *
 *  mdio data (read back)
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio_get_rd_data(bf_dev_id_t dev_id,
                                bf_subdev_id_t subdev_id,
                                bf_io_pin_pair_t pin_pair,
                                uint16_t *mdio_data) {
  uint32_t offset;
  uint32_t data;

  if ((dev_id >= BF_MAX_DEV_COUNT) || (subdev_id >= BF_MAX_SUBDEV_COUNT) ||
      !mdio_data) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio_tof3_get_rd_data(dev_id, subdev_id, pin_pair, mdio_data));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }
  offset = GPIO_PAIR_OFFSET(dev_id, pin_pair, mdio_addrdata);
  lld_mdio_reg_rd(dev_id, subdev_id, offset, &data);
  *mdio_data = (uint16_t)getp_gpio_pair_regs_mdio_addrdata_mdio_data(&data);
  return BF_SUCCESS;
}

/**
 * @brief bf_mdio22_get_rd_data
 *  get the mdio_read data from a previously completed mdio-22 read operation
 *
 * @param dev_id: int
 *  dev_id id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param mdio_data: uint16_t *
 *  mdio data (read back)
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio22_get_rd_data(bf_dev_id_t dev_id,
                                  bf_subdev_id_t subdev_id,
                                  bf_io_pin_pair_t pin_pair,
                                  uint16_t *mdio_data) {
  return (bf_mdio_get_rd_data(dev_id, subdev_id, pin_pair, mdio_data));
}

/* API to check for MDIO done status
 * checks cnt times with a microsec delay in between before returning
 */
static int bf_mdio_check_for_comp(bf_dev_id_t dev_id,
                                  bf_subdev_id_t subdev_id,
                                  bf_io_pin_pair_t pin_pair,
                                  int cnt,
                                  int microsec) {
  bool complete;
  int wait_cnt = 0;

  while (wait_cnt++ < cnt) {
    bf_sys_usleep(microsec);
    if (bf_mdio_get_completion_status(dev_id, subdev_id, pin_pair, &complete) !=
        BF_SUCCESS) {
      return -1;
    }
    if (complete) {
      return 0;
    }
  }
  return -1;
}

/**
 * @brief : bf_mdio_addr_blocking
 *  clause-45 MDIO address operation
 *  could block for upto 12 bytes of mdio wire-time
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param phy_addr: uint8_t
 *  5 bit phy device address on mdio bus
 * @param dev_type: uint8_t
 *  5 bit dev_type field
 * @param  address: uint16_t
 *  16 bit address of address-type MDIO transaction
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio_addr_blocking(bf_dev_id_t dev_id,
                                  bf_subdev_id_t subdev_id,
                                  bf_io_pin_pair_t pin_pair,
                                  uint8_t phy_addr,
                                  uint8_t dev_type,
                                  uint16_t address) {
  bf_status_t status;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio_tof3_addr_blocking(
        dev_id, subdev_id, pin_pair, phy_addr, dev_type, address));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }

  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }
  /* issue the mdio op */
  status = bf_mdio_issue_addr(
      dev_id, subdev_id, pin_pair, phy_addr, dev_type, address);
  if (status != BF_SUCCESS) {
    return status;
  }
  /* wait for completion */
  if (bf_mdio_check_for_comp(
          dev_id,
          subdev_id,
          pin_pair,
          3,
          bf_mdio_setting[dev_id][subdev_id].period_4B[pin_pair])) {
    return BF_HW_COMM_FAIL;
  } else {
    return BF_SUCCESS;
  }
}

/**
 * @brief : bf_mdio_wr_blocking
 *  clause-45 MDIO write operation
 *  could block for upto 12 bytes of mdio wire-time
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param phy_addr: uint8_t
 *  5 bit phy device address on mdio bus
 * @param dev_type: uint8_t
 *  5 bit dev_type field
 * @param  data: uint16_t
 *  16 bit data of write-type MDIO transaction
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio_wr_blocking(bf_dev_id_t dev_id,
                                bf_subdev_id_t subdev_id,
                                bf_io_pin_pair_t pin_pair,
                                uint8_t phy_addr,
                                uint8_t dev_type,
                                uint16_t data) {
  bf_status_t status;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio_tof3_wr_blocking(
        dev_id, subdev_id, pin_pair, phy_addr, dev_type, data));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }

  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }
  /* issue the mdio op */
  status =
      bf_mdio_issue_wr(dev_id, subdev_id, pin_pair, phy_addr, dev_type, data);
  if (status != BF_SUCCESS) {
    return status;
  }
  /* wait for completion */
  if (bf_mdio_check_for_comp(
          dev_id,
          subdev_id,
          pin_pair,
          3,
          bf_mdio_setting[dev_id][subdev_id].period_4B[pin_pair])) {
    return BF_HW_COMM_FAIL;
  } else {
    return BF_SUCCESS;
  }
}

/**
 * @brief : bf_mdio_rd_blocking
 *  clause-45 MDIO read operation
 *  could block for upto 12 bytes of mdio wire-time
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param phy_addr: uint8_t
 *  5 bit phy device address on mdio bus
 * @param dev_type: uint8_t
 *  5 bit dev_type field
 * @param  data: uint16_t *
 *  16 bit data read back
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio_rd_blocking(bf_dev_id_t dev_id,
                                bf_subdev_id_t subdev_id,
                                bf_io_pin_pair_t pin_pair,
                                uint8_t phy_addr,
                                uint8_t dev_type,
                                uint16_t *data) {
  bf_status_t status;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio_tof3_rd_blocking(
        dev_id, subdev_id, pin_pair, phy_addr, dev_type, data));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }

  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }
  /* issue the mdio op */
  status = bf_mdio_issue_rd(dev_id, subdev_id, pin_pair, phy_addr, dev_type);
  if (status != BF_SUCCESS) {
    return status;
  }
  /* wait for completion */
  if (bf_mdio_check_for_comp(
          dev_id,
          subdev_id,
          pin_pair,
          3,
          bf_mdio_setting[dev_id][subdev_id].period_4B[pin_pair])) {
    return BF_HW_COMM_FAIL;
  }
  /* read the data */
  status = bf_mdio_get_rd_data(dev_id, subdev_id, pin_pair, data);
  return status;
}

/**
 * @brief : bf_mdio_rd_and_incr_addr_blocking
 *  clause-45 MDIO operation : read with post address increment
 *  could block for upto 12 bytes of mdio wire-time
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param phy_addr: uint8_t
 *  5 bit phy device address on mdio bus
 * @param dev_type: uint8_t
 *  5 bit dev_type field
 * @param  data: uint16_t *
 *  16 bit data read back
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio_rd_and_incr_addr_blocking(bf_dev_id_t dev_id,
                                              bf_subdev_id_t subdev_id,
                                              bf_io_pin_pair_t pin_pair,
                                              uint8_t phy_addr,
                                              uint8_t dev_type,
                                              uint16_t *data) {
  bf_status_t status;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio_tof3_rd_and_incr_addr_blocking(
        dev_id, subdev_id, pin_pair, phy_addr, dev_type, data));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }

  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }
  /* issue the mdio op */
  status = bf_mdio_issue_rd_and_incr_addr(
      dev_id, subdev_id, pin_pair, phy_addr, dev_type);
  if (status != BF_SUCCESS) {
    return status;
  }
  /* wait for completion */
  if (bf_mdio_check_for_comp(
          dev_id,
          subdev_id,
          pin_pair,
          3,
          bf_mdio_setting[dev_id][subdev_id].period_4B[pin_pair])) {
    return BF_HW_COMM_FAIL;
  }
  /* read the data */
  status = bf_mdio_get_rd_data(dev_id, subdev_id, pin_pair, data);
  return status;
}

/**
 * @brief : bf_mdio22_wr_blocking
 *  clause-22 MDIO write operation
 *  could block for upto 12 bytes of mdio wire-time
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param phy_addr: uint8_t
 *  5 bit phy device address on mdio bus
 * @param dev_type: uint8_t
 *  5 bit dev_type field
 * @param  data : uint16_t
 *  16 bit data of write-type MDIO transaction
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio22_wr_blocking(bf_dev_id_t dev_id,
                                  bf_subdev_id_t subdev_id,
                                  bf_io_pin_pair_t pin_pair,
                                  uint8_t phy_addr,
                                  uint8_t reg_addr,
                                  uint16_t data) {
  bf_status_t status;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio22_tof3_wr_blocking(
        dev_id, subdev_id, pin_pair, phy_addr, reg_addr, data));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }

  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }
  /* issue the mdio op */
  status =
      bf_mdio22_issue_wr(dev_id, subdev_id, pin_pair, phy_addr, reg_addr, data);
  if (status != BF_SUCCESS) {
    return status;
  }
  /* wait for completion */
  if (bf_mdio_check_for_comp(
          dev_id,
          subdev_id,
          pin_pair,
          3,
          bf_mdio_setting[dev_id][subdev_id].period_4B[pin_pair])) {
    return BF_HW_COMM_FAIL;
  } else {
    return BF_SUCCESS;
  }
}

/**
 * @brief : bf_mdio22_rd_blocking
 *  clause-45 MDIO read operation
 *  could block for upto 12 bytes of mdio wire-time
 *
 * @param dev_id: int
 *  dev_id id
 * @param subdev_id: int
 *  subdev_id subdevice within dev_id
 * @param pin_pair: enum
 *  which of the 12 pin-pairs to configure
 * @param phy_addr: uint8_t
 *  5 bit phy device address on mdio bus
 * @param dev_type: uint8_t
 *  5 bit dev_type field
 * @param  data: uint16_t *
 *  16 bit data read back
 *
 * @return status
 *   BF_SUCCESS on success
 *   BF ERROR code on failure
 *
 */
bf_status_t bf_mdio22_rd_blocking(bf_dev_id_t dev_id,
                                  bf_subdev_id_t subdev_id,
                                  bf_io_pin_pair_t pin_pair,
                                  uint8_t phy_addr,
                                  uint8_t reg_addr,
                                  uint16_t *data) {
  bf_status_t status;

  if (dev_id >= BF_MAX_DEV_COUNT || subdev_id >= BF_MAX_SUBDEV_COUNT) {
    return BF_INVALID_ARG;
  }
  if (lld_dev_is_tof3(dev_id)) {
    return (bf_mdio22_tof3_rd_blocking(
        dev_id, subdev_id, pin_pair, phy_addr, reg_addr, data));
  } else {
    if (pin_pair > BF_IO_PIN_PAIR_MAX) {
      return BF_INVALID_ARG;
    }
  }

  if (!bf_io_is_mdio_mode(dev_id, subdev_id, pin_pair)) {
    return BF_IN_USE;
  }
  /* issue the mdio op */
  status = bf_mdio22_issue_rd(dev_id, subdev_id, pin_pair, phy_addr, reg_addr);
  if (status != BF_SUCCESS) {
    return status;
  }
  /* wait for completion */
  if (bf_mdio_check_for_comp(
          dev_id,
          subdev_id,
          pin_pair,
          3,
          bf_mdio_setting[dev_id][subdev_id].period_4B[pin_pair])) {
    return BF_HW_COMM_FAIL;
  }
  /* read the data */
  status = bf_mdio22_get_rd_data(dev_id, subdev_id, pin_pair, data);
  return status;
}
/**
 * @}
 */
