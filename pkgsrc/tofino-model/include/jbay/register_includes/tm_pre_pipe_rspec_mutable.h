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
#ifndef __REGISTER_INCLUDES_TM_PRE_PIPE_RSPEC_MUTABLE_H__
#define __REGISTER_INCLUDES_TM_PRE_PIPE_RSPEC_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "pre_arb_ctrl_mutable.h"
#include "pre_ctr48_cpu_copies_mutable.h"
#include "pre_ctr48_first_mutable.h"
#include "pre_ctr48_packet_drop_mutable.h"
#include "pre_ctr48_ph_lost_mutable.h"
#include "pre_ctr48_ph_processed_mutable.h"
#include "pre_ctr48_total_copies_mutable.h"
#include "pre_ctr48_xid_prunes_mutable.h"
#include "pre_ctr48_yid_prunes_mutable.h"
#include "pre_ctrl_mutable.h"
#include "pre_debug_mutable.h"
#include "pre_fifo_credit_log_mutable.h"
#include "pre_fifo_depth_ctrl_mutable.h"
#include "pre_fifo_ph_count_mutable.h"
#include "pre_filter_ctrl_mutable.h"
#include "pre_filter_mask_mutable.h"
#include "pre_ififo_stats_r_mutable.h"
#include "pre_illegal_l1_node_log_mutable.h"
#include "pre_illegal_l2_node_log_mutable.h"
#include "pre_max_l1_node_ctrl_mutable.h"
#include "pre_max_l1_node_log_mutable.h"
#include "pre_max_l2_node_ctrl_mutable.h"
#include "pre_max_l2_node_log_mutable.h"
#include "pre_mbe_log_mutable.h"
#include "pre_port_vector_mutable.h"
#include "pre_rdm_addr_ctrl_mutable.h"
#include "pre_rdm_ctrl_mutable.h"
#include "pre_rdm_ph_log_mutable.h"
#include "pre_sbe_log_mutable.h"
#include "pre_table_ph_count_mutable.h"
#include "pre_wrr_ctrl_mutable.h"
#include "tm_pre_pipe_rspec_debug_bus_ctrl_mutable.h"
#include "tm_pre_pipe_rspec_ecc_mutable.h"
#include "tm_pre_pipe_rspec_intr_mutable.h"
#include "tm_pre_pipe_rspec_pre_ififo_ctrl0_mutable.h"
#include "tm_pre_pipe_rspec_pre_ififo_ctrl1_mutable.h"
#include "tm_pre_pipe_rspec_pre_ififo_ctrl2_mutable.h"
#include "tm_pre_pipe_rspec_pre_ififo_ctrl3_mutable.h"

namespace jbay {
  namespace register_classes {

class TmPrePipeRspecMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  TmPrePipeRspecMutable(
      int chipNumber, int index_tm_pre_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_pre_pipe_rspec), 32768, true, write_callback, read_callback, std::string("TmPrePipeRspecMutable")+":"+boost::lexical_cast<std::string>(index_tm_pre_pipe_rspec))
    {
    }
  TmPrePipeRspecMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "TmPrePipeRspecMutable")
    {
    }
