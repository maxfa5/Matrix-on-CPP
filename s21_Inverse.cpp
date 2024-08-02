
#include "s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();

  if (fabs(det) < ACCURACY || isnan(det)) {
    throw logic_error("Determinant must be non-zero to calculate Inverse");
  }
  return Transpose().CalcComplements() * (1.0 / det);
}