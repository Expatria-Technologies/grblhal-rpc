add_library(grblhal-rpc INTERFACE)

target_sources(grblhal-rpc INTERFACE
${CMAKE_CURRENT_LIST_DIR}/grbl_rpc.c
 #${CMAKE_CURRENT_LIST_DIR}/config/common.c
 #${CMAKE_CURRENT_LIST_DIR}/infra/tmc_interface.c
 #${CMAKE_CURRENT_LIST_DIR}/port/tmc2130.c
 #${CMAKE_CURRENT_LIST_DIR}/setup/tmc2130hal.c
 #${CMAKE_CURRENT_LIST_DIR}/transports/tmc2209.c
)

target_include_directories(grblhal-rpc INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/config
    ${CMAKE_CURRENT_LIST_DIR}/infra
    ${CMAKE_CURRENT_LIST_DIR}/port
    ${CMAKE_CURRENT_LIST_DIR}/setup
    ${CMAKE_CURRENT_LIST_DIR}/transports
)
