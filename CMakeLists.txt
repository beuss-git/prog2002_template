cmake_minimum_required(VERSION 3.15)

project(PROG2002)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # Fix the output directory for the archive artifacts [7]
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # Fix the output directory for libraries [8]
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # Fix the output directory for runtime files [9]

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")

# Build the external dependencies
add_subdirectory(external/tclap)

# Find TCLAP
#
set(TCLAP_INCLUDE_PATH "${CMAKE_CURRENT_LIST_DIR}/external/tclap/include")
find_package(TCLAP REQUIRED)

# Add Lab 01
add_subdirectory(Labs/Lab01)
