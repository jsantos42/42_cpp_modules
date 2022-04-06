cmake_minimum_required(VERSION 3.21)
project(ex01)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(ex01 main.cpp ClapTrap.cpp ClapTrap.h ScavTrap.cpp ScavTrap.h)
