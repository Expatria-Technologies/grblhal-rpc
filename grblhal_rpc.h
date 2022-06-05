/*
 * Implementation of eRPC for GRBLHAL IOStreams.
 */

/*
 * Generated by erpcgen 1.9.0 on Sun Jun  5 12:51:53 2022.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_grblhal_rpc_h_)
#define _grblhal_rpc_h_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "erpc_version.h"

#if 10900 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

#if !defined(ERPC_TYPE_DEFINITIONS)
#define ERPC_TYPE_DEFINITIONS

// Aliases data types declarations
typedef struct rpc_coolant_state_t rpc_coolant_state_t;

// Structures/unions data types declarations
struct rpc_coolant_state_t
{
    uint8_t flood;
    uint8_t mist;
    uint8_t shower;
    uint8_t through_spindle;
};


#endif // ERPC_TYPE_DEFINITIONS

/*! @brief GRBLHALService identifiers */
enum _GRBLHALService_ids
{
    kGRBLHALService_service_id = 1,
    kGRBLHALService_led_on_id = 1,
    kGRBLHALService_led_off_id = 2,
    kGRBLHALService_rpc_get_coolant_state_id = 3,
    kGRBLHALService_rpc_get_integer_id = 4,
};

#if defined(__cplusplus)
extern "C" {
#endif

//! @name GRBLHALService
//@{
void led_on(uint8_t led);

void led_off(uint8_t led);

rpc_coolant_state_t * rpc_get_coolant_state(void);

uint8_t rpc_get_integer(void);
//@}

#if defined(__cplusplus)
}
#endif

#endif // _grblhal_rpc_h_
