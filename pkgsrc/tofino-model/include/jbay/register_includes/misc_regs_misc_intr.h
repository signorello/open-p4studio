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
#ifndef __REGISTER_INCLUDES_MISC_REGS_MISC_INTR_H__
#define __REGISTER_INCLUDES_MISC_REGS_MISC_INTR_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "misc_regs_misc_intr_en0.h"
#include "misc_regs_misc_intr_en1.h"
#include "misc_regs_misc_intr_freeze_enable.h"
#include "misc_regs_misc_intr_inj.h"
#include "misc_regs_misc_intr_stat.h"

namespace jbay {
  namespace register_classes {

class MiscRegsMiscIntr : public model_core::RegisterBlock<RegisterCallback> {
public:
  MiscRegsMiscIntr(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 20, false, write_callback, read_callback, std::string("MiscRegsMiscIntr"))
    {
    }
  MiscRegsMiscIntr(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "MiscRegsMiscIntr")
    {
    }
public:






  MiscRegsMiscIntrStat &misc_intr_stat() { return misc_intr_stat_; }







  MiscRegsMiscIntrEn0 &misc_intr_en0() { return misc_intr_en0_; }







  MiscRegsMiscIntrEn1 &misc_intr_en1() { return misc_intr_en1_; }








  MiscRegsMiscIntrInj &misc_intr_inj() { return misc_intr_inj_; }





  MiscRegsMiscIntrFreezeEnable &misc_intr_freeze_enable() { return misc_intr_freeze_enable_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      misc_intr_stat_.read( offset, data );
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      if (read_callback_) read_callback_();
      misc_intr_en0_.read( offset, data );
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      if (read_callback_) read_callback_();
      misc_intr_en1_.read( offset, data );
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      if (read_callback_) read_callback_();
      misc_intr_inj_.read( offset, data );
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      if (read_callback_) read_callback_();
      misc_intr_freeze_enable_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      offset -= 0x0;
      misc_intr_stat_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      misc_intr_en0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      misc_intr_en1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      misc_intr_inj_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      misc_intr_freeze_enable_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    misc_intr_stat_.reset();
    misc_intr_en0_.reset();
    misc_intr_en1_.reset();
    misc_intr_inj_.reset();
    misc_intr_freeze_enable_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x4) {
      offset -= 0x0;
      r += misc_intr_stat_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      r += misc_intr_en0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      r += misc_intr_en1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      r += misc_intr_inj_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      r += misc_intr_freeze_enable_.to_string(offset,print_zeros,indent_string) ;
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
    r += misc_intr_stat_.to_string(print_zeros,indent_string) ;
    r += misc_intr_en0_.to_string(print_zeros,indent_string) ;
    r += misc_intr_en1_.to_string(print_zeros,indent_string) ;
    r += misc_intr_inj_.to_string(print_zeros,indent_string) ;
    r += misc_intr_freeze_enable_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  MiscRegsMiscIntrStat misc_intr_stat_;
  MiscRegsMiscIntrEn0 misc_intr_en0_;
  MiscRegsMiscIntrEn1 misc_intr_en1_;
  MiscRegsMiscIntrInj misc_intr_inj_;
  MiscRegsMiscIntrFreezeEnable misc_intr_freeze_enable_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x80000; // to get to misc_regs
    offset += 0x200; // to get to misc_intr
    return offset;
  }

};





  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_MISC_REGS_MISC_INTR_H__
