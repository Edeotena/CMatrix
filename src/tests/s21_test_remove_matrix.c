#include "s21_test_matrix.h"

START_TEST(s21_remove_matrix_01) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = WR_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_02) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = WR_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_03) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = WR_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_04) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 4, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = WR_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_05) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = WR_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

Suite *suite_remove_matrix(void) {
  Suite *s = suite_create(BLUE "s21_remove_matrix" WHITE);
  TCase *tc = tcase_create("suite_remove_matrix");

  tcase_add_test(tc, s21_remove_matrix_01);
  tcase_add_test(tc, s21_remove_matrix_02);
  tcase_add_test(tc, s21_remove_matrix_03);
  tcase_add_test(tc, s21_remove_matrix_04);
  tcase_add_test(tc, s21_remove_matrix_05);

  suite_add_tcase(s, tc);
  return s;
}
