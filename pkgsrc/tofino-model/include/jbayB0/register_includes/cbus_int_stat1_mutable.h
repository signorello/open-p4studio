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
#ifndef __REGISTER_INCLUDES_CBUS_INT_STAT1_MUTABLE_H__
#define __REGISTER_INCLUDES_CBUS_INT_STAT1_MUTABLE_H__


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

class CbusIntStat1Mutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  CbusIntStat1Mutable(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, true, write_callback, read_callback, std::string("CbusIntStat1Mutable"))
    {
    }
  CbusIntStat1Mutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "CbusIntStat1Mutable")
    {
    }
public:





  uint8_t wl_iqueue0_mbe() { return wl_iqueue0_mbe_; }
  void wl_iqueue0_mbe(const uint8_t &v) { wl_iqueue0_mbe_=v; }





  uint8_t wl_iqueue1_mbe() { return wl_iqueue1_mbe_; }
  void wl_iqueue1_mbe(const uint8_t &v) { wl_iqueue1_mbe_=v; }





  uint8_t rb_oqueue0_mbe() { return rb_oqueue0_mbe_; }
  void rb_oqueue0_mbe(const uint8_t &v) { rb_oqueue0_mbe_=v; }





  uint8_t rb_oqueue1_mbe() { return rb_oqueue1_mbe_; }
  void rb_oqueue1_mbe(const uint8_t &v) { rb_oqueue1_mbe_=v; }





  uint8_t lq_oqueue_mbe() { return lq_oqueue_mbe_; }
  void lq_oqueue_mbe(const uint8_t &v) { lq_oqueue_mbe_=v; }





  uint8_t wl_iqueue0_sbe() { return wl_iqueue0_sbe_; }
  void wl_iqueue0_sbe(const uint8_t &v) { wl_iqueue0_sbe_=v; }





  uint8_t wl_iqueue1_sbe() { return wl_iqueue1_sbe_; }
  void wl_iqueue1_sbe(const uint8_t &v) { wl_iqueue1_sbe_=v; }





  uint8_t rb_oqueue0_sbe() { return rb_oqueue0_sbe_; }
  void rb_oqueue0_sbe(const uint8_t &v) { rb_oqueue0_sbe_=v; }





  uint8_t rb_oqueue1_sbe() { return rb_oqueue1_sbe_; }
  void rb_oqueue1_sbe(const uint8_t &v) { rb_oqueue1_sbe_=v; }





  uint8_t lq_oqueue_sbe() { return lq_oqueue_sbe_; }
  void lq_oqueue_sbe(const uint8_t &v) { lq_oqueue_sbe_=v; }







  uint8_t cbus_parity_err(int j0) { return cbus_parity_err_[j0]; }
  void cbus_parity_err(int j0,const uint8_t &v) { cbus_parity_err_[j0]=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (wl_iqueue0_mbe_ & 0x1);
    *data |= ((wl_iqueue1_mbe_ & 0x1) << 1);
    *data |= ((rb_oqueue0_mbe_ & 0x1) << 2);
    *data |= ((rb_oqueue1_mbe_ & 0x1) << 3);
    *data |= ((lq_oqueue_mbe_ & 0x1) << 4);
    *data |= ((wl_iqueue0_sbe_ & 0x1) << 5);
    *data |= ((wl_iqueue1_sbe_ & 0x1) << 6);
    *data |= ((rb_oqueue0_sbe_ & 0x1) << 7);
    *data |= ((rb_oqueue1_sbe_ & 0x1) << 8);
    *data |= ((lq_oqueue_sbe_ & 0x1) << 9);
    *data |= ((cbus_parity_err_[0] & 0x1) << 10);
    *data |= ((cbus_parity_err_[1] & 0x1) << 11);
    *data |= ((cbus_parity_err_[2] & 0x1) << 12);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    wl_iqueue0_mbe_ &= ~(data & 0x1);
    wl_iqueue1_mbe_ &= ~((data >> 1) & 0x1);
    rb_oqueue0_mbe_ &= ~((data >> 2) & 0x1);
    rb_oqueue1_mbe_ &= ~((data >> 3) & 0x1);
    lq_oqueue_mbe_ &= ~((data >> 4) & 0x1);
    wl_iqueue0_sbe_ &= ~((data >> 5) & 0x1);
    wl_iqueue1_sbe_ &= ~((data >> 6) & 0x1);
    rb_oqueue0_sbe_ &= ~((data >> 7) & 0x1);
    rb_oqueue1_sbe_ &= ~((data >> 8) & 0x1);
    lq_oqueue_sbe_ &= ~((data >> 9) & 0x1);
    cbus_parity_err_[0] &= ~((data >> 10) & 0x1);
    cbus_parity_err_[1] &= ~((data >> 11) & 0x1);
    cbus_parity_err_[2] &= ~((data >> 12) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    wl_iqueue0_mbe_ = 0x0;
    wl_iqueue1_mbe_ = 0x0;
    rb_oqueue0_mbe_ = 0x0;
    rb_oqueue1_mbe_ = 0x0;
    lq_oqueue_mbe_ = 0x0;
    wl_iqueue0_sbe_ = 0x0;
    wl_iqueue1_sbe_ = 0x0;
    rb_oqueue0_sbe_ = 0x0;
    rb_oqueue1_sbe_ = 0x0;
    lq_oqueue_sbe_ = 0x0;
    cbus_parity_err_[0] = 0x0;
    cbus_parity_err_[1] = 0x0;
    cbus_parity_err_[2] = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("CbusIntStat1Mutable") + ":\n";
    r += indent_string + "  " + std::string("wl_iqueue0_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_iqueue0_mbe_) ) + "\n";
    all_zeros &= (0 == wl_iqueue0_mbe_);
    r += indent_string + "  " + std::string("wl_iqueue1_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_iqueue1_mbe_) ) + "\n";
    all_zeros &= (0 == wl_iqueue1_mbe_);
    r += indent_string + "  " + std::string("rb_oqueue0_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_oqueue0_mbe_) ) + "\n";
    all_zeros &= (0 == rb_oqueue0_mbe_);
    r += indent_string + "  " + std::string("rb_oqueue1_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_oqueue1_mbe_) ) + "\n";
    all_zeros &= (0 == rb_oqueue1_mbe_);
    r += indent_string + "  " + std::string("lq_oqueue_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lq_oqueue_mbe_) ) + "\n";
    all_zeros &= (0 == lq_oqueue_mbe_);
    r += indent_string + "  " + std::string("wl_iqueue0_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_iqueue0_sbe_) ) + "\n";
    all_zeros &= (0 == wl_iqueue0_sbe_);
    r += indent_string + "  " + std::string("wl_iqueue1_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_iqueue1_sbe_) ) + "\n";
    all_zeros &= (0 == wl_iqueue1_sbe_);
    r += indent_string + "  " + std::string("rb_oqueue0_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_oqueue0_sbe_) ) + "\n";
    all_zeros &= (0 == rb_oqueue0_sbe_);
    r += indent_string + "  " + std::string("rb_oqueue1_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_oqueue1_sbe_) ) + "\n";
    all_zeros &= (0 == rb_oqueue1_sbe_);
    r += indent_string + "  " + std::string("lq_oqueue_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lq_oqueue_sbe_) ) + "\n";
    all_zeros &= (0 == lq_oqueue_sbe_);
    for (uint32_t f=0;f<3;++f) {
      r += indent_string + "  " + std::string("cbus_parity_err") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cbus_parity_err_[f]) ) + "\n";
      all_zeros &= (0 == cbus_parity_err_[f]);
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
    r += indent_string + std::string("CbusIntStat1Mutable") + ":\n";
    r += indent_string + "  " + std::string("wl_iqueue0_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_iqueue0_mbe_) ) + "\n";
    all_zeros &= (0 == wl_iqueue0_mbe_);
    r += indent_string + "  " + std::string("wl_iqueue1_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_iqueue1_mbe_) ) + "\n";
    all_zeros &= (0 == wl_iqueue1_mbe_);
    r += indent_string + "  " + std::string("rb_oqueue0_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_oqueue0_mbe_) ) + "\n";
    all_zeros &= (0 == rb_oqueue0_mbe_);
    r += indent_string + "  " + std::string("rb_oqueue1_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_oqueue1_mbe_) ) + "\n";
    all_zeros &= (0 == rb_oqueue1_mbe_);
    r += indent_string + "  " + std::string("lq_oqueue_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lq_oqueue_mbe_) ) + "\n";
    all_zeros &= (0 == lq_oqueue_mbe_);
    r += indent_string + "  " + std::string("wl_iqueue0_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_iqueue0_sbe_) ) + "\n";
    all_zeros &= (0 == wl_iqueue0_sbe_);
    r += indent_string + "  " + std::string("wl_iqueue1_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_iqueue1_sbe_) ) + "\n";
    all_zeros &= (0 == wl_iqueue1_sbe_);
    r += indent_string + "  " + std::string("rb_oqueue0_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_oqueue0_sbe_) ) + "\n";
    all_zeros &= (0 == rb_oqueue0_sbe_);
    r += indent_string + "  " + std::string("rb_oqueue1_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_oqueue1_sbe_) ) + "\n";
    all_zeros &= (0 == rb_oqueue1_sbe_);
    r += indent_string + "  " + std::string("lq_oqueue_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lq_oqueue_sbe_) ) + "\n";
    all_zeros &= (0 == lq_oqueue_sbe_);
    for (uint32_t f=0;f<3;++f) {
      r += indent_string + "  " + std::string("cbus_parity_err") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cbus_parity_err_[f]) ) + "\n";
      all_zeros &= (0 == cbus_parity_err_[f]);
    }
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t wl_iqueue0_mbe_;
  uint8_t wl_iqueue1_mbe_;
  uint8_t rb_oqueue0_mbe_;
  uint8_t rb_oqueue1_mbe_;
  uint8_t lq_oqueue_mbe_;
  uint8_t wl_iqueue0_sbe_;
  uint8_t wl_iqueue1_sbe_;
  uint8_t rb_oqueue0_sbe_;
  uint8_t rb_oqueue1_sbe_;
  uint8_t lq_oqueue_sbe_;
  std::array< uint8_t, 3 > cbus_parity_err_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x280000; // to get to cbc
    offset += 0x28; // to get to intr_stat1
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_CBUS_INT_STAT1_MUTABLE_H__
