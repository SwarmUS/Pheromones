nanopb_generate_cpp(PROTO_SRCS PROTO_HDRS example.proto)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
set_source_files_properties(${PROTO_SRCS} ${PROTO_HDRS}
    PROPERTIES GENERATED TRUE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -g -O0")

add_executable(example example.c ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(example
  PUBLIC
    protobuf-nanopb-static)

include_directories(${NANOPB_INCLUDE_DIRS})
