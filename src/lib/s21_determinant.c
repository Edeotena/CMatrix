#include <stdio.h>

#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (is_valid(A) != OK || result == NULL) {
    return result == NULL ? CALC_ERR : WR_MATRIX;
  }

  if (A->rows != A->columns) {
    return CALC_ERR;
  }

  int det_power = 1;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else {
    matrix_t cp_matrix = DEFAULT_MATRIX;

    for (int i = 0; i < A->columns; ++i) {
      int code = less_matrix(A, &cp_matrix, 0, i);
      if (code != OK) {
        return code;
      }

      double temp = 0;
      code = s21_determinant(&cp_matrix, &temp);
      if (code != OK) {
        s21_remove_matrix(&cp_matrix);
        return code;
      }

      *result = *result + det_power * A->matrix[0][i] * temp;

      det_power = -det_power;

      s21_remove_matrix(&cp_matrix);
    }
  }

  return OK;
}
