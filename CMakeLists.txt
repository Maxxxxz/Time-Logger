# Our minimum version of CMake
cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

# Project Name
project(time-logger)

# Set our variables
set(wxWidgets_ROOT_DIR $ENV{wx_ROOT_DIR})
set(wxWidgets_LIB_DIR $ENV{wx_LIB_DIR})

# Add wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# Add our /src directory as a glob
file(GLOB src_GLOB
  src/*
)

# Executable
add_executable(time-logger ${src_GLOB})

# Link wxWidgets lib and add the wxWidgets link libraries
target_link_libraries(time-logger ${wxWidgets_LIBRARIES})
target_include_directories(time-logger PRIVATE ${wxWidgets_INCLUDE_DIRS})