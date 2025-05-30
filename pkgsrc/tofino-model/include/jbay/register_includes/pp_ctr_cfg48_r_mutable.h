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
#ifndef __REGISTER_INCLUDES_PP_CTR_CFG48_R_MUTABLE_H__
#define __REGISTER_INCLUDES_PP_CTR_CFG48_R_MUTABLE_H__


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

class PpCtrCfg48RMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum DprsrHoEEnum {
    kHer,
    kOutEgr
  };
  enum DprsrHoIEnum {
    kHir,
    kOutIngr
  };
  enum DprsrIppRegsEnum {
    kMainE,
    kMainI
  };
public:
  PpCtrCfg48RMutable(
      int chipNumber, int index_pipe_addrmap, int index_pp_ctr_cfg48_r, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_pp_ctr_cfg48_r), 8, true, write_callback, read_callback, std::string("PpCtrCfg48RMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_pp_ctr_cfg48_r))
    {
    }
  PpCtrCfg48RMutable(
      int chipNumber, int index_pipe_addrmap, int index_dprsr_ho_e, DprsrHoEEnum selector_dprsr_ho_e, int index_pp_ctr_cfg48_r, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_dprsr_ho_e, selector_dprsr_ho_e, index_pp_ctr_cfg48_r), 8, true, write_callback, read_callback, std::string("PpCtrCfg48RMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_dprsr_ho_e) + "," + boost::lexical_cast<std::string>(selector_dprsr_ho_e) + "," + boost::lexical_cast<std::string>(index_pp_ctr_cfg48_r))
    {
    }
  PpCtrCfg48RMutable(
      int chipNumber, int index_pipe_addrmap, int index_dprsr_ho_i, DprsrHoIEnum selector_dprsr_ho_i, int index_pp_ctr_cfg48_r, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_dprsr_ho_i, selector_dprsr_ho_i, index_pp_ctr_cfg48_r), 8, true, write_callback, read_callback, std::string("PpCtrCfg48RMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_dprsr_ho_i) + "," + boost::lexical_cast<std::string>(selector_dprsr_ho_i) + "," + boost::lexical_cast<std::string>(index_pp_ctr_cfg48_r))
    {
    }
  PpCtrCfg48RMutable(
      int chipNumber, int index_pipe_addrmap, DprsrIppRegsEnum selector_dprsr_ipp_regs, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, selector_dprsr_ipp_regs), 8, true, write_callback, read_callback, std::string("PpCtrCfg48RMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(selector_dprsr_ipp_regs))
    {
    }
  PpCtrCfg48RMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "PpCtrCfg48RMutable")
    {
    }
public:





  uint64_t ctr48() { return ctr48_; }
  void ctr48(const uint64_t &v) { ctr48_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      if (read_callback_) read_callback_();
      *data = (ctr48_ & 0xffffffff);
    }
    else if (offset >= 0x4 && offset < 0x8) {
      if (read_callback_) read_callback_();
      *data = ((ctr48_ & UINT64_C(0xffff00000000)) >> 32);
    }
    else {
      assert(0);
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      ctr48_ = ((static_cast<uint64_t>(data) & 0xffffffff) | (ctr48_ & UINT64_C(0xffff00000000)));
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      ctr48_ = (((static_cast<uint64_t>(data) << 32) & UINT64_C(0xffff00000000)) | (ctr48_ & 0xffffffff));
      if (write_callback_) write_callback_();
    }
    else {
      assert(0);
    }
    return true;
  }

  void reset(
      
      ) {
    ctr48_ = UINT64_C(0x0);
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PpCtrCfg48RMutable") + ":\n";
    r += indent_string + "  " + std::string("ctr48") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ctr48_) ) + "\n";
    all_zeros &= (0 == ctr48_);
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
    r += indent_string + std::string("PpCtrCfg48RMutable") + ":\n";
    r += indent_string + "  " + std::string("ctr48") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ctr48_) ) + "\n";
    all_zeros &= (0 == ctr48_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint64_t ctr48_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_pp_ctr_cfg48_r
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x100000; // to get to dprsrreg
    offset += 0x28000; // to get to icr
    offset += 0x2cc0; // to get to cfg48
    assert(index_pp_ctr_cfg48_r < 4);
    offset += index_pp_ctr_cfg48_r * 0x8; // pp_ctr_cfg48_r[]
    return offset;
  }

  static int StartOffset(
      int index_pipe_addrmap, int index_dprsr_ho_e, DprsrHoEEnum selector_dprsr_ho_e, int index_pp_ctr_cfg48_r
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x100000; // to get to dprsrreg
    offset += 0x38000; // to get to ho_e
    assert(index_dprsr_ho_e < 4);
    offset += index_dprsr_ho_e * 0x2000; // dprsr_ho_e[]
    switch (selector_dprsr_ho_e) {
      case kHer:
        offset += 0xc00; // to get to her
        offset += 0xe0; // to get to h_cfg48
        assert(index_pp_ctr_cfg48_r < 2);
        offset += index_pp_ctr_cfg48_r * 0x8; // pp_ctr_cfg48_r[]
        break;
      case kOutEgr:
        offset += 0x1000; // to get to out_egr
        offset += 0x480; // to get to cfg48
        assert(index_pp_ctr_cfg48_r < 4);
        offset += index_pp_ctr_cfg48_r * 0x8; // pp_ctr_cfg48_r[]
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

  static int StartOffset(
      int index_pipe_addrmap, int index_dprsr_ho_i, DprsrHoIEnum selector_dprsr_ho_i, int index_pp_ctr_cfg48_r
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x100000; // to get to dprsrreg
    offset += 0x30000; // to get to ho_i
    assert(index_dprsr_ho_i < 4);
    offset += index_dprsr_ho_i * 0x2000; // dprsr_ho_i[]
    switch (selector_dprsr_ho_i) {
      case kHir:
        offset += 0xc00; // to get to hir
        offset += 0xe0; // to get to h_cfg48
        assert(index_pp_ctr_cfg48_r < 2);
        offset += index_pp_ctr_cfg48_r * 0x8; // pp_ctr_cfg48_r[]
        break;
      case kOutIngr:
        offset += 0x1000; // to get to out_ingr
        offset += 0x360; // to get to cfg48
        assert(index_pp_ctr_cfg48_r < 4);
        offset += index_pp_ctr_cfg48_r * 0x8; // pp_ctr_cfg48_r[]
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

  static int StartOffset(
      int index_pipe_addrmap, DprsrIppRegsEnum selector_dprsr_ipp_regs
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x100000; // to get to dprsrreg
    offset += 0x20000; // to get to ipp
    switch (selector_dprsr_ipp_regs) {
      case kMainE:
        offset += 0x60; // to get to main_e_pp_ctr_cfg48
        break;
      case kMainI:
        offset += 0x20; // to get to main_i_pp_ctr_cfg48
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_PP_CTR_CFG48_R_MUTABLE_H__
