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


#ifndef _PI_LOG_H__
#define _PI_LOG_H__

#include <target-sys/bf_sal/bf_sys_intf.h>

#ifdef LOG_CRIT
// Undefine these macros if they were previously defined as we want the errors
// to have the correct module.
#undef LOG_CRIT
#undef LOG_ERROR
#undef LOG_WARN
#undef LOG_TRACE
#undef LOG_DBG
#endif

#define LOG_CRIT(...) bf_sys_log_and_trace(BF_MOD_PI, BF_LOG_CRIT, __VA_ARGS__)
#define LOG_ERROR(...) bf_sys_log_and_trace(BF_MOD_PI, BF_LOG_ERR, __VA_ARGS__)
#define LOG_WARN(...) bf_sys_log_and_trace(BF_MOD_PI, BF_LOG_WARN, __VA_ARGS__)
#define LOG_TRACE(...) bf_sys_log_and_trace(BF_MOD_PI, BF_LOG_INFO, __VA_ARGS__)
#define LOG_DBG(...) bf_sys_log_and_trace(BF_MOD_PI, BF_LOG_DBG, __VA_ARGS__)

#endif  // _PI_LOG_H__
