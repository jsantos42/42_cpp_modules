cmake_minimum_required(VERSION 3.21)
project(ex00)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex00 main.cpp Zombie.cpp Zombie.h utils.cpp utils.h newZombie.cpp newZombie.h randomChump.cpp randomChump.h)
