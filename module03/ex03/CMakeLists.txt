cmake_minimum_required(VERSION 3.21)
project(ex03)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wshadow")

add_executable(ex03 main.cpp ClapTrap.cpp ClapTrap.h ScavTrap.cpp ScavTrap.h FragTrap.cpp FragTrap.h DiamondTrap.cpp DiamondTrap.h)
