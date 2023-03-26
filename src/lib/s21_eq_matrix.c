#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (is_valid(A) != OK || is_valid(B) != OK) {
    return FAILURE;
  }

  if (A->rows != B->rows || A->columns != B->columns) {
    return FAILURE;
  }

  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= EPS) {
        return FAILURE;
      }
    }
  }

  return SUCCESS;
}