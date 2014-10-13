/*
 * lispd_config_functions.h
 *
 * This file is part of LISP Mobile Node Implementation.
 * Handle lispd command line and config file
 * Parse command line args using gengetopt.
 * Handle config file with libconfuse.
 *
 * Copyright (C) 2011 Cisco Systems, Inc, 2011. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * Please send any bug reports or fixes you make to the email address(es):
 *    LISP-MN developers <devel@lispmob.org>
 *
 * Written or modified by:
 *    Alberto López     <alopez@ac.upc.edu>
 *
 */

#ifndef LISPD_CONFIG_FUNCTIONS_H_
#define LISPD_CONFIG_FUNCTIONS_H_

#include "lisp_ms.h"
#include "lisp_site.h"
#include "lisp_xtr.h"


void
validate_rloc_probing_parameters(
        int *interval,
        int *retries,
        int *retries_int);

int
validate_priority_weight(
        int priority,
        int weight);

int
add_server(
        char *              server,
        lisp_addr_list_t ** list);

int
add_map_server(
        lisp_xtr_t *xtr,
        char *map_server,
        int key_type,
        char *key,
        uint8_t proxy_reply);

int
add_proxy_etr_entry(
        lisp_xtr_t *    xtr,
        char *          address,
        int             priority,
        int             weight);

int
add_database_mapping(
        lisp_xtr_t  *xtr,
        char        *eid_str,
        int         iid,
        char        *iface_name,
        int         priority4,
        int         weight4,
        int         priority6,
        int         weight6);

int
add_static_map_cache_entry(
        lisp_xtr_t *        xtr,
        char *              eid,
        int                 iid,
        char *              rloc_addr,
        int                 priority,
        int                 weight,
        htable_t *          elp_hash);

/*
 * Create the locators associated with the address of the iface and assign them
 * to the mapping_t and the iface_locators
 * @param iface Interface containing the rlocs associated to the mapping
 * @param if_loct Structure that associate iface with locators
 * @param mapping Mapping where to add the new locators
 * @param priority4 priority of the IPv4 RLOC. 1..255 -1 the IPv4 address is not used
 * @param weight4 weight of the IPv4 RLOC
 * @param priority6 priority of the IPv6 RLOC. 1..255 -1 the IPv6 address is not used
 * @param weight6 weight of the IPv6 RLOC
 * @return GOOD if finish correctly or an error code otherwise
 */

int
link_iface_and_mapping(
        iface_t *           iface,
        iface_locators *    if_loct,
        mapping_t *         mapping,
        int                 priority4,
        int                 weight4,
        int                 priority6,
        int                 weight6);

int
add_rtr_iface(
        lisp_xtr_t  *xtr,
        char        *iface_name,
        int         priority,
        int         weight);

lisp_site_prefix_t *
build_lisp_site_prefix(
        lisp_ms_t *     ms,
        char *          eidstr,
        uint32_t        iid,
        int             key_type,
        char *          key,
        uint8_t         more_specifics,
        uint8_t         proxy_reply,
        uint8_t         merge,
        htable_t *      lcaf_ht);

char *
get_interface_name_from_address(lisp_addr_t *addr);


#endif /* LISPD_CONFIG_FUNCTIONS_H_ */
