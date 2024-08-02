#ifndef S21_MATRIXPLUS_TESTS
#define S21_MATRIXPLUS_TESTS

#include <gtest/gtest.h>

#define ACCURACY 1e-7

#include "../s21_matrix_oop.h"

S21Matrix GetIdentityMatrix(int size);

void CheckMatrix(const S21Matrix& matrix, double value);
void FillMatrix(S21Matrix& matrix, double value);
#endif  // S21_MATRIXPLUS_TESTS