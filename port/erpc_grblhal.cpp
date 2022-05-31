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

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <errno.h>
#include <string.h>
/*included this here for cygwin. need to figure out proper include handling for cygwin */
//#include <termios.h>

//#define LINUX 1
//#ifdef LINUX
//#include <termios.h>
//#endif
// included from serial.h

#include "erpc_grblhal.h"

int grblhal_setup(io_stream_t *rpc_stream)
{
    return 0;
}

int grblhal_set_read_timeoutio_stream_t *rpc_stream, uint8_t vtime, uint8_t vmin)
{
    return 0;
}

int grblhal_write(io_stream_t *rpc_stream, char *buf, int size)
{
    uint32_t counter = 0;

    while (counter < size){
        rpc_stream.write_char(buf[counter]);
        counter++
    }
    return counter;

}

int grblhal_read(io_stream_t *rpc_stream, char *buf, int size)
{
    int len = 0;
    int ret = 0;
    int timeout = 0;

    while (len < size)
    {
        ret = SERIAL_NO_DATA;
        ret = rpc_stream.read();
        if (ret == -1)
        {
            timeout++;

            if (timeout >= 10)
            {
                break;
            }

            continue;
        } else{
            buf[len] = ret;
            len ++;
        }
    }

    return len;
#endif
}

int grblhal_open(io_stream_t *rpc_stream)
{
    int fd = 0;
}

int serial_close(io_stream_t *rpc_stream)
{
    return 0;
}
