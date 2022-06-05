/*
 * Implementation of eRPC for GRBLHAL IOStreams.
 */

/*
 * Generated by erpcgen 1.9.0 on Sat Jun  4 22:10:58 2022.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include "erpc_client_manager.h"
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
#include "erpc_port.h"
#endif
#include "erpc_codec.h"
extern "C"
{
#include "grblhal_rpc.h"
}

#if 10900 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

using namespace erpc;
using namespace std;

extern ClientManager *g_client;

//! @brief Function to read struct rpc_coolant_state
static void read_rpc_coolant_state_struct(erpc::Codec * codec, rpc_coolant_state * data);


// Read struct rpc_coolant_state function implementation
static void read_rpc_coolant_state_struct(erpc::Codec * codec, rpc_coolant_state * data)
{
    if(NULL == data)
    {
        return;
    }

    codec->read(&data->flood);

    codec->read(&data->mist);

    codec->read(&data->shower);

    codec->read(&data->through_spindle);
}



// GRBLHALService interface led_on function client shim.
void led_on(uint8_t led)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = g_client->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = g_client->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    if (codec == NULL)
    {
        err = kErpcStatus_MemoryError;
    }
    else
    {
        codec->startWriteMessage(kInvocationMessage, kGRBLHALService_service_id, kGRBLHALService_led_on_id, request.getSequence());

        codec->write(led);

        // Send message to server
        // Codec status is checked inside this function.
        g_client->performRequest(request);

        err = codec->getStatus();
    }

    // Dispose of the request.
    g_client->releaseRequest(request);

    // Invoke error handler callback function
    g_client->callErrorHandler(err, kGRBLHALService_led_on_id);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = g_client->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// GRBLHALService interface led_off function client shim.
void led_off(uint8_t led)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = g_client->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = g_client->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    if (codec == NULL)
    {
        err = kErpcStatus_MemoryError;
    }
    else
    {
        codec->startWriteMessage(kInvocationMessage, kGRBLHALService_service_id, kGRBLHALService_led_off_id, request.getSequence());

        codec->write(led);

        // Send message to server
        // Codec status is checked inside this function.
        g_client->performRequest(request);

        err = codec->getStatus();
    }

    // Dispose of the request.
    g_client->releaseRequest(request);

    // Invoke error handler callback function
    g_client->callErrorHandler(err, kGRBLHALService_led_off_id);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = g_client->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// GRBLHALService interface get_coolant_state function client shim.
rpc_coolant_state * get_coolant_state(void)
{
    erpc_status_t err = kErpcStatus_Success;

    rpc_coolant_state * result = NULL;

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = g_client->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = g_client->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    if (codec == NULL)
    {
        err = kErpcStatus_MemoryError;
    }
    else
    {
        codec->startWriteMessage(kInvocationMessage, kGRBLHALService_service_id, kGRBLHALService_get_coolant_state_id, request.getSequence());

        // Send message to server
        // Codec status is checked inside this function.
        g_client->performRequest(request);

        result = (rpc_coolant_state *) erpc_malloc(sizeof(rpc_coolant_state));
        if (result == NULL)
        {
            codec->updateStatus(kErpcStatus_MemoryError);
        }
        read_rpc_coolant_state_struct(codec, result);

        err = codec->getStatus();
    }

    // Dispose of the request.
    g_client->releaseRequest(request);

    // Invoke error handler callback function
    g_client->callErrorHandler(err, kGRBLHALService_get_coolant_state_id);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = g_client->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return result;
}
