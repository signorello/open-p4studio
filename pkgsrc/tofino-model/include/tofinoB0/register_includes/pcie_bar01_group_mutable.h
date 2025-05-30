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

// generated by split_classes.pl
#ifndef __REGISTER_INCLUDES_PCIE_BAR01_GROUP_MUTABLE_H__
#define __REGISTER_INCLUDES_PCIE_BAR01_GROUP_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "cpu_glb_ctrl_mutable.h"
#include "cpu_ind_addr_high_mutable.h"
#include "cpu_ind_addr_low_mutable.h"
#include "cpu_ind_data00_mutable.h"
#include "cpu_ind_data01_mutable.h"
#include "cpu_ind_data10_mutable.h"
#include "cpu_ind_data11_mutable.h"
#include "cpu_ind_rerr_mutable.h"
#include "default_pciehdr_param_mutable.h"
#include "dma_glb_ctrl_mutable.h"
#include "dma_tag_pndg_mutable.h"
#include "dmard_thruput_ctrl_mutable.h"
#include "freerun_cnt_mutable.h"
#include "glb_shadow_int_mutable.h"
#include "int_timeout_ctrl_mutable.h"
#include "msix_ram_err_addr_mutable.h"
#include "pcie_bus_dev_mutable.h"
#include "pcie_dev_info_mutable.h"
#include "pcie_dma_temp_stall_mutable.h"
#include "pcie_int_en_mutable.h"
#include "pcie_int_freeze_mutable.h"
#include "pcie_int_inj_mutable.h"
#include "pcie_int_stat_mutable.h"
#include "pcie_mst_cred_mutable.h"
#include "pcie_ram_err_addr_mutable.h"
#include "shadow_int_mutable.h"
#include "shadow_msk_mutable.h"
#include "window0_base_high_mutable.h"
#include "window0_base_param_mutable.h"
#include "window0_limit_high_mutable.h"
#include "window0_limit_low_mutable.h"
#include "window1_base_high_mutable.h"
#include "window1_base_param_mutable.h"
#include "window1_limit_high_mutable.h"
#include "window1_limit_low_mutable.h"
#include "wrr_table0_mutable.h"
#include "wrr_table1_mutable.h"
#include "wrr_table2_mutable.h"
#include "wrr_table3_mutable.h"

namespace tofinoB0 {
  namespace register_classes {

class PcieBar01GroupMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  PcieBar01GroupMutable(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 372, true, write_callback, read_callback, std::string("PcieBar01GroupMutable"))
    {
    }
  PcieBar01GroupMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "PcieBar01GroupMutable")
    {
    }
public:





  FreerunCntMutable &pcie_regs_freerun_cnt() { return pcie_regs_freerun_cnt_; }





  DmaGlbCtrlMutable &pcie_regs_dma_glb_ctrl() { return pcie_regs_dma_glb_ctrl_; }












  WrrTable0Mutable &pcie_regs_wrr_table0() { return pcie_regs_wrr_table0_; }












  WrrTable1Mutable &pcie_regs_wrr_table1() { return pcie_regs_wrr_table1_; }












  WrrTable2Mutable &pcie_regs_wrr_table2() { return pcie_regs_wrr_table2_; }












  WrrTable3Mutable &pcie_regs_wrr_table3() { return pcie_regs_wrr_table3_; }








  DmardThruputCtrlMutable &pcie_regs_dmard_thruput_ctrl() { return pcie_regs_dmard_thruput_ctrl_; }






  IntTimeoutCtrlMutable &pcie_regs_int_timeout_ctrl() { return pcie_regs_int_timeout_ctrl_; }






  CpuGlbCtrlMutable &pcie_regs_cpu_glb_ctrl() { return pcie_regs_cpu_glb_ctrl_; }





  CpuIndAddrLowMutable &pcie_regs_cpu_ind_addr_low() { return pcie_regs_cpu_ind_addr_low_; }





  CpuIndAddrHighMutable &pcie_regs_cpu_ind_addr_high() { return pcie_regs_cpu_ind_addr_high_; }





