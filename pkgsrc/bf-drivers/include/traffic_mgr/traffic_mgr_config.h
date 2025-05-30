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


/**
 *
 * @file
 * @brief traffic_mgr Configuration Header
 *
 * @addtogroup traffic_mgr-config
 * @{
 *
 */
#ifndef __TRAFFIC_MGR_CONFIG_H__
#define __TRAFFIC_MGR_CONFIG_H__

#ifdef GLOBAL_INCLUDE_CUSTOM_CONFIG
#include <global_custom_config.h>
#endif
#ifdef TRAFFIC_MGR_INCLUDE_CUSTOM_CONFIG
#include <traffic_mgr_custom_config.h>
#endif

/**
 * TRAFFIC_MGR_CONFIG_PORTING_STDLIB
 *
 * Default all porting macros to use the C standard libraries. */

#ifndef TRAFFIC_MGR_CONFIG_PORTING_STDLIB
#define TRAFFIC_MGR_CONFIG_PORTING_STDLIB 1
#endif

/**
 * TRAFFIC_MGR_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
 *
 * Include standard library headers for stdlib porting macros. */

#ifndef TRAFFIC_MGR_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
#define TRAFFIC_MGR_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS \
  TRAFFIC_MGR_CONFIG_PORTING_STDLIB
#endif

/**
 * TRAFFIC_MGR_CONFIG_INCLUDE_UCLI
 *
 * Include generic uCli support. */

#ifndef TRAFFIC_MGR_CONFIG_INCLUDE_UCLI
#define TRAFFIC_MGR_CONFIG_INCLUDE_UCLI 0
#endif

#include "traffic_mgr_porting.h"

#endif /* __TRAFFIC_MGR_CONFIG_H__ */
/* @} */
