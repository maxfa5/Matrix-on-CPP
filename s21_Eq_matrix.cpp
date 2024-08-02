#include "s21_matrix_oop.h"

bool S21Matrix::Eq_matrix(const S21Matrix& other) noexcept {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs(other(i, j) - (*this)(i, j)) > ACCURACY) return false;
    }
  }
  return true;
}