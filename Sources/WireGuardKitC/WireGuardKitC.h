// SPDX-License-Identifier: MIT
// Copyright © 2018-2023 WireGuard LLC. All Rights Reserved.

// u_int32_t / u_char / u_int16_t must come from the DarwinFoundation modules;
// declaring them ourselves breaks explicit-module builds on newer SDKs.
#include <sys/types.h>

#include "key.h"
#include "x25519.h"

// The kernel-control (utun) declarations were never public on iOS and are
// absent from modern iOS SDKs; WireGuardAdapter still consumes them, so they
// are declared here with types imported from <sys/types.h> (DarwinFoundation).

/* From <sys/kern_control.h> (not exposed by modern iOS SDKs) */
#ifndef CTLIOCGINFO
#define CTLIOCGINFO 0xc0644e03UL
struct ctl_info {
    u_int32_t   ctl_id;
    char        ctl_name[96];
};
struct sockaddr_ctl {
    u_char      sc_len;
    u_char      sc_family;
    u_int16_t   ss_sysaddr;
    u_int32_t   sc_id;
    u_int32_t   sc_unit;
    u_int32_t   sc_reserved[5];
};
#endif /* CTLIOCGINFO */
