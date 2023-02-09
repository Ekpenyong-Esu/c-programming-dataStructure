cmake_minimum_required(VERSION 3.23)
project(CircularHeaderLinkList C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CircularHeaderLinkList
        CircularHeaderLinkList.c
        CircularHeaderLinkList.h)
