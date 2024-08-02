#include "test.h"

S21Matrix GetIdentityMatrix(int size) {
  S21Matrix result{size, size};

  for (int i = 0; i < result.get_rows(); i++) {
    for (int j = 0; j < result.get_cols(); j++) {
      if (i == j) {
        result(i, j) = 1.0;
      }
    }
  }

  return result;
}

void S21Matrix::TestInverse(S21Matrix& matrix) {
  S21Matrix matrix_before = matrix;
  double det = matrix.Determinant();
  if (fabs(det) < ACCURACY) {
    EXPECT_ANY_THROW(matrix.InverseMatrix());
  } else {
    S21Matrix matrix_inverse = matrix.InverseMatrix();
    S21Matrix matrix_mult = matrix * matrix_inverse;
    S21Matrix matrix_identity = GetIdentityMatrix(matrix.get_rows());

    EXPECT_TRUE(matrix_mult == matrix_identity);
  }
  EXPECT_TRUE(matrix == matrix_before);
}

void S21Matrix::set(double* nums, S21Matrix& A) {
  int count = 0;
  for (int i = 0; i < A.rows_; i++) {
    for (int j = 0; j < A.cols_; j++) {
      A.matrix_[i][j] = nums[count++];
    }
  }
}

void FillMatrix(S21Matrix& matrix, double value) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      matrix(i, j) = value;
    }
  }
}

void CheckMatrix(const S21Matrix& matrix, double value) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      ASSERT_NEAR(matrix(i, j), value, ACCURACY);
    }
  }
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}