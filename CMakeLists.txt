cmake_minimum_required(VERSION 3.15)

project(PROG2002)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")

# Build the external dependencies
add_subdirectory(external/tclap)

# Find TCLAP
#
set(TCLAP_INCLUDE_PATH "${CMAKE_CURRENT_LIST_DIR}/external/tclap/include")
find_package(TCLAP REQUIRED)

# Add Lab 01
add_subdirectory(Labs/Lab01)
