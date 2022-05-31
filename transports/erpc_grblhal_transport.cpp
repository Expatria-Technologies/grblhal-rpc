/*
 * Copyright (c) 2014, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
 * Copyright 2021 ACRIOS Systems s.r.o.
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Modified for GRBLHAL
 */

#include "erpc_serial_transport.h"

#include "erpc_message_buffer.h"
#include "erpc_serial.h"

#include <cstdio>
#include <string>


using namespace erpc;

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

static const io_stream_t *grblhal_rpc_stream;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

GRBLHALTransport::GRBLHALTransport(io_stream_t *rpc_stream)
{
}

GRBLHALTransport::~GRBLHALTransport(void)
{
}

erpc_status_t GRBLHALTransport::init(const io_stream_t *rpc_stream)
{
    erpc_status_t status = kErpcStatus_Success;

    grblhal_rpc_stream = rpc_stream;

    return status;
}

erpc_status_t GRBLHALTransport::underlyingSend(const uint8_t *data, uint32_t size)
{
    uint32_t bytesWritten = grblhal_write(grblhal_rpc_stream, (char *)data, size);

    return (size != bytesWritten) ? kErpcStatus_SendFailed : kErpcStatus_Success;
}
erpc_status_t GRBLHALTransport::underlyingReceive(uint8_t *data, uint32_t size)
{
    uint32_t bytesRead = grblhal_read(grblhal_rpc_stream, (char *)data, size);

    return (size != bytesRead) ? kErpcStatus_ReceiveFailed : kErpcStatus_Success;
}
