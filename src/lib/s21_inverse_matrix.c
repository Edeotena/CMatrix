#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (is_valid(A) != OK || result == NULL) {
    return result == NULL ? CALC_ERR : WR_MATRIX;
  }

  if (A->rows != A->columns) {
    return CALC_ERR;
  }

  double matrix_det = 0;
  int code = s21_determinant(A, &matrix_det);
  if (code != OK || fabs(matrix_det) <= EPS) {
    return code != OK ? code : CALC_ERR;
  }

  if (A->rows == 1) {
    if (s21_create_matrix(A->rows, A->columns, result) != OK) {
      return WR_MATRIX;
    }
    result->matrix[0][0] = 1 / A->matrix[0][0];
  } else {
    matrix_t adj = DEFAULT_MATRIX;
    code = s21_calc_complements(A, &adj);
    if (code != OK) {
      return code;
    }

    code = s21_mult_number(&adj, 1 / matrix_det, result);
    if (code != OK) {
      s21_remove_matrix(&adj);
      return code;
    }

    s21_remove_matrix(&adj);
  }

  return OK;
}