
#include "test.h"

TEST(TestDeterminant, TestDeterminantException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException2) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException3) {
  S21Matrix test_matrix(55, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException4) {
  S21Matrix test_matrix(3, 55);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}