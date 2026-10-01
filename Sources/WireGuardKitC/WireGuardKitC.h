// SPDX-License-Identifier: MIT
// Copyright © 2018-2023 WireGuard LLC. All Rights Reserved.

// u_int32_t / u_char / u_int16_t must come from the DarwinFoundation modules;
// declaring them ourselves breaks explicit-module builds on newer SDKs.
#include <sys/types.h>

#include "key.h"
#include "x25519.h"

// The kernel-control (utun) declarations were never public on iOS and are
// absent from modern iOS SDKs; wireguard-go performs its own syscalls.