  CpuIndData00Mutable &pcie_regs_cpu_ind_data00() { return pcie_regs_cpu_ind_data00_; }





  CpuIndData01Mutable &pcie_regs_cpu_ind_data01() { return pcie_regs_cpu_ind_data01_; }





  CpuIndData10Mutable &pcie_regs_cpu_ind_data10() { return pcie_regs_cpu_ind_data10_; }





  CpuIndData11Mutable &pcie_regs_cpu_ind_data11() { return pcie_regs_cpu_ind_data11_; }





  CpuIndRerrMutable &pcie_regs_cpu_ind_rerr() { return pcie_regs_cpu_ind_rerr_; }







  DmaTagPndgMutable &pcie_regs_dma_tag_pndg() { return pcie_regs_dma_tag_pndg_; }







  GlbShadowIntMutable &pcie_regs_glb_shadow_int() { return pcie_regs_glb_shadow_int_; }









  ShadowIntMutable &pcie_regs_shadow_int(int j0) { return pcie_regs_shadow_int_[j0]; }








  ShadowMskMutable &pcie_regs_shadow_msk(int j0) { return pcie_regs_shadow_msk_[j0]; }





  Window0BaseParamMutable &pcie_regs_window0_base_param() { return pcie_regs_window0_base_param_; }





  Window0BaseHighMutable &pcie_regs_window0_base_high() { return pcie_regs_window0_base_high_; }





  Window0LimitLowMutable &pcie_regs_window0_limit_low() { return pcie_regs_window0_limit_low_; }





  Window0LimitHighMutable &pcie_regs_window0_limit_high() { return pcie_regs_window0_limit_high_; }





  Window1BaseParamMutable &pcie_regs_window1_base_param() { return pcie_regs_window1_base_param_; }





  Window1BaseHighMutable &pcie_regs_window1_base_high() { return pcie_regs_window1_base_high_; }





  Window1LimitLowMutable &pcie_regs_window1_limit_low() { return pcie_regs_window1_limit_low_; }





  Window1LimitHighMutable &pcie_regs_window1_limit_high() { return pcie_regs_window1_limit_high_; }





  DefaultPciehdrParamMutable &pcie_regs_default_pciehdr_param() { return pcie_regs_default_pciehdr_param_; }





  PcieIntStatMutable &pcie_regs_pcie_int_stat() { return pcie_regs_pcie_int_stat_; }





  PcieIntEnMutable &pcie_regs_pcie_int_en() { return pcie_regs_pcie_int_en_; }






  PcieIntInjMutable &pcie_regs_pcie_int_inj() { return pcie_regs_pcie_int_inj_; }





  PcieRamErrAddrMutable &pcie_regs_pcie_ram_err_addr() { return pcie_regs_pcie_ram_err_addr_; }





  MsixRamErrAddrMutable &pcie_regs_msix_ram_err_addr() { return pcie_regs_msix_ram_err_addr_; }







  PcieDevInfoMutable &pcie_regs_pcie_dev_info(int j0) { return pcie_regs_pcie_dev_info_[j0]; }





  PcieBusDevMutable &pcie_regs_pcie_bus_dev() { return pcie_regs_pcie_bus_dev_; }






  PcieDmaTempStallMutable &pcie_regs_pcie_dma_temp_stall() { return pcie_regs_pcie_dma_temp_stall_; }





  PcieMstCredMutable &pcie_regs_pcie_mst_cred() { return pcie_regs_pcie_mst_cred_; }





