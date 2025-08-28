cmake_minimum_required(VERSION 4.0)
project(sockets)

set(CMAKE_CXX_STANDARD 20)
include_directories(include/)

add_executable(sockets src/main.cpp
        include/sockets/Listener.hpp
        src/Listener.cpp)
