#include <stdlib.h>

#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL) {
    return CALC_ERR;
  }

  return OK;
}