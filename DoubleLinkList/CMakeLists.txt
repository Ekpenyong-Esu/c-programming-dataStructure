cmake_minimum_required(VERSION 3.23)
project(DoubleLinkList C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(DoubleLinkList
        DoubleLinkList.c
        DoubleLinkList.h
        DoubleLinkListFunction.c)
