/*

  rpc_wrappers.c - Wrapper functions to expose GRBLHAL API

  Part of grblHAL

  Public domain

*/
#include "hardware/gpio.h"
#include "driver.h"
#include "grblhal_rpc_server.h"
#include <erpc_server_setup.h>
#include "serial.h"
#include "usb_serial.h"

#include "rpc_wrappers.h"
#include "grblhal_rpc.h"

#include "../grbl/hal.h"
#include "../grbl/protocol.h"
#include "../grbl/motion_control.h"
#include "../grbl/state_machine.h"


void led_on (uint8_t led){
    gpio_put(8, 0);
}

void led_off (uint8_t led){
    gpio_put(8, 1);    
}

rpc_coolant_state * get_coolant_state (void){
    rpc_coolant_state * a;

    a->flood = (bool) hal.coolant.get_state().flood;
    a->mist = (bool) hal.coolant.get_state().mist;
    a->shower = (bool) hal.coolant.get_state().shower;
    a->through_spindle = (bool) hal.coolant.get_state().trough_spindle;

    return a;
}
