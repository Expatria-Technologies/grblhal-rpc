/*

  rpc_wrappers.c - Wrapper functions to expose GRBLHAL API

  Part of grblHAL

  Public domain

*/

#include <stdlib.h>

#include "hardware/gpio.h"
#include "driver.h"
#include "grblhal_rpc_server.h"
#include <erpc_server_setup.h>
#include "serial.h"
#include "usb_serial.h"

#include "grblhal_rpc.h"
#include "rpc_wrappers.h"

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

rpc_coolant_state_t * rpc_get_coolant_state(void){
    //calling function needs to take care of garbage collection.
    rpc_coolant_state_t *a = malloc(sizeof(rpc_coolant_state_t));

        a->flood = (uint8_t) hal.coolant.get_state().flood;
        a->mist = (uint8_t) hal.coolant.get_state().mist;
        a->shower = (uint8_t)hal.coolant.get_state().shower;
        a->through_spindle = (uint8_t) hal.coolant.get_state().trough_spindle;

    return a;
}

uint8_t rpc_get_integer (void){
    
    return 42;
}

