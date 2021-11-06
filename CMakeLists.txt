# Our minimum version of CMake
cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

# Project Name
project(time-logger)

# Set our variables
set(wxWidgets_ROOT_DIR $ENV{wx_ROOT_DIR})
set(wxWidgets_LIB_DIR $ENV{wx_LIB_DIR})
file(TO_CMAKE_PATH $ENV{yaml_cpp_ROOT_DIR} yaml_cpp_ROOT)
set(yaml_cpp_LIB ${yaml_cpp_ROOT}/build/libyaml-cpp.a)
set(yaml_cpp_INCLUDE ${yaml_cpp_ROOT}/include)

# Add wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# Add our /src directory as a glob
file(GLOB src_GLOB
  src/*
)

# Executable
add_executable(time-logger ${src_GLOB})

# Link libraries and add include directories
target_link_libraries(time-logger ${wxWidgets_LIBRARIES} ${yaml_cpp_LIB})
target_include_directories(time-logger PRIVATE ${wxWidgets_INCLUDE_DIRS} PRIVATE ${yaml_cpp_INCLUDE})
