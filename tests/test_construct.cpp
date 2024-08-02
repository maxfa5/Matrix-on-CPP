#include "test.h"

TEST(TestConstructor, TestConstructorMove2) {
  S21Matrix matrix_test{14, 14};
  FillMatrix(matrix_test, 2.0);

  S21Matrix matrix_check = matrix_test;
  FillMatrix(matrix_test, 1.0);
  EXPECT_EQ(matrix_check.get_cols(), 14);
  EXPECT_EQ(matrix_check.get_rows(), 14);

  CheckMatrix(matrix_check, 2.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException1) {
  S21Matrix matrix_check{99, 99};
  EXPECT_ANY_THROW(matrix_check(100, 99));
  CheckMatrix(matrix_check, 0.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException2) {
  S21Matrix matrix_check{99, 99};
  EXPECT_ANY_THROW(matrix_check(99, 100));
  CheckMatrix(matrix_check, 0.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException3) {
  S21Matrix matrix_check{99, 99};
  EXPECT_ANY_THROW(matrix_check(100, 100));
  CheckMatrix(matrix_check, 0.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException4) {
  S21Matrix matrix_check{5, 5};
  FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(6, 5));
  CheckMatrix(matrix_check, 2.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException5) {
  S21Matrix matrix_check{5, 5};
  FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(5, 6));
  CheckMatrix(matrix_check, 2.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException6) {
  S21Matrix matrix_check{5, 5};
  FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(999, 999));
  CheckMatrix(matrix_check, 2.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException7) {
  S21Matrix matrix_check{5, 5};
  FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(1000, 0) == 1 ? 1 : 0);
  CheckMatrix(matrix_check, 2.0);
}
TEST(TestOperatorBrackets, TestOperatorBracketsException8) {
  S21Matrix matrix_check{5, 5};
  FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(1, 999));
  CheckMatrix(matrix_check, 2.0);
}
TEST(TestOperatorBrackets, TestOperatorBracketsException9) {
  S21Matrix matrix_check{5, 5};
  FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(-1, 999));
  CheckMatrix(matrix_check, 2.0);
}
TEST(TestOperatorBrackets, TestOperatorBracketsException10) {
  S21Matrix matrix_check{5, 5};
  FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(1, -1));
  CheckMatrix(matrix_check, 2.0);
}
TEST(TestOperatorBrackets, TestOperatorBracketsException11) {
  S21Matrix matrix_check{5, 5};
  FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(100, 100));
  CheckMatrix(matrix_check, 2.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException13) {
  S21Matrix matrix{5, 5};
  EXPECT_ANY_THROW(ASSERT_NEAR(matrix(555, 555), 0, ACCURACY));
}
TEST(MatrixTests, GetElementInRange) {
  S21Matrix mat(3, 3);  // Создаем матрицу 3x3
  mat(0, 0) = 1.0;  // Заполняем некоторые элементы
  mat(1, 1) = 2.0;
  mat(2, 2) = 3.0;

  EXPECT_DOUBLE_EQ(mat(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(mat(1, 1), 2.0);
  EXPECT_DOUBLE_EQ(mat(2, 2), 3.0);
}

TEST(MatrixTests, GetElementOutOfRange) {
  S21Matrix mat(3, 3);  // Создаем матрицу 3x3

  ASSERT_THROW(mat(-1, 0), std::logic_error);
  ASSERT_THROW(mat(3, 0), std::logic_error);
  ASSERT_THROW(mat(0, -1), std::logic_error);
  ASSERT_THROW(mat(0, 3), std::logic_error);
}

TEST(MatrixTests, GetElementNegativeIndex) {
  S21Matrix mat(3, 3);  // Создаем матрицу 3x3

  ASSERT_THROW(mat(-1, 0), std::logic_error);
  ASSERT_THROW(mat(0, -1), std::logic_error);
}

TEST(MatrixTests, AccessOutOfRangeThrowsException) {
  S21Matrix matrix(3, 3);  // Создаем матрицу 3x3

  ASSERT_THROW(matrix(-1, 0), std::out_of_range);
  ASSERT_THROW(matrix(3, 0), std::out_of_range);
  ASSERT_THROW(matrix(0, -1), std::out_of_range);
  ASSERT_THROW(matrix(0, 3), std::out_of_range);
}

TEST(MatrixTests, AccessThroughConstReference) {
  S21Matrix matrix(3, 3);  // Создаем матрицу 3x3
  matrix(0, 0) = 1.0;
  matrix(1, 1) = 2.0;
  matrix(2, 2) = 3.0;

  const S21Matrix& constMat = matrix;
  EXPECT_EQ(constMat(0, 0), 1.0);
  EXPECT_EQ(constMat(1, 1), 2.0);
  EXPECT_EQ(constMat(2, 2), 3.0);
}

TEST(MatrixTests, ModifyElements) {
  S21Matrix matrix(3, 3);  // Создаем матрицу 3x3
  matrix(0, 0) = 1.0;
  matrix(1, 1) = 2.0;
  matrix(2, 2) = 3.0;

  double& element = matrix(0, 0);
  element = 10.0;
  EXPECT_EQ(element, 10.0);
  EXPECT_EQ(matrix(0, 0), 10.0);
}
TEST(Init, Init_construct1_Test) {
  S21Matrix a = S21Matrix();
  EXPECT_EQ(a.get_rows(), 0);
  EXPECT_EQ(a.get_cols(), 0);
}
TEST(Init, Init_construct2_Test) {
  S21Matrix a = S21Matrix(1);
  EXPECT_EQ(a.get_rows(), 1);
  EXPECT_EQ(a.get_cols(), 1);
}
TEST(Init, Init_construct3_Test) {
  // Создаем временный объект S21Matrix и заполняем его данными
  S21Matrix tempMatrix(
      3, 3);  // Предполагается, что конструктор принимает размеры матрицы
  tempMatrix(0, 0) = 1.0;
  tempMatrix(1, 1) = 2.0;
  tempMatrix(2, 2) = 3.0;

  // Создаем новый объект S21Matrix с помощью перемещенного конструктора
  S21Matrix movedMatrix(std::move(tempMatrix));

  // Проверяем, что данные были успешно перемещены
  EXPECT_EQ(movedMatrix(0, 0), 1.0);
  EXPECT_EQ(movedMatrix(1, 1), 2.0);
  EXPECT_EQ(movedMatrix(2, 2), 3.0);
}