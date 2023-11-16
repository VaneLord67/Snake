cmake_minimum_required(VERSION 3.16)
project(Snake)

set(CMAKE_CXX_STANDARD 14)

add_executable(Snake main.cpp snake.cpp snake.h item.cpp item.h position.cpp position.h map.cpp map.h main.h)
