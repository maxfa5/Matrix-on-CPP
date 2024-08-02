#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept : rows_{}, cols_{}, matrix_{} {}

S21Matrix::S21Matrix(int rows, int cols) noexcept
    : rows_{rows}, cols_{cols}, matrix_{} {
  s21_create_matrix(rows, cols);
}
S21Matrix::S21Matrix(int n) noexcept : S21Matrix(n, n) {}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) delete[] matrix_[i];
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}
void S21Matrix::s21_create_matrix(int rows, int columns) {
  int i = 0;

  matrix_ = new double*[rows];

  for (; i < rows; i++) matrix_[i] = new double[columns]();
}

S21Matrix::S21Matrix(const S21Matrix& other) noexcept
    : rows_{other.rows_}, cols_{other.cols_}, matrix_{} {
  s21_create_matrix(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}
S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_{other.rows_}, cols_{other.cols_}, matrix_{other.matrix_} {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

int S21Matrix::get_cols() const noexcept { return cols_; }
int S21Matrix::get_rows() const noexcept { return rows_; }

void S21Matrix::set_rows(int new_rows) {
  if (new_rows < 0) {
    throw length_error("matrix rows can`t be non-negative");
  }
  if (new_rows != rows_) {
    S21Matrix tmp{new_rows, cols_};
    int min_rows = min(rows_, new_rows);
    for (int i = 0; i < min_rows; i++) {
      for (int j = 0; j < cols_; j++) {
        tmp.matrix_[i][j] = this->matrix_[i][j];
      }
    }

    tmp.swap(*this);
  }
}

void S21Matrix::set_cols(int new_cols) {
  if (new_cols < 0) {
    throw length_error("matrix cols can`t be non-negative");
  }
  if (new_cols != cols_) {
    S21Matrix tmp{rows_, new_cols};
    int min_cols = min(cols_, new_cols);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < min_cols; j++) {
        tmp.matrix_[i][j] = matrix_[i][j];
      }
    }
    tmp.swap(*this);
  }
}

void S21Matrix::swap(S21Matrix& other) noexcept {
  std::swap(matrix_, other.matrix_);
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
}