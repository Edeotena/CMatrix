#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  nfree_matrix(A, A->rows);
  A->rows = 0;
  A->columns = 0;
}