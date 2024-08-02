#include "test.h"

TEST(TestOperatorBrackets, TestOperatorBrackets1) {
  S21Matrix matrix_check{3, 3};
  EXPECT_EQ(matrix_check.get_rows(), 3);
  EXPECT_EQ(matrix_check.get_cols(), 3);

  ASSERT_NEAR(matrix_check(0, 0), 0.0, ACCURACY);
  ASSERT_NEAR(matrix_check(0, 1), 0.0, ACCURACY);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, ACCURACY);
  ASSERT_NEAR(matrix_check(1, 0), 0.0, ACCURACY);
  ASSERT_NEAR(matrix_check(1, 1), 0.0, ACCURACY);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, ACCURACY);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, ACCURACY);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, ACCURACY);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, ACCURACY);

  matrix_check(0, 0) = 1.0;
  matrix_check(0, 1) = 2.0;
  matrix_check(1, 0) = 3.0;
  matrix_check(1, 1) = 4.0;

  ASSERT_NEAR(matrix_check(0, 0), 1.0, ACCURACY);
  ASSERT_NEAR(matrix_check(0, 1), 2.0, ACCURACY);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, ACCURACY);
  ASSERT_NEAR(matrix_check(1, 0), 3.0, ACCURACY);
  ASSERT_NEAR(matrix_check(1, 1), 4.0, ACCURACY);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, ACCURACY);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, ACCURACY);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, ACCURACY);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, ACCURACY);
}

TEST(TestMutators, TestMutatorsException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.set_rows(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException2) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.set_rows(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException3) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.set_cols(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException4) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.set_cols(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException5) {
  S21Matrix test_matrix(2, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.set_cols(-9999));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException6) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.set_cols(-9999));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutators1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 1);

  FillMatrix(matrix1, 5.5);
  matrix1.set_rows(2);

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 1);

  EXPECT_NEAR(matrix1(0, 0), 5.5, ACCURACY);
  EXPECT_NEAR(matrix1(1, 0), 0.0, ACCURACY);
}

TEST(TestMutators, TestMutators2) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 1);

  FillMatrix(matrix1, 5.5);
  matrix1.set_cols(2);

  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 2);

  EXPECT_NEAR(matrix1(0, 0), 5.5, ACCURACY);
  EXPECT_NEAR(matrix1(0, 1), 0.0, ACCURACY);
}

TEST(TestMutators, TestMutators3) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 1);

  FillMatrix(matrix1, 5.5);
  matrix1.set_rows(1);

  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 1);

  EXPECT_NEAR(matrix1(0, 0), 5.5, ACCURACY);
}

TEST(TestMutators, TestMutators4) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 1);

  FillMatrix(matrix1, 5.5);
  matrix1.set_cols(1);

  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 1);

  EXPECT_NEAR(matrix1(0, 0), 5.5, ACCURACY);
}

TEST(TestMutators, TestMutators5) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  FillMatrix(matrix1, 5.5);
  matrix1.set_rows(1);

  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 2);

  EXPECT_NEAR(matrix1(0, 0), 5.5, ACCURACY);
  EXPECT_NEAR(matrix1(0, 1), 5.5, ACCURACY);
}

TEST(TestMutators, TestMutators6) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  FillMatrix(matrix1, 5.5);
  matrix1.set_cols(1);

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 1);

  EXPECT_NEAR(matrix1(0, 0), 5.5, ACCURACY);
  EXPECT_NEAR(matrix1(1, 0), 5.5, ACCURACY);
}

TEST(TestMutators, TestMutators7) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  FillMatrix(matrix1, 5.5);
  matrix1.set_rows(2);
  matrix1.set_cols(2);

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  EXPECT_NEAR(matrix1(0, 0), 5.5, ACCURACY);
  EXPECT_NEAR(matrix1(0, 1), 5.5, ACCURACY);
  EXPECT_NEAR(matrix1(1, 0), 5.5, ACCURACY);
  EXPECT_NEAR(matrix1(1, 1), 5.5, ACCURACY);
}

TEST(TestMutators, TestMutators8) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1.set_rows(1);

  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 2);

  EXPECT_NEAR(matrix1(0, 0), 1, ACCURACY);
  EXPECT_NEAR(matrix1(0, 1), 2, ACCURACY);
}

TEST(TestMutators, TestMutators9) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1.set_cols(1);

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 1);

  EXPECT_NEAR(matrix1(0, 0), 1, ACCURACY);
  EXPECT_NEAR(matrix1(1, 0), 3, ACCURACY);
}

TEST(TestMutators, TestMutators10) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1.set_rows(3);

  EXPECT_EQ(matrix1.get_rows(), 3);
  EXPECT_EQ(matrix1.get_cols(), 2);

  EXPECT_NEAR(matrix1(0, 0), 1, ACCURACY);
  EXPECT_NEAR(matrix1(0, 1), 2, ACCURACY);
  EXPECT_NEAR(matrix1(1, 0), 3, ACCURACY);
  EXPECT_NEAR(matrix1(1, 1), 4, ACCURACY);
  EXPECT_NEAR(matrix1(2, 0), 0, ACCURACY);
  EXPECT_NEAR(matrix1(2, 1), 0, ACCURACY);
}

TEST(TestMutators, TestMutators11) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1.set_cols(3);

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 3);

  EXPECT_NEAR(matrix1(0, 0), 1, ACCURACY);
  EXPECT_NEAR(matrix1(0, 1), 2, ACCURACY);
  EXPECT_NEAR(matrix1(0, 2), 0, ACCURACY);
  EXPECT_NEAR(matrix1(1, 0), 3, ACCURACY);
  EXPECT_NEAR(matrix1(1, 1), 4, ACCURACY);
  EXPECT_NEAR(matrix1(1, 2), 0, ACCURACY);
}
