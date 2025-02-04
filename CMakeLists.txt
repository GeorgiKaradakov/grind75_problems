# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(grind_tasks)

#enable compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the root source directory
set(SOURCE_DIR ${CMAKE_SOURCE_DIR})

# Include directories for headers
include_directories(
    ${SOURCE_DIR}/utils
    ${SOURCE_DIR}/week_1
    ${SOURCE_DIR}/week_2
    ${SOURCE_DIR}/week_3
    # ${SOURCE_DIR}/week_4
    # ${SOURCE_DIR}/week_5
    # ${SOURCE_DIR}/week_6
    # ${SOURCE_DIR}/week_7
    # ${SOURCE_DIR}/week_8
    # ${SOURCE_DIR}/week_9
)

set(CMAKE_BUILD_TYPE Debug)

# Define the main executable
add_executable(${PROJECT_NAME} ${SOURCE_DIR}/main.cpp)
