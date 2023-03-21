cmake_minimum_required(VERSION 3.24)
project(CMatrix C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(CMatrix
        src/lib/s21_create_matrix.c
        src/lib/s21_remove_matrix.c
        src/lib/s21_utils.c
        src/main.c
        src/s21_matrix.h)
