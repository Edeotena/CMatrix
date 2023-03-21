#include <stdlib.h>

#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL) {
    return CALC_ERR;
  }

  int code = create_matrix_from_two(A, B, result);
  if (code != OK) {
    return code;
  }

  make_every_val_from_two(A, B, result, sum_double);

  return OK;
}