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
#ifndef __REGISTER_INCLUDES_QPEX_PIPE_CTRL_MUTABLE_H__
#define __REGISTER_INCLUDES_QPEX_PIPE_CTRL_MUTABLE_H__


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

class QpexPipeCtrlMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  QpexPipeCtrlMutable(
      int chipNumber, int index_tm_pex_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_pex_pipe_rspec), 4, true, write_callback, read_callback, std::string("QpexPipeCtrlMutable")+":"+boost::lexical_cast<std::string>(index_tm_pex_pipe_rspec))
    {
    }
  QpexPipeCtrlMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "QpexPipeCtrlMutable")
    {
    }
public:








  uint8_t tx_cnt_en() { return tx_cnt_en_; }
  void tx_cnt_en(const uint8_t &v) { tx_cnt_en_=v; }





  uint8_t tx_cnt_mode() { return tx_cnt_mode_; }
  void tx_cnt_mode(const uint8_t &v) { tx_cnt_mode_=v; }





  uint8_t pack_sop_dis() { return pack_sop_dis_; }
  void pack_sop_dis(const uint8_t &v) { pack_sop_dis_=v; }






  uint8_t ct_sop_wait() { return ct_sop_wait_; }
  void ct_sop_wait(const uint8_t &v) { ct_sop_wait_=v; }





  uint8_t freeze_on_error() { return freeze_on_error_; }
  void freeze_on_error(const uint8_t &v) { freeze_on_error_=v; }





  uint8_t ecc_dis() { return ecc_dis_; }
  void ecc_dis(const uint8_t &v) { ecc_dis_=v; }





  uint8_t afull_thrd0() { return afull_thrd0_; }
  void afull_thrd0(const uint8_t &v) { afull_thrd0_=v; }





  uint8_t afull_thrd1() { return afull_thrd1_; }
  void afull_thrd1(const uint8_t &v) { afull_thrd1_=v; }






  uint8_t pt_stage_prefetch_dis() { return pt_stage_prefetch_dis_; }
  void pt_stage_prefetch_dis(const uint8_t &v) { pt_stage_prefetch_dis_=v; }






  uint8_t ipg_bytes() { return ipg_bytes_; }
  void ipg_bytes(const uint8_t &v) { ipg_bytes_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (tx_cnt_en_ & 0x1);
    *data |= ((tx_cnt_mode_ & 0x3) << 1);
    *data |= ((pack_sop_dis_ & 0x1) << 3);
    *data |= ((ct_sop_wait_ & 0x1f) << 4);
    *data |= ((freeze_on_error_ & 0x1) << 9);
    *data |= ((ecc_dis_ & 0x1) << 10);
    *data |= ((afull_thrd0_ & 0x7f) << 11);
    *data |= ((afull_thrd1_ & 0x7f) << 18);
    *data |= ((pt_stage_prefetch_dis_ & 0x1) << 25);
    *data |= ((ipg_bytes_ & 0x1f) << 26);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    tx_cnt_en_ = (data & 0x1);
    tx_cnt_mode_ = ((data >> 1) & 0x3);
    pack_sop_dis_ = ((data >> 3) & 0x1);
    ct_sop_wait_ = ((data >> 4) & 0x1f);
    freeze_on_error_ = ((data >> 9) & 0x1);
    ecc_dis_ = ((data >> 10) & 0x1);
    afull_thrd0_ = ((data >> 11) & 0x7f);
    afull_thrd1_ = ((data >> 18) & 0x7f);
    pt_stage_prefetch_dis_ = ((data >> 25) & 0x1);
    ipg_bytes_ = ((data >> 26) & 0x1f);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    tx_cnt_en_ = 0x1;
    tx_cnt_mode_ = 0x2;
    pack_sop_dis_ = 0x0;
    ct_sop_wait_ = 0xa;
    freeze_on_error_ = 0x0;
    ecc_dis_ = 0x0;
    afull_thrd0_ = 0x70;
    afull_thrd1_ = 0x70;
    pt_stage_prefetch_dis_ = 0x1;
    ipg_bytes_ = 0x14;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("QpexPipeCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("tx_cnt_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tx_cnt_en_) ) + "\n";
    all_zeros &= (0 == tx_cnt_en_);
    r += indent_string + "  " + std::string("tx_cnt_mode") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tx_cnt_mode_) ) + "\n";
    all_zeros &= (0 == tx_cnt_mode_);
    r += indent_string + "  " + std::string("pack_sop_dis") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pack_sop_dis_) ) + "\n";
    all_zeros &= (0 == pack_sop_dis_);
    r += indent_string + "  " + std::string("ct_sop_wait") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_sop_wait_) ) + "\n";
    all_zeros &= (0 == ct_sop_wait_);
    r += indent_string + "  " + std::string("freeze_on_error") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(freeze_on_error_) ) + "\n";
    all_zeros &= (0 == freeze_on_error_);
    r += indent_string + "  " + std::string("ecc_dis") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ecc_dis_) ) + "\n";
    all_zeros &= (0 == ecc_dis_);
    r += indent_string + "  " + std::string("afull_thrd0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(afull_thrd0_) ) + "\n";
    all_zeros &= (0 == afull_thrd0_);
    r += indent_string + "  " + std::string("afull_thrd1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(afull_thrd1_) ) + "\n";
    all_zeros &= (0 == afull_thrd1_);
    r += indent_string + "  " + std::string("pt_stage_prefetch_dis") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pt_stage_prefetch_dis_) ) + "\n";
    all_zeros &= (0 == pt_stage_prefetch_dis_);
    r += indent_string + "  " + std::string("ipg_bytes") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ipg_bytes_) ) + "\n";
    all_zeros &= (0 == ipg_bytes_);
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
    r += indent_string + std::string("QpexPipeCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("tx_cnt_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tx_cnt_en_) ) + "\n";
    all_zeros &= (0 == tx_cnt_en_);
    r += indent_string + "  " + std::string("tx_cnt_mode") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tx_cnt_mode_) ) + "\n";
    all_zeros &= (0 == tx_cnt_mode_);
    r += indent_string + "  " + std::string("pack_sop_dis") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pack_sop_dis_) ) + "\n";
    all_zeros &= (0 == pack_sop_dis_);
    r += indent_string + "  " + std::string("ct_sop_wait") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_sop_wait_) ) + "\n";
    all_zeros &= (0 == ct_sop_wait_);
    r += indent_string + "  " + std::string("freeze_on_error") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(freeze_on_error_) ) + "\n";
    all_zeros &= (0 == freeze_on_error_);
    r += indent_string + "  " + std::string("ecc_dis") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ecc_dis_) ) + "\n";
    all_zeros &= (0 == ecc_dis_);
    r += indent_string + "  " + std::string("afull_thrd0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(afull_thrd0_) ) + "\n";
    all_zeros &= (0 == afull_thrd0_);
    r += indent_string + "  " + std::string("afull_thrd1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(afull_thrd1_) ) + "\n";
    all_zeros &= (0 == afull_thrd1_);
    r += indent_string + "  " + std::string("pt_stage_prefetch_dis") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pt_stage_prefetch_dis_) ) + "\n";
    all_zeros &= (0 == pt_stage_prefetch_dis_);
    r += indent_string + "  " + std::string("ipg_bytes") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ipg_bytes_) ) + "\n";
    all_zeros &= (0 == ipg_bytes_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t tx_cnt_en_;
  uint8_t tx_cnt_mode_;
  uint8_t pack_sop_dis_;
  uint8_t ct_sop_wait_;
  uint8_t freeze_on_error_;
  uint8_t ecc_dis_;
  uint8_t afull_thrd0_;
  uint8_t afull_thrd1_;
  uint8_t pt_stage_prefetch_dis_;
  uint8_t ipg_bytes_;
private:
  static int StartOffset(
      int index_tm_pex_pipe_rspec
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x300000; // to get to tm_pex_top
    assert(index_tm_pex_pipe_rspec < 4);
    offset += index_tm_pex_pipe_rspec * 0x4000; // tm_pex_pipe_rspec[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_QPEX_PIPE_CTRL_MUTABLE_H__
