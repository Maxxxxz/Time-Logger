# Our minimum version of CMake
cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

# Project Name
project(time-logger)


# Add wxWidgets
find_package(wxWidgets COMPONENTS gl core base OPTIONAL_COMPONENTS net)
message(STATUS "wx include dir: ${wxWidgets_INCLUDE_DIRS}")
if(wxWidgets_FOUND)
  include(${wxWidgets_USE_FILE})
  message(STATUS "wx include dir: ${wxWidgets_INCLUDE_DIRS}")
  # and for each of your dependent executable/library targets:
  target_link_libraries(time-logger ${wxWidgets_LIBRARIES})
endif()
# Executable
add_executable(time-logger src/main.cpp)

# Add wx include dirs
include_directories(time-logger ${wxWidgets_INCLUDE_DIRS})

