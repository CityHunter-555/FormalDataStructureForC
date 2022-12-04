cmake_minimum_required(VERSION 3.23)
project(FormalDataStructure C)

set(CMAKE_C_STANDARD 99)

add_library(FormalDataStructure SHARED library.c src/source/sqlist.c src/head/sqlist.h src/source/Linear_List.c src/head/Linear_List.h src/source/slink.c src/head/slink.h src/source/AdjacentMatrix.c src/head/AdjacentMatrix.h src/source/CycleQuqne.c src/head/CycleQuqne.h src/source/AdjacentList.c src/head/AdjacentList.h)
