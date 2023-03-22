#include "s21_test_matrix.h"

int main() {
  Suite *suite[] = {
      suite_create_matrix(),    suite_remove_matrix(),  suite_eq_matrix(),
      suite_sum_matrix(),       suite_sub_matrix(),     suite_mult_number(),
      suite_mult_matrix(),      suite_transpose(),      suite_determinant(),
      suite_calc_complements(), suite_inverse_matrix(), NULL};

  for (Suite **count_suite = suite; *count_suite != NULL; count_suite++) {
    SRunner *suite_runner = srunner_create(*count_suite);

    srunner_run_all(suite_runner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    if (failed_count != 0)
      printf(RED "Failed\n" WHITE);
    else
      printf(GREEN "Success\n" WHITE);
  }

  return 0;
}

double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}