  PcieIntFreezeMutable &pcie_regs_pcie_int_freeze() { return pcie_regs_pcie_int_freeze_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      if (read_callback_) read_callback_();
      pcie_regs_freerun_cnt_.read( offset, data );
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      if (read_callback_) read_callback_();
      pcie_regs_dma_glb_ctrl_.read( offset, data );
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      if (read_callback_) read_callback_();
      pcie_regs_wrr_table0_.read( offset, data );
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      if (read_callback_) read_callback_();
      pcie_regs_wrr_table1_.read( offset, data );
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      if (read_callback_) read_callback_();
      pcie_regs_wrr_table2_.read( offset, data );
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      if (read_callback_) read_callback_();
      pcie_regs_wrr_table3_.read( offset, data );
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      if (read_callback_) read_callback_();
      pcie_regs_dmard_thruput_ctrl_.read( offset, data );
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      if (read_callback_) read_callback_();
      pcie_regs_int_timeout_ctrl_.read( offset, data );
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      if (read_callback_) read_callback_();
      pcie_regs_cpu_glb_ctrl_.read( offset, data );
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      if (read_callback_) read_callback_();
      pcie_regs_cpu_ind_addr_low_.read( offset, data );
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      if (read_callback_) read_callback_();
      pcie_regs_cpu_ind_addr_high_.read( offset, data );
    }
    else if (offset >= 0x40 && offset < 0x44) {
      offset -= 0x40;
      if (read_callback_) read_callback_();
      pcie_regs_cpu_ind_data00_.read( offset, data );
    }
    else if (offset >= 0x44 && offset < 0x48) {
      offset -= 0x44;
      if (read_callback_) read_callback_();
      pcie_regs_cpu_ind_data01_.read( offset, data );
    }
    else if (offset >= 0x48 && offset < 0x4c) {
      offset -= 0x48;
      if (read_callback_) read_callback_();
      pcie_regs_cpu_ind_data10_.read( offset, data );
    }
    else if (offset >= 0x4c && offset < 0x50) {
      offset -= 0x4c;
      if (read_callback_) read_callback_();
      pcie_regs_cpu_ind_data11_.read( offset, data );
    }
    else if (offset >= 0x50 && offset < 0x54) {
      offset -= 0x50;
      if (read_callback_) read_callback_();
      pcie_regs_cpu_ind_rerr_.read( offset, data );
    }
    else if (offset >= 0x54 && offset < 0x58) {
      offset -= 0x54;
      if (read_callback_) read_callback_();
      pcie_regs_dma_tag_pndg_.read( offset, data );
    }
    else if (offset >= 0x58 && offset < 0x5c) {
      offset -= 0x58;
      if (read_callback_) read_callback_();
      pcie_regs_glb_shadow_int_.read( offset, data );
    }
    else if (offset >= 0x80 && offset < 0xc0) {
      offset -= 0x80;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      pcie_regs_shadow_int_[ i0 ].read( offset, data );
    }
    else if (offset >= 0xc0 && offset < 0x100) {
      offset -= 0xc0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      pcie_regs_shadow_msk_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x100 && offset < 0x104) {
      offset -= 0x100;
      if (read_callback_) read_callback_();
      pcie_regs_window0_base_param_.read( offset, data );
    }
    else if (offset >= 0x104 && offset < 0x108) {
      offset -= 0x104;
      if (read_callback_) read_callback_();
      pcie_regs_window0_base_high_.read( offset, data );
    }
    else if (offset >= 0x108 && offset < 0x10c) {
      offset -= 0x108;
      if (read_callback_) read_callback_();
      pcie_regs_window0_limit_low_.read( offset, data );
    }
    else if (offset >= 0x10c && offset < 0x110) {
      offset -= 0x10c;
      if (read_callback_) read_callback_();
      pcie_regs_window0_limit_high_.read( offset, data );
    }
    else if (offset >= 0x110 && offset < 0x114) {
      offset -= 0x110;
      if (read_callback_) read_callback_();
      pcie_regs_window1_base_param_.read( offset, data );
    }
    else if (offset >= 0x114 && offset < 0x118) {
      offset -= 0x114;
      if (read_callback_) read_callback_();
      pcie_regs_window1_base_high_.read( offset, data );
    }
    else if (offset >= 0x118 && offset < 0x11c) {
      offset -= 0x118;
      if (read_callback_) read_callback_();
      pcie_regs_window1_limit_low_.read( offset, data );
    }
    else if (offset >= 0x11c && offset < 0x120) {
      offset -= 0x11c;
      if (read_callback_) read_callback_();
      pcie_regs_window1_limit_high_.read( offset, data );
    }
    else if (offset >= 0x120 && offset < 0x124) {
      offset -= 0x120;
      if (read_callback_) read_callback_();
      pcie_regs_default_pciehdr_param_.read( offset, data );
    }
    else if (offset >= 0x124 && offset < 0x128) {
      offset -= 0x124;
      if (read_callback_) read_callback_();
      pcie_regs_pcie_int_stat_.read( offset, data );
    }
    else if (offset >= 0x128 && offset < 0x12c) {
      offset -= 0x128;
      if (read_callback_) read_callback_();
      pcie_regs_pcie_int_en_.read( offset, data );
    }
    else if (offset >= 0x12c && offset < 0x130) {
      offset -= 0x12c;
      if (read_callback_) read_callback_();
      pcie_regs_pcie_int_inj_.read( offset, data );
    }
    else if (offset >= 0x130 && offset < 0x134) {
      offset -= 0x130;
      if (read_callback_) read_callback_();
      pcie_regs_pcie_ram_err_addr_.read( offset, data );
    }
    else if (offset >= 0x134 && offset < 0x138) {
      offset -= 0x134;
      if (read_callback_) read_callback_();
      pcie_regs_msix_ram_err_addr_.read( offset, data );
    }
    else if (offset >= 0x140 && offset < 0x160) {
      offset -= 0x140;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      pcie_regs_pcie_dev_info_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x160 && offset < 0x164) {
      offset -= 0x160;
      if (read_callback_) read_callback_();
      pcie_regs_pcie_bus_dev_.read( offset, data );
    }
    else if (offset >= 0x164 && offset < 0x168) {
      offset -= 0x164;
      if (read_callback_) read_callback_();
      pcie_regs_pcie_dma_temp_stall_.read( offset, data );
    }
    else if (offset >= 0x168 && offset < 0x16c) {
      offset -= 0x168;
      if (read_callback_) read_callback_();
      pcie_regs_pcie_mst_cred_.read( offset, data );
    }
    else if (offset >= 0x16c && offset < 0x170) {
      offset -= 0x16c;
      if (read_callback_) read_callback_();
      pcie_regs_pcie_int_freeze_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      pcie_regs_freerun_cnt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      pcie_regs_dma_glb_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      pcie_regs_wrr_table0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      pcie_regs_wrr_table1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      pcie_regs_wrr_table2_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      pcie_regs_wrr_table3_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      pcie_regs_dmard_thruput_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      pcie_regs_int_timeout_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      pcie_regs_cpu_glb_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      pcie_regs_cpu_ind_addr_low_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      pcie_regs_cpu_ind_addr_high_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x40 && offset < 0x44) {
      offset -= 0x40;
      pcie_regs_cpu_ind_data00_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x44 && offset < 0x48) {
      offset -= 0x44;
      pcie_regs_cpu_ind_data01_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x48 && offset < 0x4c) {
      offset -= 0x48;
      pcie_regs_cpu_ind_data10_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4c && offset < 0x50) {
      offset -= 0x4c;
      pcie_regs_cpu_ind_data11_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x50 && offset < 0x54) {
      offset -= 0x50;
      pcie_regs_cpu_ind_rerr_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x54 && offset < 0x58) {
      offset -= 0x54;
      pcie_regs_dma_tag_pndg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x58 && offset < 0x5c) {
      offset -= 0x58;
      pcie_regs_glb_shadow_int_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x80 && offset < 0xc0) {
      offset -= 0x80;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      pcie_regs_shadow_int_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc0 && offset < 0x100) {
      offset -= 0xc0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      pcie_regs_shadow_msk_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x100 && offset < 0x104) {
      offset -= 0x100;
      pcie_regs_window0_base_param_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x104 && offset < 0x108) {
      offset -= 0x104;
      pcie_regs_window0_base_high_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x108 && offset < 0x10c) {
      offset -= 0x108;
      pcie_regs_window0_limit_low_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10c && offset < 0x110) {
      offset -= 0x10c;
      pcie_regs_window0_limit_high_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x110 && offset < 0x114) {
      offset -= 0x110;
      pcie_regs_window1_base_param_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x114 && offset < 0x118) {
      offset -= 0x114;
      pcie_regs_window1_base_high_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x118 && offset < 0x11c) {
      offset -= 0x118;
      pcie_regs_window1_limit_low_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x11c && offset < 0x120) {
      offset -= 0x11c;
      pcie_regs_window1_limit_high_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x120 && offset < 0x124) {
      offset -= 0x120;
      pcie_regs_default_pciehdr_param_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x124 && offset < 0x128) {
      offset -= 0x124;
      pcie_regs_pcie_int_stat_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x128 && offset < 0x12c) {
      offset -= 0x128;
      pcie_regs_pcie_int_en_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x12c && offset < 0x130) {
      offset -= 0x12c;
      pcie_regs_pcie_int_inj_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x130 && offset < 0x134) {
      offset -= 0x130;
      pcie_regs_pcie_ram_err_addr_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x134 && offset < 0x138) {
      offset -= 0x134;
      pcie_regs_msix_ram_err_addr_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x140 && offset < 0x160) {
      offset -= 0x140;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      pcie_regs_pcie_dev_info_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x160 && offset < 0x164) {
      offset -= 0x160;
      pcie_regs_pcie_bus_dev_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x164 && offset < 0x168) {
      offset -= 0x164;
      pcie_regs_pcie_dma_temp_stall_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x168 && offset < 0x16c) {
      offset -= 0x168;
      pcie_regs_pcie_mst_cred_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x16c && offset < 0x170) {
      offset -= 0x16c;
      pcie_regs_pcie_int_freeze_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    pcie_regs_freerun_cnt_.reset();
    pcie_regs_dma_glb_ctrl_.reset();
    pcie_regs_wrr_table0_.reset();
    pcie_regs_wrr_table1_.reset();
    pcie_regs_wrr_table2_.reset();
    pcie_regs_wrr_table3_.reset();
    pcie_regs_dmard_thruput_ctrl_.reset();
    pcie_regs_int_timeout_ctrl_.reset();
    pcie_regs_cpu_glb_ctrl_.reset();
    pcie_regs_cpu_ind_addr_low_.reset();
    pcie_regs_cpu_ind_addr_high_.reset();
    pcie_regs_cpu_ind_data00_.reset();
    pcie_regs_cpu_ind_data01_.reset();
    pcie_regs_cpu_ind_data10_.reset();
    pcie_regs_cpu_ind_data11_.reset();
    pcie_regs_cpu_ind_rerr_.reset();
    pcie_regs_dma_tag_pndg_.reset();
    pcie_regs_glb_shadow_int_.reset();
    for (auto &f0 : pcie_regs_shadow_int_) {
      f0.reset();
    }
    for (auto &f0 : pcie_regs_shadow_msk_) {
      f0.reset();
    }
    pcie_regs_window0_base_param_.reset();
    pcie_regs_window0_base_high_.reset();
    pcie_regs_window0_limit_low_.reset();
    pcie_regs_window0_limit_high_.reset();
    pcie_regs_window1_base_param_.reset();
    pcie_regs_window1_base_high_.reset();
    pcie_regs_window1_limit_low_.reset();
    pcie_regs_window1_limit_high_.reset();
    pcie_regs_default_pciehdr_param_.reset();
    pcie_regs_pcie_int_stat_.reset();
    pcie_regs_pcie_int_en_.reset();
    pcie_regs_pcie_int_inj_.reset();
    pcie_regs_pcie_ram_err_addr_.reset();
    pcie_regs_msix_ram_err_addr_.reset();
    for (auto &f0 : pcie_regs_pcie_dev_info_) {
      f0.reset();
    }
    pcie_regs_pcie_bus_dev_.reset();
    pcie_regs_pcie_dma_temp_stall_.reset();
    pcie_regs_pcie_mst_cred_.reset();
    pcie_regs_pcie_int_freeze_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      r += pcie_regs_freerun_cnt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      r += pcie_regs_dma_glb_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      r += pcie_regs_wrr_table0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      r += pcie_regs_wrr_table1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      r += pcie_regs_wrr_table2_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      r += pcie_regs_wrr_table3_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      r += pcie_regs_dmard_thruput_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      r += pcie_regs_int_timeout_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      r += pcie_regs_cpu_glb_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      r += pcie_regs_cpu_ind_addr_low_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      r += pcie_regs_cpu_ind_addr_high_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x40 && offset < 0x44) {
      offset -= 0x40;
      r += pcie_regs_cpu_ind_data00_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x44 && offset < 0x48) {
      offset -= 0x44;
      r += pcie_regs_cpu_ind_data01_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x48 && offset < 0x4c) {
      offset -= 0x48;
      r += pcie_regs_cpu_ind_data10_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4c && offset < 0x50) {
      offset -= 0x4c;
      r += pcie_regs_cpu_ind_data11_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x50 && offset < 0x54) {
      offset -= 0x50;
      r += pcie_regs_cpu_ind_rerr_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x54 && offset < 0x58) {
      offset -= 0x54;
      r += pcie_regs_dma_tag_pndg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x58 && offset < 0x5c) {
      offset -= 0x58;
      r += pcie_regs_glb_shadow_int_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x80 && offset < 0xc0) {
      offset -= 0x80;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += pcie_regs_shadow_int_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc0 && offset < 0x100) {
      offset -= 0xc0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += pcie_regs_shadow_msk_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x100 && offset < 0x104) {
      offset -= 0x100;
      r += pcie_regs_window0_base_param_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x104 && offset < 0x108) {
      offset -= 0x104;
      r += pcie_regs_window0_base_high_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x108 && offset < 0x10c) {
      offset -= 0x108;
      r += pcie_regs_window0_limit_low_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10c && offset < 0x110) {
      offset -= 0x10c;
      r += pcie_regs_window0_limit_high_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x110 && offset < 0x114) {
      offset -= 0x110;
      r += pcie_regs_window1_base_param_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x114 && offset < 0x118) {
      offset -= 0x114;
      r += pcie_regs_window1_base_high_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x118 && offset < 0x11c) {
      offset -= 0x118;
      r += pcie_regs_window1_limit_low_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x11c && offset < 0x120) {
      offset -= 0x11c;
      r += pcie_regs_window1_limit_high_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x120 && offset < 0x124) {
      offset -= 0x120;
      r += pcie_regs_default_pciehdr_param_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x124 && offset < 0x128) {
      offset -= 0x124;
      r += pcie_regs_pcie_int_stat_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x128 && offset < 0x12c) {
      offset -= 0x128;
      r += pcie_regs_pcie_int_en_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x12c && offset < 0x130) {
      offset -= 0x12c;
      r += pcie_regs_pcie_int_inj_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x130 && offset < 0x134) {
      offset -= 0x130;
      r += pcie_regs_pcie_ram_err_addr_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x134 && offset < 0x138) {
      offset -= 0x134;
      r += pcie_regs_msix_ram_err_addr_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x140 && offset < 0x160) {
      offset -= 0x140;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += pcie_regs_pcie_dev_info_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x160 && offset < 0x164) {
      offset -= 0x160;
      r += pcie_regs_pcie_bus_dev_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x164 && offset < 0x168) {
      offset -= 0x164;
      r += pcie_regs_pcie_dma_temp_stall_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x168 && offset < 0x16c) {
      offset -= 0x168;
      r += pcie_regs_pcie_mst_cred_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x16c && offset < 0x170) {
      offset -= 0x16c;
      r += pcie_regs_pcie_int_freeze_.to_string(offset,print_zeros,indent_string) ;
    }
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

