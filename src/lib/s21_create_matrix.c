#include <stdlib.h>

#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL) {
    return WR_MATRIX;
  }

  if (rows < 1 || columns < 1) {
    return WR_MATRIX;
  }

  result->columns = columns;
  result->rows = rows;

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) {
    return WR_MATRIX;
  }

  for (int i = 0; i < rows; ++i) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double *));
    if (result->matrix[i] == NULL) {
      nfree_matrix(result, i);
      return WR_MATRIX;
    }
  }

  return OK;
}