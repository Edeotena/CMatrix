#include <stdlib.h>

#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL) {
    return CALC_ERR;
  }

  if (A->columns != B->rows) {
    return CALC_ERR;
  }

  if (s21_create_matrix(A->rows, B->columns, result) != OK) {
    return WR_MATRIX;
  }

  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      double val = 0;
      for (int k = 0; k < A->columns; ++k) {
        val += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return OK;
}