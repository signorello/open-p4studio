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
#ifndef __REGISTER_INCLUDES_MIRROR_COAL_TO_ENTRY_R_H__
#define __REGISTER_INCLUDES_MIRROR_COAL_TO_ENTRY_R_H__


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

class MirrorCoalToEntryR : public model_core::RegisterBlock<RegisterCallback> {
public:
  MirrorCoalToEntryR(
      int chipNumber, int index_pipe_addrmap, int index_mirror_slice_mem, int index_mirror_coal_to_entry_r, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mirror_slice_mem, index_mirror_coal_to_entry_r), 4, false, write_callback, read_callback, std::string("MirrorCoalToEntryR")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mirror_slice_mem) + "," + boost::lexical_cast<std::string>(index_mirror_coal_to_entry_r))
    {
    }
  MirrorCoalToEntryR(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "MirrorCoalToEntryR")
    {
    }
public:






  uint32_t &coal_timeout() { return coal_timeout_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (coal_timeout_ & 0xffffff);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    coal_timeout_ = (data & 0xffffff);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    coal_timeout_ = 0x2710;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("MirrorCoalToEntryR") + ":\n";
    r += indent_string + "  " + std::string("coal_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(coal_timeout_) ) + "\n";
    all_zeros &= (0 == coal_timeout_);
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
    r += indent_string + std::string("MirrorCoalToEntryR") + ":\n";
    r += indent_string + "  " + std::string("coal_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(coal_timeout_) ) + "\n";
    all_zeros &= (0 == coal_timeout_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t coal_timeout_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mirror_slice_mem, int index_mirror_coal_to_entry_r
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x80000; // to get to mirreg
    offset += 0x10000; // to get to slice_mem
    assert(index_mirror_slice_mem < 4);
    offset += index_mirror_slice_mem * 0x800; // mirror_slice_mem[]
    offset += 0x440; // to get to coal_to_cfg
    assert(index_mirror_coal_to_entry_r < 16);
    offset += index_mirror_coal_to_entry_r * 0x4; // mirror_coal_to_entry_r[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_MIRROR_COAL_TO_ENTRY_R_H__
