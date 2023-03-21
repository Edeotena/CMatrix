#include <stdlib.h>

#include "../s21_matrix.h"

void nfree_matrix(matrix_t* mx, int n) {
  for (int i = 0; i < n; ++i) {
    free(mx->matrix[i]);
  }
  free(mx->matrix);
}