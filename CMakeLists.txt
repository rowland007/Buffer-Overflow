cmake_minimum_required(VERSION 3.19)
project(Buffer_Overflow)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES source/BufferOverflow.cpp)

add_executable(Buffer_Overflow source/BufferOverflow.cpp)