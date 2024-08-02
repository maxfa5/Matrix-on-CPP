#include "s21_matrix_oop.h"

bool S21Matrix::operator==(const S21Matrix& other) noexcept {
  return Eq_matrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) noexcept {
  if (this != &other) {
    S21Matrix temp{other};
    (*this).swap(temp);
  }

  return *this;
}

S21Matrix S21Matrix::operator*(double x) {
  S21Matrix temp{*this};

  temp.MulNumber(x);

  return temp;
}

S21Matrix S21Matrix::operator*(const S21Matrix& x) const {
  S21Matrix temp{*this};

  temp.MulMatrix(x);

  return temp;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& x) {
  this->SumMatrix(x);

  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& x) {
  this->SubMatrix(x);

  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& x) {
  this->MulMatrix(x);

  return *this;
}

S21Matrix& S21Matrix::operator*=(const double x) {
  this->MulNumber(x);

  return *this;
}

S21Matrix operator*(double number, const S21Matrix& matrix) noexcept {
  S21Matrix tmp = matrix;
  tmp.MulNumber(number);
  return tmp;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix temp{*this};

  temp.SumMatrix(other);

  return temp;
}
S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix temp{*this};

  temp.SubMatrix(other);

  return temp;
}

double& S21Matrix::operator()(int i, int j) & {
  return const_cast<double&>(GetMatrixElement(i, j));
}

const double& S21Matrix::operator()(int i, int j) const& {
  return GetMatrixElement(i, j);
}

const double& S21Matrix::GetMatrixElement(int i, int j) const {
  if (i >= 0 && i < rows_ && j >= 0 && j < cols_) {
    return (matrix_[i][j]);
  } else {
    throw std::out_of_range("Index out of range");
  }
}