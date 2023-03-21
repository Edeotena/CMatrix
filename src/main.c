#include "s21_matrix.h"

int main() {
  matrix_t a;
  int code = s21_create_matrix(20, 15, &a);
  if (code == OK) {
    s21_remove_matrix(&a);
  }
}