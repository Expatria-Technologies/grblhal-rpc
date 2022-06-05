add_library(grblhal-rpc INTERFACE)

target_sources(grblhal-rpc INTERFACE
${CMAKE_CURRENT_LIST_DIR}/grblhal_rpc.c
${CMAKE_CURRENT_LIST_DIR}/rpc_wrappers.c
${CMAKE_CURRENT_LIST_DIR}/grblhal_rpc_server.cpp
${CMAKE_CURRENT_LIST_DIR}/config/
${CMAKE_CURRENT_LIST_DIR}/infra/erpc_client_manager.cpp
${CMAKE_CURRENT_LIST_DIR}/infra/erpc_basic_codec.cpp
${CMAKE_CURRENT_LIST_DIR}/infra/erpc_crc16.cpp
${CMAKE_CURRENT_LIST_DIR}/infra/erpc_framed_transport.cpp
${CMAKE_CURRENT_LIST_DIR}/infra/erpc_message_buffer.cpp
${CMAKE_CURRENT_LIST_DIR}/infra/erpc_message_loggers.cpp
${CMAKE_CURRENT_LIST_DIR}/infra/erpc_pre_post_action.cpp
${CMAKE_CURRENT_LIST_DIR}/infra/erpc_server.cpp
${CMAKE_CURRENT_LIST_DIR}/infra/erpc_simple_server.cpp
${CMAKE_CURRENT_LIST_DIR}/port/erpc_grblhal.cpp
${CMAKE_CURRENT_LIST_DIR}/setup/erpc_setup_mbf_dynamic.cpp
${CMAKE_CURRENT_LIST_DIR}/setup/erpc_setup_mbf_static.cpp
${CMAKE_CURRENT_LIST_DIR}/setup/erpc_server_setup.cpp
${CMAKE_CURRENT_LIST_DIR}/setup/erpc_setup_grblhal.cpp
${CMAKE_CURRENT_LIST_DIR}/transports/erpc_grblhal_transport.cpp
)

target_include_directories(grblhal-rpc INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/config
    ${CMAKE_CURRENT_LIST_DIR}/infra
    ${CMAKE_CURRENT_LIST_DIR}/port
    ${CMAKE_CURRENT_LIST_DIR}/setup
    ${CMAKE_CURRENT_LIST_DIR}/transports
)
