/*

  grblhal_rpc.c - Implementation of eRPC for GRBLHAL IOStreams.

  Part of grblHAL

  Public domain

  Use this command to generate the shim code:
  erpcgen -g c grblhal-rpc.erpc

  Use this command to generate the Python shim code:
  erpcgen -g py -o grblhal_python led-service.erpc


*/
#include "hardware/gpio.h"
#include "driver.h"
#include "serial.h"
#include "usb_serial.h"

#include "../grbl/hal.h"
#include "../grbl/protocol.h"
#include "../grbl/motion_control.h"
#include "../grbl/state_machine.h"

#include "grblhal_rpc_server.h"
#include <erpc_server_setup.h>

static on_report_options_ptr on_report_options;
static on_execute_realtime_ptr on_execute_realtime;
static on_state_change_ptr on_state_change;

static const io_stream_t *rpc_stream;

// Don't want to strip any characters from our input stream
ISR_CODE bool ISR_FUNC(stream_insert_buffer)(char c)
{
    return 0;
}

// Add info about our plugin to the $I report.
static void on_report_my_options (bool newopt)
{
    on_report_options(newopt);

    if(!newopt)
        hal.stream.write("[PLUGIN:RPC LED v1.01]" ASCII_EOL);
        //rpc_stream->write("[PLUGIN:RPC LED v1.00]" ASCII_EOL);
}
static void erpc_server_function (sys_state_t state){

    // Run the server.
    erpc_server_poll();

    on_execute_realtime(state);
}

void grblhal_rpc_server(void) {

    // Initialize server running over IOStream.
    erpc_server_init(
        erpc_transport_grblhal_init(rpc_stream),
        erpc_mbf_dynamic_init());

    // Add the IO service.
    erpc_add_service_to_server(create_GRBLHALService_service());
}


void grbl_rpc_init (void)
{
    rpc_stream = usb_serialInit();
    rpc_stream->set_enqueue_rt_handler(stream_insert_buffer);

    // Add info about our plugin to the $I report.
    on_report_options = grbl.on_report_options;
    grbl.on_report_options = on_report_my_options;

    grblhal_rpc_server();

    // Add erpc function to grblHAL foreground process
    on_execute_realtime = grbl.on_execute_realtime;
    grbl.on_execute_realtime = erpc_server_function;

}
