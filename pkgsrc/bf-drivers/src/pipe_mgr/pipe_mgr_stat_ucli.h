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


/*!
 * @file pipe_mgr_stat_ucli.h
 * @date
 *
 * Stat table ucli definitions
 */

#ifndef _PIPE_MGR_STAT_UCLI_H
#define _PIPE_MGR_STAT_UCLI_H

#include <target-utils/uCli/ucli.h>
#include <target-utils/uCli/ucli_argparse.h>
#include <target-utils/uCli/ucli_handler_macros.h>

ucli_node_t *pipe_mgr_stat_tbl_ucli_node_create(ucli_node_t *n);

#endif  // _PIPE_MGR_STAT_UCLI_H
