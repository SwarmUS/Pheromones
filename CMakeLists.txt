cmake_minimum_required(VERSION 3.13)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Project definition
project(pheromones CXX C)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

# Includes
include(nanopb/common)


# Required for most libs
nanopb_fetch()
find_package(Nanopb REQUIRED)

# Add libraries
add_subdirectory(example)
add_subdirectory(hivemind-host)
