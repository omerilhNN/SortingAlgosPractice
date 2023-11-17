cmake_minimum_required(VERSION 3.26)
project(SortingAlgosPractice C)

set(CMAKE_C_STANDARD 11)

add_library(SortingAlgosPractice library.c
        SelectionSort.c
        BubbleSort.c
        test.c)
