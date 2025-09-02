cmake_minimum_required(VERSION 4.0)
project(sockets CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/)
include_directories(${CMAKE_SOURCE_DIR}/include/)


add_executable(server
        include/sockets/Command.hpp
        include/sockets/Echo.hpp
        include/sockets/Append.hpp

        src/Append.cpp
        src/Echo.cpp
        src/server.cpp
)

add_executable(client
        src/client.cpp
)

