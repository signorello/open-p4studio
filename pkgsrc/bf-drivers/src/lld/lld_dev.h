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


#ifndef LLD_DEV_H_INCLUDED
#define LLD_DEV_H_INCLUDED

/* Allow the use in C++ code.  */
#ifdef __cplusplus
extern "C" {
#endif

struct bf_dma_info_s;

bf_status_t lld_master_dev_add(bf_dev_id_t dev_id,
                               bf_dev_family_t dev_family,
                               struct bf_dma_info_s *dma_info,
                               bf_dev_init_mode_t warm_init_mode);

bf_status_t lld_dev_add(bf_dev_id_t dev_id,
                        bf_dev_family_t dev_family,
                        bf_device_profile_t *profile,
                        struct bf_dma_info_s *dma_info,
                        bf_dev_init_mode_t warm_init_mode);
bf_status_t lld_dev_remove(bf_dev_id_t dev_id);
bf_status_t lld_reset_core(bf_dev_id_t dev_id);
bool lld_dev_is_tofino(bf_dev_id_t dev_id);
bool lld_dev_is_tof2(bf_dev_id_t dev_id);
bool lld_dev_is_tof3(bf_dev_id_t dev_id);

bool lld_dev_ready(bf_dev_id_t dev_id, bf_subdev_id_t subdev_id);
bf_dev_type_t lld_dev_type_get(bf_dev_id_t dev_id);
bf_dev_family_t lld_dev_family_get(bf_dev_id_t dev_id);

bf_status_t lld_dev_lock(bf_dev_id_t dev_id);
bf_status_t lld_dev_unlock(bf_dev_id_t dev_id);
bf_status_t lld_subdev_lock(bf_dev_id_t dev_id, bf_subdev_id_t subdev_id);
bf_status_t lld_subdev_unlock(bf_dev_id_t dev_id, bf_subdev_id_t subdev_id);
bool lld_dev_is_locked(bf_dev_id_t dev_id, bf_subdev_id_t subdev_id);
bf_status_t lld_warm_init_quick(bf_dev_id_t dev_id);

#ifdef __cplusplus
}
#endif /* C++ */

#endif  // LLD_DEV_H_INCLUDED
