cmake_minimum_required(VERSION 3.19)
project(untitled C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /execution-charset:SHIFT_JIS /source-charset:UTF-8")
set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c)
