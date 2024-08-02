#include "s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if ((rows_) != other.cols_ || cols_ != rows_)
    throw logic_error("Incorrect matrix size for Mul on matrix");
  S21Matrix result = S21Matrix(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  (*this).swap(result);
}