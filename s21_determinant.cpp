
#include "s21_matrix_oop.h"

void S21Matrix::swap_rows(int str1, int str2, S21Matrix& A) {
  for (int i = 0; i < A.cols_; i++) {
    double tmp = A.matrix_[str1][i];
    A.matrix_[str1][i] = A.matrix_[str2][i];
    A.matrix_[str2][i] = tmp;
  }
}

void S21Matrix::s21_sub_rows(S21Matrix& A, int minuend, int subtrahend,
                             double mul) {
  for (int i = 0; i < A.cols_; i++) {
    A.matrix_[minuend][i] -= A.matrix_[subtrahend][i] * mul;
  }
}
// 1 - под этим эллементом нулевые обьекты
int S21Matrix::check_null_under(const S21Matrix& A, int column, int row) {
  int code = 1;
  row++;
  for (; row < A.rows_ && code; row++) {
    if (A.matrix_[row][column]) code--;
  }
  return code;
}

void S21Matrix::to_triangle_form(S21Matrix& A) {
  int column = 0, row = 0;
  for (; column < A.cols_ && row < A.rows_; column++, row++) {
    if (!check_null_under(A, column, row)) {
      rows_to_null(A, row, column);
    }
  }
}

void S21Matrix::rows_to_null(S21Matrix& A, int start_row, int column) {
  int go_row = start_row + 1;
  double mul1 = A.matrix_[go_row][column] / A.matrix_[start_row][column];
  for (; go_row < A.rows_; go_row++) {
    mul1 = A.matrix_[go_row][column] / A.matrix_[start_row][column];
    s21_sub_rows(A, go_row, start_row, mul1);
  }
}

double S21Matrix::mul_diagonal(const S21Matrix& A) {
  double res = 1;
  for (int i = 0; i < A.rows_; i++) res *= A.matrix_[i][i];
  return res;
}

int S21Matrix::swap_zeros(S21Matrix& A, int sign, int column) {
  for (int i = 0; i < A.rows_; i++)
    if (A.matrix_[i][column] == 0) {
      swap_rows(i, not_null_str(A), A);
      sign *= (-1);
      break;
    }
  return sign;
}

int S21Matrix::not_null_str(const S21Matrix& A) {
  int result = 0;
  for (int i = 0; i < A.rows_; i++)
    if (A.matrix_[i][0] != 0) {
      result = i;
    }
  return result;
}

double S21Matrix::Determinant() {
  int sign = 1;
  double result = 0;
  S21Matrix A = S21Matrix(*this);
  if (A.cols_ == A.rows_) {
    for (int i = 0; !mul_diagonal(A) && i < A.rows_; i++) {
      sign = swap_zeros(A, sign, i);
    }

    double mul_daigoanl = mul_diagonal(A);
    if (!mul_daigoanl) { /*проверка на 0 на главной диагонали */
      result = 0;
    } else {
      to_triangle_form(A);
      result = mul_diagonal(A) * sign;
    }
  } else {
    throw logic_error("The matrix is ​​not square.");
  }
  return result;
}
