#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (is_valid(A) != OK || result == NULL) {
    return result == NULL ? CALC_ERR : WR_MATRIX;
  }

  if (s21_create_matrix(A->columns, A->rows, result) != OK) {
    return WR_MATRIX;
  }

  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }

  return OK;
}