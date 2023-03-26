#include "s21_test_matrix.h"

START_TEST(null_matrix) {
  matrix_t m = {0};
  m.columns = 1;
  m.rows = 1;
  matrix_t r;
  int code = s21_calc_complements(&m, &r);
  ck_assert_int_eq(code, WR_MATRIX);
}

START_TEST(test_one_by_one) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, CALC_ERR);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_incorrect) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, WR_MATRIX);
}
END_TEST

START_TEST(test_not_sqare) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(3, 4, &m);
  if (codec == OK) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, CALC_ERR);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_normal) {
  matrix_t expected = {0};
  matrix_t m = {0};
  matrix_t result = {0};
  int code1 = s21_create_matrix(3, 3, &m);
  int code2 = s21_create_matrix(3, 3, &expected);
  if (code1 && code2) {
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;

    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;

    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;

    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    int code = s21_calc_complements(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, OK);
  }
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(special_test_0) {
  matrix_t m = {0};
  s21_create_matrix(1, 1, &m);
  m.matrix[0][0] = 123;
  matrix_t r;
  int code = s21_calc_complements(&m, &r);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(r.columns, 1);
  ck_assert_int_eq(r.rows, 1);
  ck_assert_float_eq_tol(r.matrix[0][0], 0, 1e-6);
  s21_remove_matrix(&m);
  s21_remove_matrix(&r);
}
END_TEST

START_TEST(special_test_1) {
  int sizes[] = {3, 3};
  const double vals[] = {2, 2, 3, 4, 5, 6, 7, 8, 9};
  double res[] = {-3.000000, 6.000000,  -3.000000, 6.000000, -3.000000,
                  0.000000,  -3.000000, -2.000000, 2.000000};
  matrix_t m = DEFAULT_MATRIX, r = DEFAULT_MATRIX;
  s21_create_matrix(sizes[0], sizes[1], &m);
  for (int i = 0; i < m.rows; ++i) {
    for (int j = 0; j < m.columns; ++j) {
      m.matrix[i][j] = vals[i * m.columns + j];
    }
  }

  s21_calc_complements(&m, &r);
  ck_assert_int_eq(r.rows, sizes[0]);
  ck_assert_int_eq(r.rows, sizes[1]);

  for (int i = 0; i < r.rows; ++i) {
    for (int j = 0; j < r.columns; ++j) {
      ck_assert_double_eq_tol(r.matrix[i][j], res[i * r.columns + j], 1e-6);
    }
  }

  s21_remove_matrix(&m);
  s21_remove_matrix(&r);
}
END_TEST

START_TEST(special_test_2) {
  int sizes[] = {4, 4};
  const double vals[] = {-0.72, 1.85, -0.07, 2.64,  3.97, -0.04, 4.71,  -1.34,
                         1.49,  1.22, -0.57, -4.54, 0.41, -1.96, -0.65, 4.84};
  double res[] = {16.887916, 15.815610, 64.804654,  55.954948,
                  64.417104, 2.806294,  26.313418,  -9.677232,
                  -6.938068, 23.660042, -55.032442, -41.286432,
                  23.723912, 2.974166,  -2.224524,  20.947118};
  matrix_t m = DEFAULT_MATRIX, r = DEFAULT_MATRIX;
  s21_create_matrix(sizes[0], sizes[1], &m);
  for (int i = 0; i < m.rows; ++i) {
    for (int j = 0; j < m.columns; ++j) {
      m.matrix[i][j] = vals[i * m.columns + j];
    }
  }

  s21_calc_complements(&m, &r);
  ck_assert_int_eq(r.rows, sizes[0]);
  ck_assert_int_eq(r.rows, sizes[1]);

  for (int i = 0; i < r.rows; ++i) {
    for (int j = 0; j < r.columns; ++j) {
      ck_assert_double_eq_tol(r.matrix[i][j], res[i * r.columns + j], 1e-6);
    }
  }

  s21_remove_matrix(&m);
  s21_remove_matrix(&r);
}
END_TEST

START_TEST(special_test_3) {
  int sizes[] = {5, 5};
  const double vals[] = {
      -584.790000, -852.810000, 0.000000,    0.000000,    0.000000,
      -524.190000, -908.600000, -406.610000, -41.120000,  0.000000,
      -578.940000, -963.950000, 0.000000,    0.000000,    -111.910000,
      -548.940000, -142.350000, -782.520000, -646.370000, 0.000000,
      -328.560000, 0.000000,    -12.260000,  0.000000,    0.000000};
  double res[] = {-797743068.076610,
                  756297807.619675,
                  0.000000,
                  -48113256.879684,
                  -22012126083.421379,
                  -8046659501.441475,
                  -518609531.921424,
                  -0.000000,
                  32992286.078576,
                  15094184182.085093,
                  21378993674.327156,
                  -20268287738.296932,
                  0.000000,
                  1289403889.101861,
                  -7869470818.588642,
                  -23432608367.056519,
                  24009472081.511185,
                  -0.000000,
                  -12865778656.491737,
                  24897036803.805099,
                  73437787492.152466,
                  554576048.184453,
                  -65488194604.636108,
                  -35280361.250282,
                  -16140993365.963287};
  matrix_t m = DEFAULT_MATRIX, r = DEFAULT_MATRIX;
  s21_create_matrix(sizes[0], sizes[1], &m);
  for (int i = 0; i < m.rows; ++i) {
    for (int j = 0; j < m.columns; ++j) {
      m.matrix[i][j] = vals[i * m.columns + j];
    }
  }

  s21_calc_complements(&m, &r);
  ck_assert_int_eq(r.rows, sizes[0]);
  ck_assert_int_eq(r.rows, sizes[1]);

  for (int i = 0; i < r.rows; ++i) {
    for (int j = 0; j < r.columns; ++j) {
      ck_assert_double_eq_tol(r.matrix[i][j], res[i * r.columns + j], 1e-6);
    }
  }

  s21_remove_matrix(&m);
  s21_remove_matrix(&r);
}
END_TEST

START_TEST(special_test_4) {
  int sizes[] = {6, 6};
  const double vals[] = {
      -38.16, -88.77, -0.4,   -38.41, -43.34, -0.08,   1., 0.,    -68.74,
      0.,     -0.14,  0.,     0.,     0.,     -405.31, 0., -0.19, -31.93,
      0.,     -0.58,  -0.91,  -0.73,  0.,     -0.79,   0., 0.,    0.,
      0.,     0.,     -42.52, 0.,     0.,     -0.07,   0., 0.,    0.};
  double res[] = {0.,
                  24.048172038800022,
                  -17.719705712800003,
                  0.,
                  13.306448810200001,
                  78984.32252154079,
                  -0.4128266800000005,
                  -15.753466108800016,
                  105.77575561280013,
                  21.721469560000024,
                  -79.83412068520009,
                  -597266.8521961814,
                  0.,
                  0.,
                  0.,
                  0.,
                  0.,
                  -343.54531484000023,
                  0.3279992800000004,
                  12.516452524800012,
                  -84.04101130880008,
                  -50.20085532000005,
                  64.04190796920005,
                  474969.0417949172,
                  0.,
                  0.,
                  -126.5693265200001,
                  0.,
                  95.04606293000008,
                  732854.4818831605,
                  0.,
                  0.,
                  0.,
                  0.,
                  -0.5655731900000005,
                  0.};
  matrix_t m = DEFAULT_MATRIX, r = DEFAULT_MATRIX;
  s21_create_matrix(sizes[0], sizes[1], &m);
  for (int i = 0; i < m.rows; ++i) {
    for (int j = 0; j < m.columns; ++j) {
      m.matrix[i][j] = vals[i * m.columns + j];
    }
  }

  s21_calc_complements(&m, &r);
  ck_assert_int_eq(r.rows, sizes[0]);
  ck_assert_int_eq(r.rows, sizes[1]);

  for (int i = 0; i < r.rows; ++i) {
    for (int j = 0; j < r.columns; ++j) {
      ck_assert_double_eq_tol(r.matrix[i][j], res[i * r.columns + j], 1e-6);
    }
  }

  s21_remove_matrix(&m);
  s21_remove_matrix(&r);
}
END_TEST

START_TEST(special_test_5) {
  int sizes[] = {4, 4};
  const double vals[] = {-823.490000, -987.440000, -168.630000, -576.490000,
                         -238.800000, 0.000000,    -773.090000, -546.200000,
                         -768.000000, -285.560000, 0.000000,    0.000000,
                         -933.730000, -114.630000, -288.150000, -297.640000};
  double res[] = {
      20764489.003456,   33103417.439268,   -31271610.440641,
      -100966291.059436, -55845102.796800,  -89030062.310400,
      -242578826.925949, 271544024.140800,  77254788.042640,
      -258685858.084396, -397635149.258980, 325082660.015440,
      -118424503.958092, 180876871.670784,  576483738.765745,
      -415978402.281844,
  };
  matrix_t m = DEFAULT_MATRIX, r = DEFAULT_MATRIX;
  s21_create_matrix(sizes[0], sizes[1], &m);
  for (int i = 0; i < m.rows; ++i) {
    for (int j = 0; j < m.columns; ++j) {
      m.matrix[i][j] = vals[i * m.columns + j];
    }
  }

  s21_calc_complements(&m, &r);
  ck_assert_int_eq(r.rows, sizes[0]);
  ck_assert_int_eq(r.rows, sizes[1]);

  for (int i = 0; i < r.rows; ++i) {
    for (int j = 0; j < r.columns; ++j) {
      ck_assert_double_eq_tol(r.matrix[i][j], res[i * r.columns + j], 1e-6);
    }
  }
  s21_remove_matrix(&m);
  s21_remove_matrix(&r);
}
END_TEST

Suite *suite_calc_complements(void) {
  Suite *s = suite_create(BLUE "s21_calc_complements" WHITE);
  TCase *tc = tcase_create("case_calc_complements");

  tcase_add_test(tc, test_normal);
  tcase_add_test(tc, test_not_sqare);
  tcase_add_test(tc, test_incorrect);
  tcase_add_test(tc, test_one_by_one);
  tcase_add_test(tc, special_test_0);
  tcase_add_test(tc, special_test_1);
  tcase_add_test(tc, special_test_2);
  tcase_add_test(tc, special_test_3);
  tcase_add_test(tc, special_test_4);
  tcase_add_test(tc, null_matrix);
  tcase_add_test(tc, special_test_5);

  suite_add_tcase(s, tc);
  return s;
}