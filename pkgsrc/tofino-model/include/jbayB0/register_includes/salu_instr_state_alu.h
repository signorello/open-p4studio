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
#ifndef __REGISTER_INCLUDES_SALU_INSTR_STATE_ALU_H__
#define __REGISTER_INCLUDES_SALU_INSTR_STATE_ALU_H__


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

class SaluInstrStateAlu : public model_core::RegisterBlock<RegisterCallback> {
public:
  SaluInstrStateAlu(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_mau_meter_alu_group_addrmap, int index_salu_instr_state_alu_0, int index_salu_instr_state_alu_1, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_mau_meter_alu_group_addrmap, index_salu_instr_state_alu_0, index_salu_instr_state_alu_1), 4, false, write_callback, read_callback, std::string("SaluInstrStateAlu")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_meter_alu_group_addrmap) + "," + boost::lexical_cast<std::string>(index_salu_instr_state_alu_0) + "," + boost::lexical_cast<std::string>(index_salu_instr_state_alu_1))
    {
    }
  SaluInstrStateAlu(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "SaluInstrStateAlu")
    {
    }
public:





  uint8_t &salu_const_src() { return salu_const_src_; }



  uint8_t &salu_regfile_const() { return salu_regfile_const_; }







  uint8_t &salu_bsrc_input() { return salu_bsrc_input_; }







  uint8_t &salu_asrc_input() { return salu_asrc_input_; }



  uint8_t &salu_op() { return salu_op_; }






  uint8_t &salu_arith() { return salu_arith_; }



  uint16_t &salu_pred() { return salu_pred_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (salu_const_src_ & 0xf);
    *data |= ((salu_regfile_const_ & 0x1) << 4);
    *data |= ((salu_bsrc_input_ & 0x7) << 5);
    *data |= ((salu_asrc_input_ & 0x7) << 8);
    *data |= ((salu_op_ & 0xf) << 11);
    *data |= ((salu_arith_ & 0x1) << 15);
    *data |= (salu_pred_ << 16);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    salu_const_src_ = (data & 0xf);
    salu_regfile_const_ = ((data >> 4) & 0x1);
    salu_bsrc_input_ = ((data >> 5) & 0x7);
    salu_asrc_input_ = ((data >> 8) & 0x7);
    salu_op_ = ((data >> 11) & 0xf);
    salu_arith_ = ((data >> 15) & 0x1);
    salu_pred_ = (data >> 16);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    salu_const_src_ = 0x0;
    salu_regfile_const_ = 0x0;
    salu_bsrc_input_ = 0x0;
    salu_asrc_input_ = 0x0;
    salu_op_ = 0x0;
    salu_arith_ = 0x0;
    salu_pred_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("SaluInstrStateAlu") + ":\n";
    r += indent_string + "  " + std::string("salu_const_src") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_const_src_) ) + "\n";
    all_zeros &= (0 == salu_const_src_);
    r += indent_string + "  " + std::string("salu_regfile_const") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_regfile_const_) ) + "\n";
    all_zeros &= (0 == salu_regfile_const_);
    r += indent_string + "  " + std::string("salu_bsrc_input") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_bsrc_input_) ) + "\n";
    all_zeros &= (0 == salu_bsrc_input_);
    r += indent_string + "  " + std::string("salu_asrc_input") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_asrc_input_) ) + "\n";
    all_zeros &= (0 == salu_asrc_input_);
    r += indent_string + "  " + std::string("salu_op") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_op_) ) + "\n";
    all_zeros &= (0 == salu_op_);
    r += indent_string + "  " + std::string("salu_arith") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_arith_) ) + "\n";
    all_zeros &= (0 == salu_arith_);
    r += indent_string + "  " + std::string("salu_pred") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_pred_) ) + "\n";
    all_zeros &= (0 == salu_pred_);
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
    r += indent_string + std::string("SaluInstrStateAlu") + ":\n";
    r += indent_string + "  " + std::string("salu_const_src") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_const_src_) ) + "\n";
    all_zeros &= (0 == salu_const_src_);
    r += indent_string + "  " + std::string("salu_regfile_const") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_regfile_const_) ) + "\n";
    all_zeros &= (0 == salu_regfile_const_);
    r += indent_string + "  " + std::string("salu_bsrc_input") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_bsrc_input_) ) + "\n";
    all_zeros &= (0 == salu_bsrc_input_);
    r += indent_string + "  " + std::string("salu_asrc_input") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_asrc_input_) ) + "\n";
    all_zeros &= (0 == salu_asrc_input_);
    r += indent_string + "  " + std::string("salu_op") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_op_) ) + "\n";
    all_zeros &= (0 == salu_op_);
    r += indent_string + "  " + std::string("salu_arith") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_arith_) ) + "\n";
    all_zeros &= (0 == salu_arith_);
    r += indent_string + "  " + std::string("salu_pred") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_pred_) ) + "\n";
    all_zeros &= (0 == salu_pred_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t salu_const_src_;
  uint8_t salu_regfile_const_;
  uint8_t salu_bsrc_input_;
  uint8_t salu_asrc_input_;
  uint8_t salu_op_;
  uint8_t salu_arith_;
  uint16_t salu_pred_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_mau_meter_alu_group_addrmap, int index_salu_instr_state_alu_0, int index_salu_instr_state_alu_1
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    assert(index_mau_addrmap < 20);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x60000; // to get to rams
    offset += 0x10000; // to get to map_alu
    offset += 0x3000; // to get to meter_group
    assert(index_mau_meter_alu_group_addrmap < 4);
    offset += index_mau_meter_alu_group_addrmap * 0x400; // mau_meter_alu_group_addrmap[]
    offset += 0x200; // to get to stateful
    offset += 0xc0; // to get to salu_instr_state_alu
    assert(index_salu_instr_state_alu_0 < 4);
    offset += index_salu_instr_state_alu_0 * 0x10; // salu_instr_state_alu[]
    assert(index_salu_instr_state_alu_1 < 4);
    offset += index_salu_instr_state_alu_1 * 0x4; // salu_instr_state_alu[][]
    return offset;
  }

};















  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_SALU_INSTR_STATE_ALU_H__
