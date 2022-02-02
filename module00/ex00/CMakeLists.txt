cmake_minimum_required(VERSION 3.21)
project(ex00)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CPP_FLAGS -Wall -Werror -Wextra)

add_executable(ex00 megaphone.cpp)
