cmake_minimum_required(VERSION 3.12)
project(student_huff)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(student_huff
        bitfile.c
        bitfile.h
        huff.c
        huff.h
        main.c
        )
