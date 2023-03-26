#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A->rows != A->columns) {
    return CALC_ERR;
  }

  if (is_valid(A) != OK ||
      s21_create_matrix(A->rows, A->columns, result) != OK) {
    return WR_MATRIX;
  }

  if (result->rows == 1) {
    result->matrix[0][0] = 0;
    return OK;
  }

  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      matrix_t small_matrix = DEFAULT_MATRIX;
      int code = less_matrix(A, &small_matrix, j, i);
      if (code != OK) {
        s21_remove_matrix(result);
        return code;
      }

      double det = 0;
      code = s21_determinant(&small_matrix, &det);
      if (code != OK) {
        s21_remove_matrix(&small_matrix);
        s21_remove_matrix(result);
        return code;
      }
      s21_remove_matrix(&small_matrix);
      result->matrix[i][j] = (i + j) % 2 == 0 ? det : -det;
    }
  }

  return OK;
}