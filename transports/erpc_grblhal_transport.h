/*
 * Copyright (c) 2014, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _EMBEDDED_RPC__SERIAL_TRANSPORT_H_
#define _EMBEDDED_RPC__SERIAL_TRANSPORT_H_

#include "erpc_framed_transport.h"

#include <string>
#include <stream.h>

/*!
 * @addtogroup serial_transport
 * @{
 * @file
 */

////////////////////////////////////////////////////////////////////////////////
// Classes
////////////////////////////////////////////////////////////////////////////////

namespace erpc {
/*!
 * @brief Serial transport layer for host PC
 *
 * @ingroup grblhal_transport
 */
class GRBLHALTransport : public FramedTransport
{
public:
    /*!
     * @brief Constructor.
     *
     */
    GRBLHALTransport(const io_stream_t *rpc_stream);

    /*!
     * @brief Destructor.
     */
    virtual ~GRBLHALTransport(void);

    /*!
     * @brief Initialize Serial peripheral.
     *
     * @return Status of init function.
     */
    erpc_status_t init(const io_stream_t *rpc_stream);

private:
    /*!
     * @brief Write data to Serial peripheral.
     *
     * @param[in] data Buffer to send.
     * @param[in] size Size of data to send.
     *
     * @retval kErpcStatus_ReceiveFailed Serial failed to receive data.
     * @retval kErpcStatus_Success Successfully received all data.
     */
    virtual erpc_status_t underlyingSend(const uint8_t *data, uint32_t size);

    /*!
     * @brief Receive data from Serial peripheral.
     *
     * @param[inout] data Preallocated buffer for receiving data.
     * @param[in] size Size of data to read.
     *
     * @retval kErpcStatus_ReceiveFailed Serial failed to receive data.
     * @retval kErpcStatus_Success Successfully received all data.
     */
    virtual erpc_status_t underlyingReceive(uint8_t *data, uint32_t size);

private:
    const io_stream_t *grblhal_rpc_stream;
};

} // namespace erpc

/*! @} */

#endif // _EMBEDDED_RPC__SERIAL_TRANSPORT_H_
