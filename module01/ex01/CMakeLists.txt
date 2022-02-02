cmake_minimum_required(VERSION 3.21)
project(ex01)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex01 main.cpp utils.cpp Zombie.cpp zombieHorde.cpp zombieHorde.h)
