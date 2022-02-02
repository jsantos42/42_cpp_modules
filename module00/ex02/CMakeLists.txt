cmake_minimum_required(VERSION 3.16)
project(ex02)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CPP_FLAGS -Wall -Werror -Wextra)

add_executable(ex02 tests.cpp Account.cpp Account.hpp)
