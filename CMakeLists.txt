cmake_minimum_required(VERSION 3.13)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(pheromones C)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

# list that will contain libs provided by the project
unset(PHEROMONES_LIB_LIST)

include(nanopb/common)
nanopb_fetch()
find_package(Nanopb REQUIRED)

add_subdirectory(example)
add_subdirectory(hivemind-host)
