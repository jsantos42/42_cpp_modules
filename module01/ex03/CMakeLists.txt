cmake_minimum_required(VERSION 3.21)
project(ex03)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex03 main.cpp Weapon.cpp Weapon.h HumanA.cpp HumanA.h HumanB.cpp HumanB.h)
