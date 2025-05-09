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
#ifndef __REGISTER_INCLUDES_PGR_IPB_CHNL_XOFF_CFG_MUTABLE_H__
#define __REGISTER_INCLUDES_PGR_IPB_CHNL_XOFF_CFG_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>










namespace jbayB0 {
  namespace register_classes {

class PgrIpbChnlXoffCfgMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  PgrIpbChnlXoffCfgMutable(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4, true, write_callback, read_callback, std::string("PgrIpbChnlXoffCfgMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PgrIpbChnlXoffCfgMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "PgrIpbChnlXoffCfgMutable")
    {
    }
public:






  uint8_t xoff_cfg_ovr() { return xoff_cfg_ovr_; }
  void xoff_cfg_ovr(const uint8_t &v) { xoff_cfg_ovr_=v; }








  uint8_t xoff_cfg_val(int j0) { return xoff_cfg_val_[j0]; }
  void xoff_cfg_val(int j0,const uint8_t &v) { xoff_cfg_val_[j0]=v; }






  uint8_t xoff_stop_eth_cpu_fifo_rd() { return xoff_stop_eth_cpu_fifo_rd_; }
  void xoff_stop_eth_cpu_fifo_rd(const uint8_t &v) { xoff_stop_eth_cpu_fifo_rd_=v; }






  uint8_t xoff_allow_tbc_fifo_rd() { return xoff_allow_tbc_fifo_rd_; }
  void xoff_allow_tbc_fifo_rd(const uint8_t &v) { xoff_allow_tbc_fifo_rd_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = xoff_cfg_ovr_;
    *data |= ((xoff_cfg_val_[0] & 0x1) << 8);
    *data |= ((xoff_cfg_val_[1] & 0x1) << 9);
    *data |= ((xoff_cfg_val_[2] & 0x1) << 10);
    *data |= ((xoff_cfg_val_[3] & 0x1) << 11);
    *data |= ((xoff_cfg_val_[4] & 0x1) << 12);
    *data |= ((xoff_cfg_val_[5] & 0x1) << 13);
    *data |= ((xoff_cfg_val_[6] & 0x1) << 14);
    *data |= ((xoff_cfg_val_[7] & 0x1) << 15);
    *data |= ((xoff_stop_eth_cpu_fifo_rd_ & 0x1) << 16);
    *data |= ((xoff_allow_tbc_fifo_rd_ & 0x1) << 17);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    xoff_cfg_ovr_ = data;
    xoff_cfg_val_[0] = ((data >> 8) & 0x1);
    xoff_cfg_val_[1] = ((data >> 9) & 0x1);
    xoff_cfg_val_[2] = ((data >> 10) & 0x1);
    xoff_cfg_val_[3] = ((data >> 11) & 0x1);
    xoff_cfg_val_[4] = ((data >> 12) & 0x1);
    xoff_cfg_val_[5] = ((data >> 13) & 0x1);
    xoff_cfg_val_[6] = ((data >> 14) & 0x1);
    xoff_cfg_val_[7] = ((data >> 15) & 0x1);
    xoff_stop_eth_cpu_fifo_rd_ = ((data >> 16) & 0x1);
    xoff_allow_tbc_fifo_rd_ = ((data >> 17) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    xoff_cfg_ovr_ = 0x0;
    xoff_cfg_val_[0] = 0x0;
    xoff_cfg_val_[1] = 0x0;
    xoff_cfg_val_[2] = 0x0;
    xoff_cfg_val_[3] = 0x0;
    xoff_cfg_val_[4] = 0x0;
    xoff_cfg_val_[5] = 0x0;
    xoff_cfg_val_[6] = 0x0;
    xoff_cfg_val_[7] = 0x0;
    xoff_stop_eth_cpu_fifo_rd_ = 0x0;
    xoff_allow_tbc_fifo_rd_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PgrIpbChnlXoffCfgMutable") + ":\n";
    r += indent_string + "  " + std::string("xoff_cfg_ovr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(xoff_cfg_ovr_) ) + "\n";
    all_zeros &= (0 == xoff_cfg_ovr_);
    for (uint32_t f=0;f<8;++f) {
      r += indent_string + "  " + std::string("xoff_cfg_val") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(xoff_cfg_val_[f]) ) + "\n";
      all_zeros &= (0 == xoff_cfg_val_[f]);
    }
    r += indent_string + "  " + std::string("xoff_stop_eth_cpu_fifo_rd") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(xoff_stop_eth_cpu_fifo_rd_) ) + "\n";
    all_zeros &= (0 == xoff_stop_eth_cpu_fifo_rd_);
    r += indent_string + "  " + std::string("xoff_allow_tbc_fifo_rd") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(xoff_allow_tbc_fifo_rd_) ) + "\n";
    all_zeros &= (0 == xoff_allow_tbc_fifo_rd_);
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
    r += indent_string + std::string("PgrIpbChnlXoffCfgMutable") + ":\n";
    r += indent_string + "  " + std::string("xoff_cfg_ovr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(xoff_cfg_ovr_) ) + "\n";
    all_zeros &= (0 == xoff_cfg_ovr_);
    for (uint32_t f=0;f<8;++f) {
      r += indent_string + "  " + std::string("xoff_cfg_val") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(xoff_cfg_val_[f]) ) + "\n";
      all_zeros &= (0 == xoff_cfg_val_[f]);
    }
    r += indent_string + "  " + std::string("xoff_stop_eth_cpu_fifo_rd") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(xoff_stop_eth_cpu_fifo_rd_) ) + "\n";
    all_zeros &= (0 == xoff_stop_eth_cpu_fifo_rd_);
    r += indent_string + "  " + std::string("xoff_allow_tbc_fifo_rd") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(xoff_allow_tbc_fifo_rd_) ) + "\n";
    all_zeros &= (0 == xoff_allow_tbc_fifo_rd_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t xoff_cfg_ovr_;
  std::array< uint8_t, 8 > xoff_cfg_val_;
  uint8_t xoff_stop_eth_cpu_fifo_rd_;
  uint8_t xoff_allow_tbc_fifo_rd_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x34000; // to get to pgrreg
    offset += 0x2000; // to get to pgr_common
    offset += 0x1dc; // to get to ipb_chnl_xoff_cfg
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_PGR_IPB_CHNL_XOFF_CFG_MUTABLE_H__
