cmake_minimum_required(VERSION 3.21)
project(ex01)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CPP_FLAGS -Wall -Werror -Wextra)

add_executable(ex01 main.cpp utils.cpp utils.h Contact.cpp Contact.h PhoneBook.cpp PhoneBook.h const.h)
