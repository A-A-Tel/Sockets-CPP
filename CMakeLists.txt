cmake_minimum_required(VERSION 4.0)
project(sockets)

set(CMAKE_CXX_STANDARD 26)
include_directories(include/)

add_executable(sockets
        src/client.cpp
        src/server.cpp)
