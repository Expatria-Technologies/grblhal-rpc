/*
 * Copyright (c) 2014-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * Copyright 2021 ACRIOS Systems s.r.o.
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "erpc_manually_constructed.h"
#include "erpc_grblhal_transport.h"
#include "erpc_transport_setup.h"

using namespace erpc;

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

ERPC_MANUALLY_CONSTRUCTED(GRBLHALTransport, g_transport);

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

erpc_transport_t erpc_transport_grblhal_init(const io_stream_t *rpc_stream)
{
    erpc_transport_t transport;
    const uint8_t vtime = 0;
    const uint8_t vmin = 1;

    g_transport.construct(rpc_stream);
    if (s_transport->init(vtime, vmin) == kErpcStatus_Success)
    {
        transport = reinterpret_cast<erpc_transport_t>(g_transport.get());
    }
    else
    {
        transport = NULL;
    }

    return transport;
}
