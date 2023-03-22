#ifndef CMATRIX_S21_MATRIX_H
#define CMATRIX_S21_MATRIX_H

#define EPS 1e-7
#define DEFAULT_MATRIX \
  { 0 }

#define OK 0
#define WR_MATRIX 1
#define CALC_ERR 2

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// utils
void nfree_matrix(matrix_t *mx, int n);
int create_matrix_from_two(matrix_t *A, matrix_t *B, matrix_t *result);
void make_every_val_from_two(matrix_t *A, matrix_t *B, matrix_t *result,
                             double act(double, double));
double sum_double(double a, double b);
double sub_double(double a, double b);
int less_matrix(matrix_t *matrix, matrix_t *result, int row_to_skip,
                int col_to_skip);
int is_valid(matrix_t *A);

#endif  // CMATRIX_S21_MATRIX_H
