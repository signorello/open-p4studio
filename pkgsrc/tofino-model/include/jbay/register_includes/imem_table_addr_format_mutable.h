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
#ifndef __REGISTER_INCLUDES_IMEM_TABLE_ADDR_FORMAT_MUTABLE_H__
#define __REGISTER_INCLUDES_IMEM_TABLE_ADDR_FORMAT_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>










namespace jbay {
  namespace register_classes {

class ImemTableAddrFormatMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  ImemTableAddrFormatMutable(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_imem_table_addr_format, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_imem_table_addr_format), 4, true, write_callback, read_callback, std::string("ImemTableAddrFormatMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_imem_table_addr_format))
    {
    }
  ImemTableAddrFormatMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "ImemTableAddrFormatMutable")
    {
    }
public:







  uint8_t bitmap_range() { return bitmap_range_; }
  void bitmap_range(const uint8_t &v) { bitmap_range_=v; }


  uint8_t bitmap_color() { return bitmap_color_; }
  void bitmap_color(const uint8_t &v) { bitmap_color_=v; }



  uint8_t addr_format() { return addr_format_; }
  void addr_format(const uint8_t &v) { addr_format_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (bitmap_range_ & 0x3);
    *data |= ((bitmap_color_ & 0x1) << 2);
    *data |= ((addr_format_ & 0x1) << 3);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    bitmap_range_ = (data & 0x3);
    bitmap_color_ = ((data >> 2) & 0x1);
    addr_format_ = ((data >> 3) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    bitmap_range_ = 0x0;
    bitmap_color_ = 0x0;
    addr_format_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("ImemTableAddrFormatMutable") + ":\n";
    r += indent_string + "  " + std::string("bitmap_range") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bitmap_range_) ) + "\n";
    all_zeros &= (0 == bitmap_range_);
    r += indent_string + "  " + std::string("bitmap_color") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bitmap_color_) ) + "\n";
    all_zeros &= (0 == bitmap_color_);
    r += indent_string + "  " + std::string("addr_format") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(addr_format_) ) + "\n";
    all_zeros &= (0 == addr_format_);
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
    r += indent_string + std::string("ImemTableAddrFormatMutable") + ":\n";
    r += indent_string + "  " + std::string("bitmap_range") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bitmap_range_) ) + "\n";
    all_zeros &= (0 == bitmap_range_);
    r += indent_string + "  " + std::string("bitmap_color") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bitmap_color_) ) + "\n";
    all_zeros &= (0 == bitmap_color_);
    r += indent_string + "  " + std::string("addr_format") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(addr_format_) ) + "\n";
    all_zeros &= (0 == addr_format_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t bitmap_range_;
  uint8_t bitmap_color_;
  uint8_t addr_format_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_imem_table_addr_format
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    assert(index_mau_addrmap < 20);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x201c0; // to get to imem_table_addr_format
    assert(index_imem_table_addr_format < 16);
    offset += index_imem_table_addr_format * 0x4; // imem_table_addr_format[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_IMEM_TABLE_ADDR_FORMAT_MUTABLE_H__
