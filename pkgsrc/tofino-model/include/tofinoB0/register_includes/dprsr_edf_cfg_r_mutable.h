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
#ifndef __REGISTER_INCLUDES_DPRSR_EDF_CFG_R_MUTABLE_H__
#define __REGISTER_INCLUDES_DPRSR_EDF_CFG_R_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>












namespace tofinoB0 {
  namespace register_classes {

class DprsrEdfCfgRMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum DprsrRegRspecEnum {
    kOutEgr,
    kOutIngr
  };
public:
  DprsrEdfCfgRMutable(
      int chipNumber, int index_pipe_addrmap, DprsrRegRspecEnum selector_dprsr_reg_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, selector_dprsr_reg_rspec), 4, true, write_callback, read_callback, std::string("DprsrEdfCfgRMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(selector_dprsr_reg_rspec))
    {
    }
  DprsrEdfCfgRMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "DprsrEdfCfgRMutable")
    {
    }
public:






  uint8_t rst_if_bp() { return rst_if_bp_; }
  void rst_if_bp(const uint8_t &v) { rst_if_bp_=v; }







  uint8_t ignore_3cell() { return ignore_3cell_; }
  void ignore_3cell(const uint8_t &v) { ignore_3cell_=v; }






  uint8_t enbl_multi_reject() { return enbl_multi_reject_; }
  void enbl_multi_reject(const uint8_t &v) { enbl_multi_reject_=v; }






  uint8_t no_count_on_ebuf_bp() { return no_count_on_ebuf_bp_; }
  void no_count_on_ebuf_bp(const uint8_t &v) { no_count_on_ebuf_bp_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (rst_if_bp_ & 0x1);
    *data |= ((ignore_3cell_ & 0x1) << 1);
    *data |= ((enbl_multi_reject_ & 0x1) << 2);
    *data |= ((no_count_on_ebuf_bp_ & 0x1) << 3);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    rst_if_bp_ = (data & 0x1);
    ignore_3cell_ = ((data >> 1) & 0x1);
    enbl_multi_reject_ = ((data >> 2) & 0x1);
    no_count_on_ebuf_bp_ = ((data >> 3) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    rst_if_bp_ = 0x0;
    ignore_3cell_ = 0x0;
    enbl_multi_reject_ = 0x0;
    no_count_on_ebuf_bp_ = 0x1;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("DprsrEdfCfgRMutable") + ":\n";
    r += indent_string + "  " + std::string("rst_if_bp") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rst_if_bp_) ) + "\n";
    all_zeros &= (0 == rst_if_bp_);
    r += indent_string + "  " + std::string("ignore_3cell") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ignore_3cell_) ) + "\n";
    all_zeros &= (0 == ignore_3cell_);
    r += indent_string + "  " + std::string("enbl_multi_reject") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(enbl_multi_reject_) ) + "\n";
    all_zeros &= (0 == enbl_multi_reject_);
    r += indent_string + "  " + std::string("no_count_on_ebuf_bp") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(no_count_on_ebuf_bp_) ) + "\n";
    all_zeros &= (0 == no_count_on_ebuf_bp_);
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
    r += indent_string + std::string("DprsrEdfCfgRMutable") + ":\n";
    r += indent_string + "  " + std::string("rst_if_bp") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rst_if_bp_) ) + "\n";
    all_zeros &= (0 == rst_if_bp_);
    r += indent_string + "  " + std::string("ignore_3cell") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ignore_3cell_) ) + "\n";
    all_zeros &= (0 == ignore_3cell_);
    r += indent_string + "  " + std::string("enbl_multi_reject") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(enbl_multi_reject_) ) + "\n";
    all_zeros &= (0 == enbl_multi_reject_);
    r += indent_string + "  " + std::string("no_count_on_ebuf_bp") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(no_count_on_ebuf_bp_) ) + "\n";
    all_zeros &= (0 == no_count_on_ebuf_bp_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t rst_if_bp_;
  uint8_t ignore_3cell_;
  uint8_t enbl_multi_reject_;
  uint8_t no_count_on_ebuf_bp_;
private:
  static int StartOffset(
      int index_pipe_addrmap, DprsrRegRspecEnum selector_dprsr_reg_rspec
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x780000; // to get to deparser
    switch (selector_dprsr_reg_rspec) {
      case kOutEgr:
        offset += 0x18000; // to get to out_egr
        offset += 0x960; // to get to edf_cfg
        break;
      case kOutIngr:
        offset += 0x10000; // to get to out_ingr
        offset += 0x980; // to get to edf_cfg
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};













  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_DPRSR_EDF_CFG_R_MUTABLE_H__
