# Our minimum version of CMake
cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

# Project Name
project(time-logger)

# Executable
add_executable(time-logger src/main.cpp)