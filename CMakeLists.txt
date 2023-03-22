cmake_minimum_required(VERSION 3.24)
project(CMatrix C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(CMatrix
        src/lib/s21_create_matrix.c
        src/lib/s21_remove_matrix.c
        src/lib/s21_utils.c
        src/main.c
        src/s21_matrix.h
        src/lib/s21_sum_matrix.c
        src/lib/s21_sub_matrix.c
        src/lib/s21_eq_matrix.c
        src/lib/s21_mult_number.c
        src/lib/s21_mult_matrix.c
        src/lib/s21_transpose.c
        src/lib/s21_determinant.c
        src/lib/s21_calc_complements.c
        src/lib/s21_inverse_matrix.c)

add_executable(Test
        src/lib/s21_create_matrix.c
        src/lib/s21_remove_matrix.c
        src/lib/s21_utils.c
        src/s21_matrix.h
        src/lib/s21_sum_matrix.c
        src/lib/s21_sub_matrix.c
        src/lib/s21_eq_matrix.c
        src/lib/s21_mult_number.c
        src/lib/s21_mult_matrix.c
        src/lib/s21_transpose.c
        src/lib/s21_determinant.c
        src/lib/s21_calc_complements.c
        src/lib/s21_inverse_matrix.c
        src/tests/s21_test_calc_complements.c
        src/tests/s21_test_create_matrix.c
        src/tests/s21_test_determinant.c
        src/tests/s21_test_eq_matrix.c
        src/tests/s21_test_inverse_matrix.c
        src/tests/s21_test_matrix.c
        src/tests/s21_test_matrix.h
        src/tests/s21_test_mult_matrix.c
        src/tests/s21_test_mult_number.c
        src/tests/s21_test_remove_matrix.c
        src/tests/s21_test_sub_matrix.c
        src/tests/s21_test_sum_matrix.c
        src/tests/s21_test_transpose.c
        )

target_link_libraries(CMatrix m)

target_link_libraries(Test check m subunit)
