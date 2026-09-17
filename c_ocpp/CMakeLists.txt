cmake_minimum_required(VERSION 3.14)
project(c_ocpp C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

set(CJSON_SRC ${CMAKE_CURRENT_SOURCE_DIR}/third_party/cjson/cJSON.c)

# Shared once: do not archive port/cJSON/layer1 into both version libs
# (linking c_ocpp16 + c_ocpp201 would duplicate those symbols).
add_library(c_ocpp_core STATIC
    ${CJSON_SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/layer1/ocpp_json.c
    ${CMAKE_CURRENT_SOURCE_DIR}/layer1/ocpp_rpc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/port/ocpp_port.c
)
target_include_directories(c_ocpp_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/port
    ${CMAKE_CURRENT_SOURCE_DIR}/layer1
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/cjson
)

file(GLOB OCPP16_MSG_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ocpp16/messages/*.c)
file(GLOB OCPP201_MSG_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ocpp201/messages/*.c)

add_library(c_ocpp16 STATIC
    ${OCPP16_MSG_SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/ocpp16/ocpp16_session.c
)
target_include_directories(c_ocpp16
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ocpp16
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/ocpp16/messages
)
target_link_libraries(c_ocpp16 PUBLIC c_ocpp_core)

add_library(c_ocpp201 STATIC
    ${OCPP201_MSG_SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/ocpp201/ocpp201_session.c
)
target_include_directories(c_ocpp201
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ocpp201
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/ocpp201/messages
)
target_link_libraries(c_ocpp201 PUBLIC c_ocpp_core)

enable_testing()
add_executable(test_ocpp16 tests/test_ocpp16.c)
target_link_libraries(test_ocpp16 PRIVATE c_ocpp16)
add_test(NAME test_ocpp16 COMMAND test_ocpp16)

add_executable(test_ocpp201 tests/test_ocpp201.c)
target_link_libraries(test_ocpp201 PRIVATE c_ocpp201)
add_test(NAME test_ocpp201 COMMAND test_ocpp201)

add_executable(test_ocpp_both tests/test_ocpp_both.c)
target_link_libraries(test_ocpp_both PRIVATE c_ocpp16 c_ocpp201)
add_test(NAME test_ocpp_both COMMAND test_ocpp_both)
