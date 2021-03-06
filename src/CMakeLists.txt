set(LIB_NAME "swarmus-pheromones")
set(LIB_ALIAS "SwarmUS::Pheromones")

# Installation destinations
set(PHEROMONES_LIB_INSTALL_DEST "lib/swarmus-pheromones")
set(PHEROMONES_INCLUDE_INSTALL_DEST "include/")

include(DefaultMessageOptions.cmake) # not a module, need to specify "".cmake"
configure_file(proto/message.options.in ${CMAKE_CURRENT_SOURCE_DIR}/proto/message.options)

nanopb_generate_cpp(PROTO_SRCS PROTO_HDRS
    RELPATH
        ${CMAKE_CURRENT_SOURCE_DIR}/proto
        
    proto/message.proto
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set_source_files_properties(${PROTO_SRCS} ${PROTO_HDRS}
    PROPERTIES GENERATED TRUE)

add_library(${LIB_NAME} STATIC ${PROTO_SRCS} ${PROTO_HDRS})
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${NANOPB_INCLUDE_DIRS}>

        # Where nanopb generates it's files
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>

        )

target_link_libraries(${LIB_NAME}
    PRIVATE
        protobuf-nanopb-static
)

message("nanopc path ${NANOPB_PATH}")

install(TARGETS ${LIB_NAME} EXPORT ${LIB_NAME} DESTINATION "${PHEROMONES_LIB_INSTALL_DEST}")
install(FILES ${LIB_HEADERS} DESTINATION "${PHEROMONES_INCLUDE_INSTALL_DEST}")
install(FILES swarmus-pheromones-config.cmake DESTINATION "${PHEROMONES_LIB_INSTALL_DEST}")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/message.pb.h DESTINATION ${PHEROMONES_INCLUDE_INSTALL_DEST})

install(EXPORT ${LIB_NAME} DESTINATION "${PHEROMONES_LIB_INSTALL_DEST}")