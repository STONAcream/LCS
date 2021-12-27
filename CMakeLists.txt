cmake_minimum_required(VERSION 3.20)
project(LCS C)

set(CMAKE_C_STANDARD 99)



add_executable(LCS readfile.h readfile.c algorithm.c algorithm.h main.c matrice.c matrice.h library.h library.c)