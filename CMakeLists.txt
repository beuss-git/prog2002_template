cmake_minimum_required(VERSION 3.15)

project(PROG2002)

# Enable testing
enable_testing()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # Fix the output directory for the archive artifacts [7]
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # Fix the output directory for libraries [8]
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # Fix the output directory for runtime files [9]

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")

# Choose vendor neutral OpenGL (libOpenGL.so, libGLX.so) over libGL.so
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

# Disable unnecessary glfw builds
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_BUILD_EXAMPLES OFF)

# Build the external dependencies
add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(external/glm)
add_subdirectory(external/tester)

# Find TCLAP
#
set(TCLAP_INCLUDE_PATH "${CMAKE_CURRENT_LIST_DIR}/external/tclap/include")
find_package(TCLAP REQUIRED)

# Add example lab
add_subdirectory(Labs/LabXX)

# Add Lab 00
add_subdirectory(Labs/Lab00)

# Add Lab 01
add_subdirectory(Labs/Lab01)
