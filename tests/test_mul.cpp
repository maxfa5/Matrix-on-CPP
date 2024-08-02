#include "test.h"
TEST(TestMulMatrix, TestMulMatrixFunctionException0) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 3};

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
}
TEST(TestMulMatrix, TestMulMatrixFunctionException1) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException2) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * (matrix2));
  EXPECT_ANY_THROW(matrix2 * (matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException3) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException4) {
  S21Matrix matrix1{3, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException5) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{3, 2};

  FillMatrix(matrix1, 1.0);
  FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException6) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 3};

  FillMatrix(matrix1, 1.0);
  FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException7) {
  S21Matrix matrix1{3, 3};
  S21Matrix matrix2{2, 2};

  FillMatrix(matrix1, 1.0);
  FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException8) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 3};

  FillMatrix(matrix1, 1.0);
  FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestInverse, TestInverseZero11) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 2};

  FillMatrix(matrix1, 1.0);
  FillMatrix(matrix2, 2.0);

  S21Matrix result = matrix1;
  result(0, 0) = 3.0;
  result(0, 1) = 3.0;
  result(1, 0) = 3.0;
  result(1, 1) = 3.0;
  S21Matrix matrix3(matrix1 + matrix2);

  EXPECT_TRUE(matrix3 == result);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException10) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 2};
  matrix1(0, 0) = 2;
  matrix2(0, 0) = 2;

  matrix1 *= matrix2;
  EXPECT_NEAR(matrix1(0, 0), 4, ACCURACY);
}
TEST(TestMulMatrix, TestMulMatrixFunctionException11) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 2};
  matrix1(0, 0) = 2;
  matrix2(0, 0) = 2;

  matrix1 *= 2;
  EXPECT_NEAR(matrix1(0, 0), 4, ACCURACY);
}
TEST(TestMulMatrix, TestMulMatrixFunctionException12) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 2};
  matrix1(0, 0) = 2;
  matrix2(0, 0) = 2;

  matrix1 = 2. * matrix2;
  EXPECT_NEAR(matrix1(0, 0), 4, ACCURACY);
}