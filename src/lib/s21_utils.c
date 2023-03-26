#include "../s21_matrix.h"

void nfree_matrix(matrix_t *mx, int n) {
  if (mx == NULL || mx->matrix == NULL) {
    return;
  }

  for (int i = 0; i < n; ++i) {
    free(mx->matrix[i]);
  }
  free(mx->matrix);
  mx->matrix = NULL;
}

int create_matrix_from_two(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (is_valid(A) != OK || is_valid(B) != OK || result == NULL) {
    return result == NULL ? CALC_ERR : WR_MATRIX;
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
  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      result->matrix[i][j] = act(A->matrix[i][j], B->matrix[i][j]);
    }
  }
}

double sum_double(double a, double b) { return a + b; }

double sub_double(double a, double b) { return a - b; }

int less_matrix(matrix_t *matrix, matrix_t *result, int row_to_skip,
                int col_to_skip) {
  int code = s21_create_matrix(matrix->rows - 1, matrix->columns - 1, result);
  if (code != OK) {
    return code;
  }

  int skip_i = 0;
  for (int i = 0; i < matrix->rows - 1; ++i) {
    if (i == row_to_skip) {
      skip_i = 1;
    }
    int skip_j = 0;
    for (int j = 0; j < matrix->columns - 1; ++j) {
      if (j == col_to_skip) {
        skip_j = 1;
      }
      result->matrix[i][j] = matrix->matrix[i + skip_i][j + skip_j];
    }
  }

  return OK;
}

int is_valid(matrix_t *A) {
  if (A == NULL || A->matrix == NULL || A->columns < 1 || A->rows < 1) {
    return WR_MATRIX;
  }

  return OK;
}
