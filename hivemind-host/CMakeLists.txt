set(LIB_NAME "swarmus-pheromones-hivemind-host")
set(LIB_ALIAS "SwarmUS::Pheromones::HiveMind::Host")

nanopb_generate_cpp(PROTO_SRCS PROTO_HDRS
    RELPATH
        ${CMAKE_CURRENT_SOURCE_DIR}/proto

    proto/generic.proto
    proto/function-call.proto
    proto/message.proto
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set_source_files_properties(${PROTO_SRCS} ${PROTO_HDRS}
    PROPERTIES GENERATED TRUE)

add_library(${LIB_NAME} STATIC ${PROTO_SRCS} ${PROTO_HDRS})
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME}
    PUBLIC
        ${NANOPB_INCLUDE_DIRS}

        # Where nanopb generates it's files
        ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${LIB_NAME}
    PUBLIC
        protobuf-nanopb-static
)

