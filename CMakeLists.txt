cmake_minimum_required(VERSION 4.0)
project(sockets)

set(CMAKE_CXX_STANDARD 26)
include_directories(include/)


add_executable(server
        include/sockets/Command.hpp
        include/sockets/Echo.hpp

        src/Echo.cpp
        src/server.cpp
)

add_executable(client
        src/client.cpp
)