set(LIB_NAME "swarmus-pheromones-common")
set(LIB_ALIAS "SwarmUS::Pheromones::Common")

set(LIB_SOURCES
)

set(LIB_HEADERS
    include/common/IProtobufStream.h
)

add_library(${LIB_NAME} STATIC ${LIB_HEADERS} ${LIB_SOURCES})
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME}
    PUBLIC
       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
       $<INSTALL_INTERFACE:include>
)

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()
