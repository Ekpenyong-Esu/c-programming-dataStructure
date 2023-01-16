cmake_minimum_required(VERSION 3.23)
project(c_programming_dataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(arrayDelete)
include_directories(arrayInsert)
include_directories(AsimpleMenuTableWithLinklist)
include_directories(linklist)
include_directories(Recursion)

add_executable(c_programming_dataStructure
        arrayDelete/array.c
        arrayDelete/main.c
        arrayDelete/main.h
        arrayInsert/arrayInsert.c
        arrayInsert/main.c
        arrayInsert/main.h
        AsimpleMenuTableWithLinklist/MenuTable.c
        AsimpleMenuTableWithLinklist/MenuTable.h
        BinarySearch/BinarySearch.c
        CombinningTwoSortedArrays/arrayCombine.c
        ConcatenatingTwoStruct/concatenatingTwoStruct.c
        insertionSort/insertionSort.c
        LinearSearch/linearSearch.c
        linklist/linkList.c
        linklist/linkList.h
        linklist/simplelink2.c
        linklist/simpleLinkList.c
        patternMartching/patternMatching.c
        Recursion/headRecursion.c
        Recursion/main.c
        Recursion/main.h
        ReverseArray/ReverseArray.c
        selectionSort/selectionSort.c
        SetAndGetIndex/SetAndGetIndex.c
        SortingLinkList/sortingLinkList.c)