public:





  PreCtrlMutable &ctrl() { return ctrl_; }





  PreArbCtrlMutable &arb_ctrl() { return arb_ctrl_; }





  PreWrrCtrlMutable &wrr_ctrl() { return wrr_ctrl_; }







  PreFifoDepthCtrlMutable &fifo_depth(int j0) { return fifo_depth_[j0]; }





  PreMaxL1NodeCtrlMutable &max_l1_node_ctrl() { return max_l1_node_ctrl_; }





  PreMaxL2NodeCtrlMutable &max_l2_node_ctrl() { return max_l2_node_ctrl_; }





  PreRdmCtrlMutable &rdm_ctrl() { return rdm_ctrl_; }





  PreFilterCtrlMutable &filter_ctrl() { return filter_ctrl_; }





  PreFilterMaskMutable &filter_mask() { return filter_mask_; }





  PreRdmAddrCtrlMutable &rdm_addr_ctrl() { return rdm_addr_ctrl_; }








  TmPrePipeRspecEccMutable &ecc() { return ecc_; }







  PreFifoPhCountMutable &fifo_ph_count(int j0) { return fifo_ph_count_[j0]; }







  PreTablePhCountMutable &table_ph_count(int j0) { return table_ph_count_[j0]; }





  PreCtr48CpuCopiesMutable &cpu_copies() { return cpu_copies_; }





  PreCtr48PhProcessedMutable &ph_processed() { return ph_processed_; }





  PreCtr48TotalCopiesMutable &total_copies() { return total_copies_; }





  PreCtr48XidPrunesMutable &xid_prunes() { return xid_prunes_; }





  PreCtr48YidPrunesMutable &yid_prunes() { return yid_prunes_; }





  PreCtr48FirstMutable &first_copies() { return first_copies_; }





  PreCtr48PhProcessedMutable &filtered_ph_processed() { return filtered_ph_processed_; }





  PreCtr48TotalCopiesMutable &filtered_total_copies() { return filtered_total_copies_; }





  PreCtr48XidPrunesMutable &filtered_xid_prunes() { return filtered_xid_prunes_; }





  PreCtr48YidPrunesMutable &filtered_yid_prunes() { return filtered_yid_prunes_; }





  PrePortVectorMutable &filtered_port_vector() { return filtered_port_vector_; }







  PreRdmPhLogMutable &rdm_ph_log(int j0) { return rdm_ph_log_[j0]; }





  PreCtr48PhLostMutable &ph_lost() { return ph_lost_; }





  PreCtr48PacketDropMutable &packet_drop() { return packet_drop_; }





  PreMaxL1NodeLogMutable &max_l1_node_log() { return max_l1_node_log_; }





  PreMaxL2NodeLogMutable &max_l2_node_log() { return max_l2_node_log_; }





  PreIllegalL1NodeLogMutable &illegal_l1_node_log() { return illegal_l1_node_log_; }





  PreIllegalL2NodeLogMutable &illegal_l2_node_log() { return illegal_l2_node_log_; }





  PreSbeLogMutable &sbe_log() { return sbe_log_; }





  PreMbeLogMutable &mbe_log() { return mbe_log_; }







  TmPrePipeRspecPreIfifoCtrl0Mutable &pre_ififo_ctrl0() { return pre_ififo_ctrl0_; }







  TmPrePipeRspecPreIfifoCtrl1Mutable &pre_ififo_ctrl1() { return pre_ififo_ctrl1_; }







  TmPrePipeRspecPreIfifoCtrl2Mutable &pre_ififo_ctrl2() { return pre_ififo_ctrl2_; }







  TmPrePipeRspecPreIfifoCtrl3Mutable &pre_ififo_ctrl3() { return pre_ififo_ctrl3_; }









  PreIfifoStatsRMutable &pre_ififo_stats(int j0) { return pre_ififo_stats_[j0]; }





  PreFifoCreditLogMutable &credit_log() { return credit_log_; }





  PreDebugMutable &debug() { return debug_; }





  TmPrePipeRspecDebugBusCtrlMutable &debug_bus_ctrl() { return debug_bus_ctrl_; }
  TmPrePipeRspecIntrMutable &intr() { return intr_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      if (read_callback_) read_callback_();
      ctrl_.read( offset, data );
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      if (read_callback_) read_callback_();
      arb_ctrl_.read( offset, data );
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      if (read_callback_) read_callback_();
      wrr_ctrl_.read( offset, data );
    }
    else if (offset >= 0x10 && offset < 0x20) {
      offset -= 0x10;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      fifo_depth_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      if (read_callback_) read_callback_();
      max_l1_node_ctrl_.read( offset, data );
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      if (read_callback_) read_callback_();
      max_l2_node_ctrl_.read( offset, data );
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      if (read_callback_) read_callback_();
      rdm_ctrl_.read( offset, data );
    }
    else if (offset >= 0x30 && offset < 0x3c) {
      offset -= 0x30;
      if (read_callback_) read_callback_();
      filter_ctrl_.read( offset, data );
    }
    else if (offset >= 0x40 && offset < 0x4c) {
      offset -= 0x40;
      if (read_callback_) read_callback_();
      filter_mask_.read( offset, data );
    }
    else if (offset >= 0x4c && offset < 0x50) {
      offset -= 0x4c;
      if (read_callback_) read_callback_();
      rdm_addr_ctrl_.read( offset, data );
    }
    else if (offset >= 0x50 && offset < 0x58) {
      offset -= 0x50;
      if (read_callback_) read_callback_();
      ecc_.read( offset, data );
    }
    else if (offset >= 0x80 && offset < 0x90) {
      offset -= 0x80;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      fifo_ph_count_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x90 && offset < 0x98) {
      offset -= 0x90;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      table_ph_count_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x98 && offset < 0xa0) {
      offset -= 0x98;
      if (read_callback_) read_callback_();
      cpu_copies_.read( offset, data );
    }
    else if (offset >= 0xa0 && offset < 0xa8) {
      offset -= 0xa0;
      if (read_callback_) read_callback_();
      ph_processed_.read( offset, data );
    }
    else if (offset >= 0xa8 && offset < 0xb0) {
      offset -= 0xa8;
      if (read_callback_) read_callback_();
      total_copies_.read( offset, data );
    }
    else if (offset >= 0xb0 && offset < 0xb8) {
      offset -= 0xb0;
      if (read_callback_) read_callback_();
      xid_prunes_.read( offset, data );
    }
    else if (offset >= 0xb8 && offset < 0xc0) {
      offset -= 0xb8;
      if (read_callback_) read_callback_();
      yid_prunes_.read( offset, data );
    }
    else if (offset >= 0xc0 && offset < 0xc8) {
      offset -= 0xc0;
      if (read_callback_) read_callback_();
      first_copies_.read( offset, data );
    }
    else if (offset >= 0xc8 && offset < 0xd0) {
      offset -= 0xc8;
      if (read_callback_) read_callback_();
      filtered_ph_processed_.read( offset, data );
    }
    else if (offset >= 0xd0 && offset < 0xd8) {
      offset -= 0xd0;
      if (read_callback_) read_callback_();
      filtered_total_copies_.read( offset, data );
    }
    else if (offset >= 0xd8 && offset < 0xe0) {
      offset -= 0xd8;
      if (read_callback_) read_callback_();
      filtered_xid_prunes_.read( offset, data );
    }
    else if (offset >= 0xe0 && offset < 0xe8) {
      offset -= 0xe0;
      if (read_callback_) read_callback_();
      filtered_yid_prunes_.read( offset, data );
    }
    else if (offset >= 0xf0 && offset < 0xfc) {
      offset -= 0xf0;
      if (read_callback_) read_callback_();
      filtered_port_vector_.read( offset, data );
    }
    else if (offset >= 0x100 && offset < 0x128) {
      offset -= 0x100;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      rdm_ph_log_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x128 && offset < 0x130) {
      offset -= 0x128;
      if (read_callback_) read_callback_();
      ph_lost_.read( offset, data );
    }
    else if (offset >= 0x130 && offset < 0x138) {
      offset -= 0x130;
      if (read_callback_) read_callback_();
      packet_drop_.read( offset, data );
    }
    else if (offset >= 0x138 && offset < 0x140) {
      offset -= 0x138;
      if (read_callback_) read_callback_();
      max_l1_node_log_.read( offset, data );
    }
    else if (offset >= 0x140 && offset < 0x148) {
      offset -= 0x140;
      if (read_callback_) read_callback_();
      max_l2_node_log_.read( offset, data );
    }
    else if (offset >= 0x148 && offset < 0x150) {
      offset -= 0x148;
      if (read_callback_) read_callback_();
      illegal_l1_node_log_.read( offset, data );
    }
    else if (offset >= 0x150 && offset < 0x158) {
      offset -= 0x150;
      if (read_callback_) read_callback_();
      illegal_l2_node_log_.read( offset, data );
    }
    else if (offset >= 0x158 && offset < 0x15c) {
      offset -= 0x158;
      if (read_callback_) read_callback_();
      sbe_log_.read( offset, data );
    }
    else if (offset >= 0x15c && offset < 0x160) {
      offset -= 0x15c;
      if (read_callback_) read_callback_();
      mbe_log_.read( offset, data );
    }
    else if (offset >= 0x160 && offset < 0x164) {
      offset -= 0x160;
      if (read_callback_) read_callback_();
      pre_ififo_ctrl0_.read( offset, data );
    }
    else if (offset >= 0x164 && offset < 0x168) {
      offset -= 0x164;
      if (read_callback_) read_callback_();
      pre_ififo_ctrl1_.read( offset, data );
    }
    else if (offset >= 0x168 && offset < 0x16c) {
      offset -= 0x168;
      if (read_callback_) read_callback_();
      pre_ififo_ctrl2_.read( offset, data );
    }
    else if (offset >= 0x16c && offset < 0x170) {
      offset -= 0x16c;
      if (read_callback_) read_callback_();
      pre_ififo_ctrl3_.read( offset, data );
    }
    else if (offset >= 0x170 && offset < 0x180) {
      offset -= 0x170;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      pre_ififo_stats_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x180 && offset < 0x184) {
      offset -= 0x180;
      if (read_callback_) read_callback_();
      credit_log_.read( offset, data );
    }
    else if (offset >= 0x184 && offset < 0x188) {
      offset -= 0x184;
      if (read_callback_) read_callback_();
      debug_.read( offset, data );
    }
    else if (offset >= 0x188 && offset < 0x18c) {
      offset -= 0x188;
      if (read_callback_) read_callback_();
      debug_bus_ctrl_.read( offset, data );
    }
    else if (offset >= 0x60 && offset < 0x74) {
      offset -= 0x60;
      if (read_callback_) read_callback_();
      intr_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      arb_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      wrr_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10 && offset < 0x20) {
      offset -= 0x10;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      fifo_depth_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      max_l1_node_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      max_l2_node_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      rdm_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x30 && offset < 0x3c) {
      offset -= 0x30;
      filter_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x40 && offset < 0x4c) {
      offset -= 0x40;
      filter_mask_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4c && offset < 0x50) {
      offset -= 0x4c;
      rdm_addr_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x50 && offset < 0x58) {
      offset -= 0x50;
      ecc_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x80 && offset < 0x90) {
      offset -= 0x80;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      fifo_ph_count_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x90 && offset < 0x98) {
      offset -= 0x90;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      table_ph_count_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x98 && offset < 0xa0) {
      offset -= 0x98;
      cpu_copies_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa0 && offset < 0xa8) {
      offset -= 0xa0;
      ph_processed_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa8 && offset < 0xb0) {
      offset -= 0xa8;
      total_copies_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xb0 && offset < 0xb8) {
      offset -= 0xb0;
      xid_prunes_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xb8 && offset < 0xc0) {
      offset -= 0xb8;
      yid_prunes_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc0 && offset < 0xc8) {
      offset -= 0xc0;
      first_copies_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc8 && offset < 0xd0) {
      offset -= 0xc8;
      filtered_ph_processed_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xd0 && offset < 0xd8) {
      offset -= 0xd0;
      filtered_total_copies_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xd8 && offset < 0xe0) {
      offset -= 0xd8;
      filtered_xid_prunes_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xe0 && offset < 0xe8) {
      offset -= 0xe0;
      filtered_yid_prunes_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xf0 && offset < 0xfc) {
      offset -= 0xf0;
      filtered_port_vector_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x100 && offset < 0x128) {
      offset -= 0x100;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      rdm_ph_log_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x128 && offset < 0x130) {
      offset -= 0x128;
      ph_lost_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x130 && offset < 0x138) {
      offset -= 0x130;
      packet_drop_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x138 && offset < 0x140) {
      offset -= 0x138;
      max_l1_node_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x140 && offset < 0x148) {
      offset -= 0x140;
      max_l2_node_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x148 && offset < 0x150) {
      offset -= 0x148;
      illegal_l1_node_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x150 && offset < 0x158) {
      offset -= 0x150;
      illegal_l2_node_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x158 && offset < 0x15c) {
      offset -= 0x158;
      sbe_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x15c && offset < 0x160) {
      offset -= 0x15c;
      mbe_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x160 && offset < 0x164) {
      offset -= 0x160;
      pre_ififo_ctrl0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x164 && offset < 0x168) {
      offset -= 0x164;
      pre_ififo_ctrl1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x168 && offset < 0x16c) {
      offset -= 0x168;
      pre_ififo_ctrl2_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x16c && offset < 0x170) {
      offset -= 0x16c;
      pre_ififo_ctrl3_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x170 && offset < 0x180) {
      offset -= 0x170;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      pre_ififo_stats_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x180 && offset < 0x184) {
      offset -= 0x180;
      credit_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x184 && offset < 0x188) {
      offset -= 0x184;
      debug_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x188 && offset < 0x18c) {
      offset -= 0x188;
      debug_bus_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x60 && offset < 0x74) {
      offset -= 0x60;
      intr_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    ctrl_.reset();
    arb_ctrl_.reset();
    wrr_ctrl_.reset();
    for (auto &f0 : fifo_depth_) {
      f0.reset();
    }
    max_l1_node_ctrl_.reset();
    max_l2_node_ctrl_.reset();
    rdm_ctrl_.reset();
    filter_ctrl_.reset();
    filter_mask_.reset();
    rdm_addr_ctrl_.reset();
    ecc_.reset();
    for (auto &f0 : fifo_ph_count_) {
      f0.reset();
    }
    for (auto &f0 : table_ph_count_) {
      f0.reset();
    }
    cpu_copies_.reset();
    ph_processed_.reset();
    total_copies_.reset();
    xid_prunes_.reset();
    yid_prunes_.reset();
    first_copies_.reset();
    filtered_ph_processed_.reset();
    filtered_total_copies_.reset();
    filtered_xid_prunes_.reset();
    filtered_yid_prunes_.reset();
    filtered_port_vector_.reset();
    for (auto &f0 : rdm_ph_log_) {
      f0.reset();
    }
    ph_lost_.reset();
    packet_drop_.reset();
    max_l1_node_log_.reset();
    max_l2_node_log_.reset();
    illegal_l1_node_log_.reset();
    illegal_l2_node_log_.reset();
    sbe_log_.reset();
    mbe_log_.reset();
    pre_ififo_ctrl0_.reset();
    pre_ififo_ctrl1_.reset();
    pre_ififo_ctrl2_.reset();
    pre_ififo_ctrl3_.reset();
    for (auto &f0 : pre_ififo_stats_) {
      f0.reset();
    }
    credit_log_.reset();
    debug_.reset();
    debug_bus_ctrl_.reset();
    intr_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      r += ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      r += arb_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      r += wrr_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10 && offset < 0x20) {
      offset -= 0x10;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += fifo_depth_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      r += max_l1_node_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      r += max_l2_node_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      r += rdm_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x30 && offset < 0x3c) {
      offset -= 0x30;
      r += filter_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x40 && offset < 0x4c) {
      offset -= 0x40;
      r += filter_mask_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4c && offset < 0x50) {
      offset -= 0x4c;
      r += rdm_addr_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x50 && offset < 0x58) {
      offset -= 0x50;
      r += ecc_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x80 && offset < 0x90) {
      offset -= 0x80;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += fifo_ph_count_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x90 && offset < 0x98) {
      offset -= 0x90;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += table_ph_count_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x98 && offset < 0xa0) {
      offset -= 0x98;
      r += cpu_copies_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa0 && offset < 0xa8) {
      offset -= 0xa0;
      r += ph_processed_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa8 && offset < 0xb0) {
      offset -= 0xa8;
      r += total_copies_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xb0 && offset < 0xb8) {
      offset -= 0xb0;
      r += xid_prunes_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xb8 && offset < 0xc0) {
      offset -= 0xb8;
      r += yid_prunes_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc0 && offset < 0xc8) {
      offset -= 0xc0;
      r += first_copies_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc8 && offset < 0xd0) {
      offset -= 0xc8;
      r += filtered_ph_processed_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xd0 && offset < 0xd8) {
      offset -= 0xd0;
      r += filtered_total_copies_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xd8 && offset < 0xe0) {
      offset -= 0xd8;
      r += filtered_xid_prunes_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xe0 && offset < 0xe8) {
      offset -= 0xe0;
      r += filtered_yid_prunes_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xf0 && offset < 0xfc) {
      offset -= 0xf0;
      r += filtered_port_vector_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x100 && offset < 0x128) {
      offset -= 0x100;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += rdm_ph_log_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x128 && offset < 0x130) {
      offset -= 0x128;
      r += ph_lost_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x130 && offset < 0x138) {
      offset -= 0x130;
      r += packet_drop_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x138 && offset < 0x140) {
      offset -= 0x138;
      r += max_l1_node_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x140 && offset < 0x148) {
      offset -= 0x140;
      r += max_l2_node_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x148 && offset < 0x150) {
      offset -= 0x148;
      r += illegal_l1_node_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x150 && offset < 0x158) {
      offset -= 0x150;
      r += illegal_l2_node_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x158 && offset < 0x15c) {
      offset -= 0x158;
      r += sbe_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x15c && offset < 0x160) {
      offset -= 0x15c;
      r += mbe_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x160 && offset < 0x164) {
      offset -= 0x160;
      r += pre_ififo_ctrl0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x164 && offset < 0x168) {
      offset -= 0x164;
      r += pre_ififo_ctrl1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x168 && offset < 0x16c) {
      offset -= 0x168;
      r += pre_ififo_ctrl2_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x16c && offset < 0x170) {
      offset -= 0x16c;
      r += pre_ififo_ctrl3_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x170 && offset < 0x180) {
      offset -= 0x170;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += pre_ififo_stats_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x180 && offset < 0x184) {
      offset -= 0x180;
      r += credit_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x184 && offset < 0x188) {
      offset -= 0x184;
      r += debug_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x188 && offset < 0x18c) {
      offset -= 0x188;
      r += debug_bus_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x60 && offset < 0x74) {
      offset -= 0x60;
      r += intr_.to_string(offset,print_zeros,indent_string) ;
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
    r += ctrl_.to_string(print_zeros,indent_string) ;
    r += arb_ctrl_.to_string(print_zeros,indent_string) ;
    r += wrr_ctrl_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<4;++a0) {
      r += fifo_depth_[a0].to_string(print_zeros,indent_string) ;
    }
    r += max_l1_node_ctrl_.to_string(print_zeros,indent_string) ;
    r += max_l2_node_ctrl_.to_string(print_zeros,indent_string) ;
    r += rdm_ctrl_.to_string(print_zeros,indent_string) ;
    r += filter_ctrl_.to_string(print_zeros,indent_string) ;
    r += filter_mask_.to_string(print_zeros,indent_string) ;
    r += rdm_addr_ctrl_.to_string(print_zeros,indent_string) ;
    r += ecc_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<4;++a0) {
      r += fifo_ph_count_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<2;++a0) {
      r += table_ph_count_[a0].to_string(print_zeros,indent_string) ;
    }
    r += cpu_copies_.to_string(print_zeros,indent_string) ;
    r += ph_processed_.to_string(print_zeros,indent_string) ;
    r += total_copies_.to_string(print_zeros,indent_string) ;
    r += xid_prunes_.to_string(print_zeros,indent_string) ;
    r += yid_prunes_.to_string(print_zeros,indent_string) ;
    r += first_copies_.to_string(print_zeros,indent_string) ;
    r += filtered_ph_processed_.to_string(print_zeros,indent_string) ;
    r += filtered_total_copies_.to_string(print_zeros,indent_string) ;
    r += filtered_xid_prunes_.to_string(print_zeros,indent_string) ;
    r += filtered_yid_prunes_.to_string(print_zeros,indent_string) ;
    r += filtered_port_vector_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<10;++a0) {
      r += rdm_ph_log_[a0].to_string(print_zeros,indent_string) ;
    }
    r += ph_lost_.to_string(print_zeros,indent_string) ;
    r += packet_drop_.to_string(print_zeros,indent_string) ;
    r += max_l1_node_log_.to_string(print_zeros,indent_string) ;
    r += max_l2_node_log_.to_string(print_zeros,indent_string) ;
    r += illegal_l1_node_log_.to_string(print_zeros,indent_string) ;
    r += illegal_l2_node_log_.to_string(print_zeros,indent_string) ;
    r += sbe_log_.to_string(print_zeros,indent_string) ;
    r += mbe_log_.to_string(print_zeros,indent_string) ;
    r += pre_ififo_ctrl0_.to_string(print_zeros,indent_string) ;
    r += pre_ififo_ctrl1_.to_string(print_zeros,indent_string) ;
    r += pre_ififo_ctrl2_.to_string(print_zeros,indent_string) ;
    r += pre_ififo_ctrl3_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<4;++a0) {
      r += pre_ififo_stats_[a0].to_string(print_zeros,indent_string) ;
    }
    r += credit_log_.to_string(print_zeros,indent_string) ;
    r += debug_.to_string(print_zeros,indent_string) ;
    r += debug_bus_ctrl_.to_string(print_zeros,indent_string) ;
    r += intr_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  PreCtrlMutable ctrl_;
  PreArbCtrlMutable arb_ctrl_;
  PreWrrCtrlMutable wrr_ctrl_;
  std::array< PreFifoDepthCtrlMutable, 4 > fifo_depth_;
  PreMaxL1NodeCtrlMutable max_l1_node_ctrl_;
  PreMaxL2NodeCtrlMutable max_l2_node_ctrl_;
  PreRdmCtrlMutable rdm_ctrl_;
  PreFilterCtrlMutable filter_ctrl_;
  PreFilterMaskMutable filter_mask_;
  PreRdmAddrCtrlMutable rdm_addr_ctrl_;
  TmPrePipeRspecEccMutable ecc_;
  std::array< PreFifoPhCountMutable, 4 > fifo_ph_count_;
  std::array< PreTablePhCountMutable, 2 > table_ph_count_;
  PreCtr48CpuCopiesMutable cpu_copies_;
  PreCtr48PhProcessedMutable ph_processed_;
  PreCtr48TotalCopiesMutable total_copies_;
  PreCtr48XidPrunesMutable xid_prunes_;
  PreCtr48YidPrunesMutable yid_prunes_;
  PreCtr48FirstMutable first_copies_;
  PreCtr48PhProcessedMutable filtered_ph_processed_;
  PreCtr48TotalCopiesMutable filtered_total_copies_;
  PreCtr48XidPrunesMutable filtered_xid_prunes_;
  PreCtr48YidPrunesMutable filtered_yid_prunes_;
  PrePortVectorMutable filtered_port_vector_;
  std::array< PreRdmPhLogMutable, 10 > rdm_ph_log_;
  PreCtr48PhLostMutable ph_lost_;
  PreCtr48PacketDropMutable packet_drop_;
  PreMaxL1NodeLogMutable max_l1_node_log_;
  PreMaxL2NodeLogMutable max_l2_node_log_;
  PreIllegalL1NodeLogMutable illegal_l1_node_log_;
  PreIllegalL2NodeLogMutable illegal_l2_node_log_;
  PreSbeLogMutable sbe_log_;
  PreMbeLogMutable mbe_log_;
  TmPrePipeRspecPreIfifoCtrl0Mutable pre_ififo_ctrl0_;
  TmPrePipeRspecPreIfifoCtrl1Mutable pre_ififo_ctrl1_;
  TmPrePipeRspecPreIfifoCtrl2Mutable pre_ififo_ctrl2_;
  TmPrePipeRspecPreIfifoCtrl3Mutable pre_ififo_ctrl3_;
  std::array< PreIfifoStatsRMutable, 4 > pre_ififo_stats_;
  PreFifoCreditLogMutable credit_log_;
  PreDebugMutable debug_;
  TmPrePipeRspecDebugBusCtrlMutable debug_bus_ctrl_;
  TmPrePipeRspecIntrMutable intr_;
private:
  static int StartOffset(
      int index_tm_pre_pipe_rspec
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x480000; // to get to tm_pre_top
    assert(index_tm_pre_pipe_rspec < 4);
    offset += index_tm_pre_pipe_rspec * 0x8000; // tm_pre_pipe_rspec[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_TM_PRE_PIPE_RSPEC_MUTABLE_H__
