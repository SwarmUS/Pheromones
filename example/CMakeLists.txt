set(LIB_NAME "swarmus-pheromones-example")
set(LIB_ALIAS "SwarmUS::Pheromones::Example")

nanopb_generate_cpp(PROTO_SRCS PROTO_HDRS example.proto)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set_source_files_properties(${PROTO_SRCS} ${PROTO_HDRS}
    PROPERTIES GENERATED TRUE)

add_library(${LIB_NAME} STATIC ${PROTO_SRCS} ${PROTO_HDRS})
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME}
    PUBLIC
        ${NANOPB_INCLUDE_DIRS})

target_link_libraries(${LIB_NAME}
    protobuf-nanopb-static)


# Just an example on how to use the created lib
add_executable(example example.c ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(example
    PUBLIC
        Pheromones::Example)


