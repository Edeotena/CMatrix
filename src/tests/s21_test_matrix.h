#ifndef S21_TEST_MATRIX_H_
#define S21_TEST_MATRIX_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define BLUE "\x1B[36m"
#define WHITE "\x1B[0m"

Suite *suite_create_matrix(void);
Suite *suite_remove_matrix(void);
Suite *suite_eq_matrix(void);

Suite *suite_sum_matrix(void);
Suite *suite_sub_matrix(void);
Suite *suite_mult_number(void);
Suite *suite_mult_matrix(void);

Suite *suite_transpose(void);
Suite *suite_calc_complements(void);
Suite *suite_determinant(void);
Suite *suite_inverse_matrix(void);

double get_rand(double min, double max);

#endif  // S21_TEST_MATRIX_H_