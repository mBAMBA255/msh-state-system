cmake_minimum_required(VERSION 3.10)

# Project name
project(MySweetHome)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Executable
add_executable(MySweetHome ${SOURCES})

