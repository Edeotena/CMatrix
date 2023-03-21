#include <stdlib.h>

#include "../s21_matrix.h"

void nfree_matrix(matrix_t *mx, int n) {
  if (mx == NULL) {
    return;
  }

  for (int i = 0; i < n; ++i) {
    free(mx->matrix[i]);
  }
  free(mx->matrix);
}

int create_matrix_from_two(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (result == NULL) {
    return WR_MATRIX;
  }

  if (A->rows != B->rows || A->columns != B->columns) {
    return CALC_ERR;
  }

  if (s21_create_matrix(A->rows, A->columns, result) != OK) {
    return WR_MATRIX;
  }

  return OK;
}

void make_every_val_from_two(matrix_t *A, matrix_t *B, matrix_t *result,
                             double act(double, double)) {
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      result->matrix[i][j] = act(A->matrix[i][j], B->matrix[i][j]);
    }
  }
}

double sum_double(double a, double b) { return a + b; }

double sub_double(double a, double b) { return a - b; }