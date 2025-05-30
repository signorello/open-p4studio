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
#ifndef __REGISTER_INCLUDES_PBUS_DMA_STATEMACHINE_H__
#define __REGISTER_INCLUDES_PBUS_DMA_STATEMACHINE_H__


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

class PbusDmaStatemachine : public model_core::RegisterBlock<RegisterCallback> {
public:
  PbusDmaStatemachine(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, false, write_callback, read_callback, std::string("PbusDmaStatemachine"))
    {
    }
  PbusDmaStatemachine(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PbusDmaStatemachine")
    {
    }
public:





  uint8_t &wb_read() { return wb_read_; }





  uint8_t &wb_write() { return wb_write_; }





  uint8_t &rb_read() { return rb_read_; }





  uint8_t &rb_write() { return rb_write_; }





  uint8_t &stat_write() { return stat_write_; }





  uint8_t &idle_write() { return idle_write_; }





  uint8_t &diag() { return diag_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (wb_read_ & 0x1);
    *data |= ((wb_write_ & 0x7) << 1);
    *data |= ((rb_read_ & 0x1) << 4);
    *data |= ((rb_write_ & 0x7) << 5);
    *data |= ((stat_write_ & 0x7) << 8);
    *data |= ((idle_write_ & 0x7) << 11);
    *data |= ((diag_ & 0xf) << 14);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    wb_read_ = (data & 0x1);
    wb_write_ = ((data >> 1) & 0x7);
    rb_read_ = ((data >> 4) & 0x1);
    rb_write_ = ((data >> 5) & 0x7);
    stat_write_ = ((data >> 8) & 0x7);
    idle_write_ = ((data >> 11) & 0x7);
    diag_ = ((data >> 14) & 0xf);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    wb_read_ = 0x0;
    wb_write_ = 0x0;
    rb_read_ = 0x0;
    rb_write_ = 0x0;
    stat_write_ = 0x0;
    idle_write_ = 0x0;
    diag_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PbusDmaStatemachine") + ":\n";
    r += indent_string + "  " + std::string("wb_read") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wb_read_) ) + "\n";
    all_zeros &= (0 == wb_read_);
    r += indent_string + "  " + std::string("wb_write") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wb_write_) ) + "\n";
    all_zeros &= (0 == wb_write_);
    r += indent_string + "  " + std::string("rb_read") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_read_) ) + "\n";
    all_zeros &= (0 == rb_read_);
    r += indent_string + "  " + std::string("rb_write") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_write_) ) + "\n";
    all_zeros &= (0 == rb_write_);
    r += indent_string + "  " + std::string("stat_write") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stat_write_) ) + "\n";
    all_zeros &= (0 == stat_write_);
    r += indent_string + "  " + std::string("idle_write") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(idle_write_) ) + "\n";
    all_zeros &= (0 == idle_write_);
    r += indent_string + "  " + std::string("diag") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(diag_) ) + "\n";
    all_zeros &= (0 == diag_);
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
    r += indent_string + std::string("PbusDmaStatemachine") + ":\n";
    r += indent_string + "  " + std::string("wb_read") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wb_read_) ) + "\n";
    all_zeros &= (0 == wb_read_);
    r += indent_string + "  " + std::string("wb_write") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wb_write_) ) + "\n";
    all_zeros &= (0 == wb_write_);
    r += indent_string + "  " + std::string("rb_read") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_read_) ) + "\n";
    all_zeros &= (0 == rb_read_);
    r += indent_string + "  " + std::string("rb_write") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_write_) ) + "\n";
    all_zeros &= (0 == rb_write_);
    r += indent_string + "  " + std::string("stat_write") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stat_write_) ) + "\n";
    all_zeros &= (0 == stat_write_);
    r += indent_string + "  " + std::string("idle_write") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(idle_write_) ) + "\n";
    all_zeros &= (0 == idle_write_);
    r += indent_string + "  " + std::string("diag") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(diag_) ) + "\n";
    all_zeros &= (0 == diag_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t wb_read_;
  uint8_t wb_write_;
  uint8_t rb_read_;
  uint8_t rb_write_;
  uint8_t stat_write_;
  uint8_t idle_write_;
  uint8_t diag_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x100000; // to get to pbc
    offset += 0x33c; // to get to dma_statemachine
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_PBUS_DMA_STATEMACHINE_H__
