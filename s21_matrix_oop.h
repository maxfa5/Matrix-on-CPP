#ifndef s21_matrix_oop
#define s21_matrix_oop

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

#define ACCURACY 1e-7

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated

  const double& GetMatrixElement(int i, int j) const;
  int not_null_str(const S21Matrix& A);
  void s21_sub_rows(S21Matrix& A, int minuend, int subtrahend, double mul);
  int swap_zeros(S21Matrix& A, int sign, int column);
  double mul_diagonal(const S21Matrix& A);
  void rows_to_null(S21Matrix& A, int start_row, int column);
  void to_triangle_form(S21Matrix& A);
  int check_null_under(const S21Matrix& A, int column, int row);
  void swap_rows(int str1, int str2, S21Matrix& A);
  void s21_create_matrix(int rows, int columns);
  double minor(const S21Matrix A, int row, int column);

 public:
  S21Matrix() noexcept;
  S21Matrix(int n) noexcept;
  S21Matrix(int rows, int cols) noexcept;
  ~S21Matrix() noexcept;
  S21Matrix(const S21Matrix& other) noexcept;  // конструктор копирования
  S21Matrix(S21Matrix&& other) noexcept;  // конструктор перемещения

  S21Matrix operator*(const S21Matrix& x) const;
  S21Matrix operator*(double x);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  double& operator()(int i, int j) &;
  const double& operator()(int i, int j) const&;
  bool operator==(const S21Matrix& other) noexcept;
  S21Matrix& operator=(const S21Matrix& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& x);
  S21Matrix& operator-=(const S21Matrix& x);
  S21Matrix& operator*=(const S21Matrix& x);
  S21Matrix& operator*=(const double x);
  friend S21Matrix operator*(double number, const S21Matrix& matrix) noexcept;

  bool Eq_matrix(const S21Matrix& other) noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() noexcept;
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  int get_cols() const noexcept;
  int get_rows() const noexcept;
  void set_rows(int new_rows);
  void set_cols(int new_cols);

  void set(double* nums, S21Matrix& A);
  void TestInverse(S21Matrix& matrix);
  void swap(S21Matrix& other) noexcept;
};
#endif  // s21_matrix_oop`