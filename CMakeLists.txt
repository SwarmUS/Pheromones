cmake_minimum_required(VERSION 3.13)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(pheromones C)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)


include(nanopb/common)
nanopb_fetch()

find_package(Nanopb REQUIRED)

nanopb_generate_cpp(PROTO_SRCS PROTO_HDRS proto/simple.proto)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
set_source_files_properties(${PROTO_SRCS} ${PROTO_HDRS}
    PROPERTIES GENERATED TRUE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -g -O0")

add_executable(simple simple.c ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(simple
  PUBLIC
    protobuf-nanopb-static)

include_directories(${NANOPB_INCLUDE_DIRS})