  std::string to_string(
      bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    r += pcie_regs_freerun_cnt_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_dma_glb_ctrl_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_wrr_table0_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_wrr_table1_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_wrr_table2_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_wrr_table3_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_dmard_thruput_ctrl_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_int_timeout_ctrl_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_cpu_glb_ctrl_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_cpu_ind_addr_low_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_cpu_ind_addr_high_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_cpu_ind_data00_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_cpu_ind_data01_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_cpu_ind_data10_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_cpu_ind_data11_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_cpu_ind_rerr_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_dma_tag_pndg_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_glb_shadow_int_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<16;++a0) {
      r += pcie_regs_shadow_int_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<16;++a0) {
      r += pcie_regs_shadow_msk_[a0].to_string(print_zeros,indent_string) ;
    }
    r += pcie_regs_window0_base_param_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_window0_base_high_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_window0_limit_low_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_window0_limit_high_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_window1_base_param_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_window1_base_high_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_window1_limit_low_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_window1_limit_high_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_default_pciehdr_param_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_pcie_int_stat_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_pcie_int_en_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_pcie_int_inj_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_pcie_ram_err_addr_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_msix_ram_err_addr_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<8;++a0) {
      r += pcie_regs_pcie_dev_info_[a0].to_string(print_zeros,indent_string) ;
    }
    r += pcie_regs_pcie_bus_dev_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_pcie_dma_temp_stall_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_pcie_mst_cred_.to_string(print_zeros,indent_string) ;
    r += pcie_regs_pcie_int_freeze_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  FreerunCntMutable pcie_regs_freerun_cnt_;
  DmaGlbCtrlMutable pcie_regs_dma_glb_ctrl_;
  WrrTable0Mutable pcie_regs_wrr_table0_;
  WrrTable1Mutable pcie_regs_wrr_table1_;
  WrrTable2Mutable pcie_regs_wrr_table2_;
  WrrTable3Mutable pcie_regs_wrr_table3_;
  DmardThruputCtrlMutable pcie_regs_dmard_thruput_ctrl_;
  IntTimeoutCtrlMutable pcie_regs_int_timeout_ctrl_;
  CpuGlbCtrlMutable pcie_regs_cpu_glb_ctrl_;
  CpuIndAddrLowMutable pcie_regs_cpu_ind_addr_low_;
  CpuIndAddrHighMutable pcie_regs_cpu_ind_addr_high_;
  CpuIndData00Mutable pcie_regs_cpu_ind_data00_;
  CpuIndData01Mutable pcie_regs_cpu_ind_data01_;
  CpuIndData10Mutable pcie_regs_cpu_ind_data10_;
  CpuIndData11Mutable pcie_regs_cpu_ind_data11_;
  CpuIndRerrMutable pcie_regs_cpu_ind_rerr_;
  DmaTagPndgMutable pcie_regs_dma_tag_pndg_;
  GlbShadowIntMutable pcie_regs_glb_shadow_int_;
  std::array< ShadowIntMutable, 16 > pcie_regs_shadow_int_;
  std::array< ShadowMskMutable, 16 > pcie_regs_shadow_msk_;
  Window0BaseParamMutable pcie_regs_window0_base_param_;
  Window0BaseHighMutable pcie_regs_window0_base_high_;
  Window0LimitLowMutable pcie_regs_window0_limit_low_;
  Window0LimitHighMutable pcie_regs_window0_limit_high_;
  Window1BaseParamMutable pcie_regs_window1_base_param_;
  Window1BaseHighMutable pcie_regs_window1_base_high_;
  Window1LimitLowMutable pcie_regs_window1_limit_low_;
  Window1LimitHighMutable pcie_regs_window1_limit_high_;
  DefaultPciehdrParamMutable pcie_regs_default_pciehdr_param_;
  PcieIntStatMutable pcie_regs_pcie_int_stat_;
  PcieIntEnMutable pcie_regs_pcie_int_en_;
  PcieIntInjMutable pcie_regs_pcie_int_inj_;
  PcieRamErrAddrMutable pcie_regs_pcie_ram_err_addr_;
  MsixRamErrAddrMutable pcie_regs_msix_ram_err_addr_;
  std::array< PcieDevInfoMutable, 8 > pcie_regs_pcie_dev_info_;
  PcieBusDevMutable pcie_regs_pcie_bus_dev_;
  PcieDmaTempStallMutable pcie_regs_pcie_dma_temp_stall_;
  PcieMstCredMutable pcie_regs_pcie_mst_cred_;
  PcieIntFreezeMutable pcie_regs_pcie_int_freeze_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_PCIE_BAR01_GROUP_MUTABLE_H__
