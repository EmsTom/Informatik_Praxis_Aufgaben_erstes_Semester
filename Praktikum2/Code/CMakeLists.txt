cmake_minimum_required(VERSION 4.0)
project(Code C)

set(CMAKE_C_STANDARD 11)

add_executable(Code main.c
        numberConvert.c
        numberConvert.h)
