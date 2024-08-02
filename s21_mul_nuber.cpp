#include "s21_matrix_oop.h"

void S21Matrix::MulNumber(const double number) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] * number;
    }
  }
}