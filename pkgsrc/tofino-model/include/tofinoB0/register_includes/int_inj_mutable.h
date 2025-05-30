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
#ifndef __REGISTER_INCLUDES_INT_INJ_MUTABLE_H__
#define __REGISTER_INCLUDES_INT_INJ_MUTABLE_H__


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

class IntInjMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  IntInjMutable(
      int chipNumber, int index_pipe_addrmap, int index_ibp_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_ibp_rspec), 4, true, write_callback, read_callback, std::string("IntInjMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_ibp_rspec))
    {
    }
  IntInjMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "IntInjMutable")
    {
    }
public:






  uint8_t dual_err_inj() { return dual_err_inj_; }
  void dual_err_inj(const uint8_t &v) { dual_err_inj_=v; }





  uint8_t singl_err_inj() { return singl_err_inj_; }
  void singl_err_inj(const uint8_t &v) { singl_err_inj_=v; }





  uint8_t banksel_err_inj() { return banksel_err_inj_; }
  void banksel_err_inj(const uint8_t &v) { banksel_err_inj_=v; }





  uint8_t linklist_err_inj() { return linklist_err_inj_; }
  void linklist_err_inj(const uint8_t &v) { linklist_err_inj_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (dual_err_inj_ & 0x3f);
    *data |= ((singl_err_inj_ & 0x3f) << 6);
    *data |= ((banksel_err_inj_ & 0x3) << 16);
    *data |= ((linklist_err_inj_ & 0x1) << 20);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    dual_err_inj_ = (data & 0x3f);
    singl_err_inj_ = ((data >> 6) & 0x3f);
    banksel_err_inj_ = ((data >> 16) & 0x3);
    linklist_err_inj_ = ((data >> 20) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    dual_err_inj_ = 0x0;
    singl_err_inj_ = 0x0;
    banksel_err_inj_ = 0x0;
    linklist_err_inj_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("IntInjMutable") + ":\n";
    r += indent_string + "  " + std::string("dual_err_inj") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dual_err_inj_) ) + "\n";
    all_zeros &= (0 == dual_err_inj_);
    r += indent_string + "  " + std::string("singl_err_inj") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(singl_err_inj_) ) + "\n";
    all_zeros &= (0 == singl_err_inj_);
    r += indent_string + "  " + std::string("banksel_err_inj") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(banksel_err_inj_) ) + "\n";
    all_zeros &= (0 == banksel_err_inj_);
    r += indent_string + "  " + std::string("linklist_err_inj") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(linklist_err_inj_) ) + "\n";
    all_zeros &= (0 == linklist_err_inj_);
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
    r += indent_string + std::string("IntInjMutable") + ":\n";
    r += indent_string + "  " + std::string("dual_err_inj") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dual_err_inj_) ) + "\n";
    all_zeros &= (0 == dual_err_inj_);
    r += indent_string + "  " + std::string("singl_err_inj") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(singl_err_inj_) ) + "\n";
    all_zeros &= (0 == singl_err_inj_);
    r += indent_string + "  " + std::string("banksel_err_inj") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(banksel_err_inj_) ) + "\n";
    all_zeros &= (0 == banksel_err_inj_);
    r += indent_string + "  " + std::string("linklist_err_inj") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(linklist_err_inj_) ) + "\n";
    all_zeros &= (0 == linklist_err_inj_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t dual_err_inj_;
  uint8_t singl_err_inj_;
  uint8_t banksel_err_inj_;
  uint8_t linklist_err_inj_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_ibp_rspec
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x700000; // to get to pmarb
    assert(index_ibp_rspec < 18);
    offset += index_ibp_rspec * 0x2000; // ibp_rspec[]
    offset += 0x1800; // to get to ing_buf_regs
    offset += 0x24; // to get to glb_group_int_inj
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_INT_INJ_MUTABLE_H__
