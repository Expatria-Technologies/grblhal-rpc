/*

  my_plugin.c - user defined plugin that blinks the LED on a STM32F411 Blackpill

  Part of grblHAL

  Public domain

*/
#include "hardware/gpio.h"
#include "driver.h"
#include "blink_led_server.h"
#include <erpc_server_setup.h>
#include "serial.h"
#include "usb_serial.h"

static on_report_options_ptr on_report_options;
static on_execute_realtime_ptr on_execute_realtime;

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

/*static void blink_led (sys_state_t state)
{
    static bool led_on = false;
    static uint32_t ms = 0;

    if(hal.get_elapsed_ticks() >= ms) {
        ms = hal.get_elapsed_ticks() + 500; //ms
        led_on = !led_on;
        if(led_on)
            gpio_put(8, 1);
        else
            gpio_put(8, 0);
    }

    on_execute_realtime(state);
}*/

void led_on (uint8_t led){
    gpio_put(8, 0);
}

void led_off (uint8_t led){
    gpio_put(8, 1);
}

static void erpc_server_function (sys_state_t state){

    // Run the server.
    erpc_server_poll();

    on_execute_realtime(state);
}

void example_server(void) {

    // Initialize server running over IOStream.
    erpc_server_init(
        erpc_transport_grblhal_init(rpc_stream),
        erpc_mbf_dynamic_init());

    // Add the IO service.
    erpc_add_service_to_server(create_LEDBlinkService_service());
}


void grbl_rpc_init (void)
{
    rpc_stream = usb_serialInit();
    rpc_stream->set_enqueue_rt_handler(stream_insert_buffer);

    // Add info about our plugin to the $I report.
    on_report_options = grbl.on_report_options;
    grbl.on_report_options = on_report_my_options;

    gpio_init(8);
    gpio_set_dir(8, GPIO_OUT);
    gpio_put(8, 1);

    example_server();

    // Add erpc function to grblHAL foreground process
    on_execute_realtime = grbl.on_execute_realtime;
    grbl.on_execute_realtime = erpc_server_function;

}
