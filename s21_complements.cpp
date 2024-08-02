#include "s21_matrix_oop.h"

double S21Matrix::minor(const S21Matrix A, int row, int column) {
  double det = 0;
  int rows = A.get_rows(), cols = A.get_cols();
  S21Matrix result(rows - 1, cols - 1);
  int k = 0;
  for (int i = 0; i < rows; i++) {
    if (i == row) continue;
    for (int j = 0, l = 0; j < cols; j++) {
      if (j == column) continue;
      result.matrix_[k][l] = A.matrix_[i][j];
      l++;
    }
    k++;
  }
  det = result.Determinant();
  return det;
}

S21Matrix S21Matrix::CalcComplements() {
  int rows = rows_, cols = cols_;
  if (rows != cols) throw logic_error("The matrix is ​​not square.");

  S21Matrix result(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int sign = ((i + j) % 2) ? -1 : 1;
      result.matrix_[i][j] = minor(*this, i, j) * sign;
    }
  }
  return result;
}
