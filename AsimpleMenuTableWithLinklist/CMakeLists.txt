cmake_minimum_required(VERSION 3.23)
project(AsimpleMenuTableWithLinklist C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(AsimpleMenuTableWithLinklist
        MenuTable.c
        MenuTable.h)
