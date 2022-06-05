/*
 * This file is part of the Bus Pirate project (http://code.google.com/p/the-bus-pirate/).
 *
 * Written and maintained by the Bus Pirate project and http://dangerousprototypes.com
 *
 * To the extent possible under law, the project has
 * waived all copyright and related or neighboring rights to Bus Pirate. This
 * work is published from United States.
 *
 * For details see: http://creativecommons.org/publicdomain/zero/1.0/.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */
/*
 * OS independent serial interface
 *
 * Heavily based on Pirate-Loader:
 * http://the-bus-pirate.googlecode.com/svn/trunk/bootloader-v4/pirate-loader/source/pirate-loader.c
 *
 */
#ifndef MYGRBLHAL_H_
#define MYGRBLHAL_H_

#include <stdint.h>

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include <driver.h>
#include <grbl/hal.h>
#include <grbl/platform.h>

#include <erpc_port.h>

#endif

/*!
 * @addtogroup port_grblhal
 * @{
 * @file
 */

#if __cplusplus
extern "C" {
#endif

int grblhal_setup(const io_stream_t *rpc_stream);
int grblhal_write(const io_stream_t *rpc_stream, char *buf, int size);
int grblhal_read(const io_stream_t *rpc_stream, char *buf, int size);
int grblhal_open(const io_stream_t *rpc_stream);
int grblhal_close(const io_stream_t *rpc_stream);

#if __cplusplus
}
#endif

/*! @} */
