cmake_minimum_required(VERSION 3.21)
get_filename_component(ProjectDir ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${ProjectDir})

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(${ProjectDir} main.cpp main.cpp)
