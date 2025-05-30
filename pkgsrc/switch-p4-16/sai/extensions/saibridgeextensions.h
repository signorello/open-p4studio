/**
 * Copyright (c) 2022 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
 *
 * @file    saibridgeextensions.h
 *
 * @brief   This module defines nexthop extensions of the Switch Abstraction Interface (SAI)
 */

#ifndef __SAIBRIDGEEXTENSIONS_H_
#define __SAIBRIDGEEXTENSIONS_H_

#include <saitypes.h>
#include <saibridge.h>

/**
 * @brief SAI nexthop attribute extensions
 *
 * @flags free
 */
typedef enum _sai_bridge_port_attr_extensions_t
{
    /** Start of extensions range */
    SAI_BRIDGE_PORT_ATTR_EXTENSIONS_START = SAI_BRIDGE_PORT_ATTR_END,

    /**
     * @brief Custom attr 0
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_BRIDGE_PORT_ATTR_CUSTOM_0 = SAI_BRIDGE_PORT_ATTR_EXTENSIONS_START,

    /** End of custom extensions range */
    SAI_BRIDGE_PORT_ATTR_EXTENSIONS_END

} sai_bridge_port_attr_extensions_t;

#endif /* __SAIBRIDGEEXTENSIONS_H_ */
