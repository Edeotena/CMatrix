#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (is_valid(A) != OK || result == NULL) {
    return result == NULL ? CALC_ERR : WR_MATRIX;
  }

  if (s21_create_matrix(A->rows, A->columns, result) != OK) {
    return WR_MATRIX;
  }

  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return OK;
}