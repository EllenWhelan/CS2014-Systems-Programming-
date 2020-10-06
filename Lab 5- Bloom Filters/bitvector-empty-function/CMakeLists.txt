cmake_minimum_required(VERSION 3.12)
project(bitvector_empty_function)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bitvector_empty_function
        bitset.c
        bitset.h
        bloom.c
        bloom.h
        input1.txt
        input2.txt
        main.c
        Makefile
        runtest
        test_out1
        test_out2)
