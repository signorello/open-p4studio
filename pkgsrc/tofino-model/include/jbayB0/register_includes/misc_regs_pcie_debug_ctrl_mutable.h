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
#ifndef __REGISTER_INCLUDES_MISC_REGS_PCIE_DEBUG_CTRL_MUTABLE_H__
#define __REGISTER_INCLUDES_MISC_REGS_PCIE_DEBUG_CTRL_MUTABLE_H__


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

class MiscRegsPcieDebugCtrlMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  MiscRegsPcieDebugCtrlMutable(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, true, write_callback, read_callback, std::string("MiscRegsPcieDebugCtrlMutable"))
    {
    }
  MiscRegsPcieDebugCtrlMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "MiscRegsPcieDebugCtrlMutable")
    {
    }
public:





  uint16_t base_addr() { return base_addr_; }
  void base_addr(const uint16_t &v) { base_addr_=v; }





  uint16_t limit_addr() { return limit_addr_; }
  void limit_addr(const uint16_t &v) { limit_addr_=v; }






  uint8_t log_ena() { return log_ena_; }
  void log_ena(const uint8_t &v) { log_ena_=v; }






  uint8_t circular() { return circular_; }
  void circular(const uint8_t &v) { circular_=v; }











  uint8_t event_sel() { return event_sel_; }
  void event_sel(const uint8_t &v) { event_sel_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (base_addr_ & 0xfff);
    *data |= ((limit_addr_ & 0xfff) << 12);
    *data |= ((log_ena_ & 0x1) << 24);
    *data |= ((circular_ & 0x1) << 25);
    *data |= ((event_sel_ & 0x3f) << 26);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    base_addr_ = (data & 0xfff);
    limit_addr_ = ((data >> 12) & 0xfff);
    log_ena_ = ((data >> 24) & 0x1);
    circular_ = ((data >> 25) & 0x1);
    event_sel_ = ((data >> 26) & 0x3f);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    base_addr_ = 0x0;
    limit_addr_ = 0xfff;
    log_ena_ = 0x1;
    circular_ = 0x1;
    event_sel_ = 0x3f;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("MiscRegsPcieDebugCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("base_addr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(base_addr_) ) + "\n";
    all_zeros &= (0 == base_addr_);
    r += indent_string + "  " + std::string("limit_addr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(limit_addr_) ) + "\n";
    all_zeros &= (0 == limit_addr_);
    r += indent_string + "  " + std::string("log_ena") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(log_ena_) ) + "\n";
    all_zeros &= (0 == log_ena_);
    r += indent_string + "  " + std::string("circular") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(circular_) ) + "\n";
    all_zeros &= (0 == circular_);
    r += indent_string + "  " + std::string("event_sel") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(event_sel_) ) + "\n";
    all_zeros &= (0 == event_sel_);
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
    r += indent_string + std::string("MiscRegsPcieDebugCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("base_addr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(base_addr_) ) + "\n";
    all_zeros &= (0 == base_addr_);
    r += indent_string + "  " + std::string("limit_addr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(limit_addr_) ) + "\n";
    all_zeros &= (0 == limit_addr_);
    r += indent_string + "  " + std::string("log_ena") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(log_ena_) ) + "\n";
    all_zeros &= (0 == log_ena_);
    r += indent_string + "  " + std::string("circular") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(circular_) ) + "\n";
    all_zeros &= (0 == circular_);
    r += indent_string + "  " + std::string("event_sel") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(event_sel_) ) + "\n";
    all_zeros &= (0 == event_sel_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t base_addr_;
  uint16_t limit_addr_;
  uint8_t log_ena_;
  uint8_t circular_;
  uint8_t event_sel_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x80000; // to get to misc_regs
    offset += 0x254; // to get to pcie_debug_ctrl
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_MISC_REGS_PCIE_DEBUG_CTRL_MUTABLE_H__
