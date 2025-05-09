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
#ifndef __REGISTER_INCLUDES_PMERGE_LOWER_LEFT_REG_H__
#define __REGISTER_INCLUDES_PMERGE_LOWER_LEFT_REG_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "pmerge_lower_left_reg_debug_ctrl.h"
#include "pmerge_lower_left_reg_i_mac_empty_4_0.h"
#include "pmerge_lower_left_reg_i_occ_oflow_err_log.h"
#include "pmerge_lower_left_reg_i_pre_wr_addr.h"
#include "pmerge_lower_left_reg_i_slot_ou_flow_err_log.h"
#include "pmerge_lower_left_reg_intr.h"
#include "pmerge_lower_left_reg_port_rate_cfg_4_0.h"

namespace jbayB0 {
  namespace register_classes {

class PmergeLowerLeftReg : public model_core::RegisterBlock<RegisterCallback> {
public:
  PmergeLowerLeftReg(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 512, false, write_callback, read_callback, std::string("PmergeLowerLeftReg")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PmergeLowerLeftReg(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PmergeLowerLeftReg")
    {
    }
public:









  PmergeLowerLeftRegPortRateCfg_4_0 &port_rate_cfg_4_0(int j0) { return port_rate_cfg_4_0_[j0]; }







  PmergeLowerLeftRegIMacEmpty_4_0 &i_mac_empty_4_0(int j0) { return i_mac_empty_4_0_[j0]; }





  PmergeLowerLeftRegDebugCtrl &debug_ctrl() { return debug_ctrl_; }





  PmergeLowerLeftRegIOccOflowErrLog &i_occ_oflow_err_log() { return i_occ_oflow_err_log_; }





  PmergeLowerLeftRegISlotOuFlowErrLog &i_slot_ou_flow_err_log() { return i_slot_ou_flow_err_log_; }







  PmergeLowerLeftRegIPreWrAddr &i_pre_wr_addr() { return i_pre_wr_addr_; }
  PmergeLowerLeftRegIntr &intr() { return intr_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0x20 && offset < 0x34) {
      offset -= 0x20;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      port_rate_cfg_4_0_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x40 && offset < 0x54) {
      offset -= 0x40;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      i_mac_empty_4_0_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x54 && offset < 0x58) {
      offset -= 0x54;
      if (read_callback_) read_callback_();
      debug_ctrl_.read( offset, data );
    }
    else if (offset >= 0x74 && offset < 0x78) {
      offset -= 0x74;
      if (read_callback_) read_callback_();
      i_occ_oflow_err_log_.read( offset, data );
    }
    else if (offset >= 0x78 && offset < 0x7c) {
      offset -= 0x78;
      if (read_callback_) read_callback_();
      i_slot_ou_flow_err_log_.read( offset, data );
    }
    else if (offset >= 0x7c && offset < 0x80) {
      offset -= 0x7c;
      if (read_callback_) read_callback_();
      i_pre_wr_addr_.read( offset, data );
    }
    else if (offset >= 0x60 && offset < 0x74) {
      offset -= 0x60;
      if (read_callback_) read_callback_();
      intr_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0x20 && offset < 0x34) {
      offset -= 0x20;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      port_rate_cfg_4_0_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x40 && offset < 0x54) {
      offset -= 0x40;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      i_mac_empty_4_0_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x54 && offset < 0x58) {
      offset -= 0x54;
      debug_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x74 && offset < 0x78) {
      offset -= 0x74;
      i_occ_oflow_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x78 && offset < 0x7c) {
      offset -= 0x78;
      i_slot_ou_flow_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x7c && offset < 0x80) {
      offset -= 0x7c;
      i_pre_wr_addr_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x60 && offset < 0x74) {
      offset -= 0x60;
      intr_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    for (auto &f0 : port_rate_cfg_4_0_) {
      f0.reset();
    }
    for (auto &f0 : i_mac_empty_4_0_) {
      f0.reset();
    }
    debug_ctrl_.reset();
    i_occ_oflow_err_log_.reset();
    i_slot_ou_flow_err_log_.reset();
    i_pre_wr_addr_.reset();
    intr_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset >= 0x20 && offset < 0x34) {
      offset -= 0x20;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += port_rate_cfg_4_0_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x40 && offset < 0x54) {
      offset -= 0x40;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += i_mac_empty_4_0_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x54 && offset < 0x58) {
      offset -= 0x54;
      r += debug_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x74 && offset < 0x78) {
      offset -= 0x74;
      r += i_occ_oflow_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x78 && offset < 0x7c) {
      offset -= 0x78;
      r += i_slot_ou_flow_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x7c && offset < 0x80) {
      offset -= 0x7c;
      r += i_pre_wr_addr_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x60 && offset < 0x74) {
      offset -= 0x60;
      r += intr_.to_string(offset,print_zeros,indent_string) ;
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
    for (uint32_t a0=0;a0<5;++a0) {
      r += port_rate_cfg_4_0_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<5;++a0) {
      r += i_mac_empty_4_0_[a0].to_string(print_zeros,indent_string) ;
    }
    r += debug_ctrl_.to_string(print_zeros,indent_string) ;
    r += i_occ_oflow_err_log_.to_string(print_zeros,indent_string) ;
    r += i_slot_ou_flow_err_log_.to_string(print_zeros,indent_string) ;
    r += i_pre_wr_addr_.to_string(print_zeros,indent_string) ;
    r += intr_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::array< PmergeLowerLeftRegPortRateCfg_4_0, 5 > port_rate_cfg_4_0_;
  std::array< PmergeLowerLeftRegIMacEmpty_4_0, 5 > i_mac_empty_4_0_;
  PmergeLowerLeftRegDebugCtrl debug_ctrl_;
  PmergeLowerLeftRegIOccOflowErrLog i_occ_oflow_err_log_;
  PmergeLowerLeftRegISlotOuFlowErrLog i_slot_ou_flow_err_log_;
  PmergeLowerLeftRegIPreWrAddr i_pre_wr_addr_;
  PmergeLowerLeftRegIntr intr_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x12000; // to get to pmergereg
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_PMERGE_LOWER_LEFT_REG_H__
