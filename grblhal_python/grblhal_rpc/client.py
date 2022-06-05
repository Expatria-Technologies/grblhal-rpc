# Implementation of eRPC for GRBLHAL IOStreams.

#
# Generated by erpcgen 1.9.0 on Sat Jun  4 22:11:33 2022.
#
# AUTOGENERATED - DO NOT EDIT
#

import erpc
from . import common, interface

# Client for GRBLHALService
class GRBLHALServiceClient(interface.IGRBLHALService):
    def __init__(self, manager):
        super(GRBLHALServiceClient, self).__init__()
        self._clientManager = manager

    def led_on(self, led):
        # Build remote function invocation message.
        request = self._clientManager.create_request()
        codec = request.codec
        codec.start_write_message(erpc.codec.MessageInfo(
                type=erpc.codec.MessageType.kInvocationMessage,
                service=self.SERVICE_ID,
                request=self.LED_ON_ID,
                sequence=request.sequence))
        if led is None:
            raise ValueError("led is None")
        codec.write_uint8(led)

        # Send request and process reply.
        self._clientManager.perform_request(request)

    def led_off(self, led):
        # Build remote function invocation message.
        request = self._clientManager.create_request()
        codec = request.codec
        codec.start_write_message(erpc.codec.MessageInfo(
                type=erpc.codec.MessageType.kInvocationMessage,
                service=self.SERVICE_ID,
                request=self.LED_OFF_ID,
                sequence=request.sequence))
        if led is None:
            raise ValueError("led is None")
        codec.write_uint8(led)

        # Send request and process reply.
        self._clientManager.perform_request(request)

    def get_coolant_state(self):
        # Build remote function invocation message.
        request = self._clientManager.create_request()
        codec = request.codec
        codec.start_write_message(erpc.codec.MessageInfo(
                type=erpc.codec.MessageType.kInvocationMessage,
                service=self.SERVICE_ID,
                request=self.GET_COOLANT_STATE_ID,
                sequence=request.sequence))

        # Send request and process reply.
        self._clientManager.perform_request(request)
        _result = common.rpc_coolant_state()._read(codec)
        return _result


