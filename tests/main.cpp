
#include "../s21_matrix_oop.h"

void print_menu();
int scanf_new_struct(S21Matrix *A, FILE *src);
void input_value_to_matrix(S21Matrix *A);
int lenght_num(const char *str);
int printf_new_struct(S21Matrix *A, FILE *dst);

// void S21Matrix::print_value_of_matrix() {
//   int i = 0, j = 0;
//   for (; i < rows_; i++) {
//     for (j = 0; j < cols_; j++) {
//       cout << " [" << matrix_[i][j] << "] ";
//     }
//     cout <<"\n";
//   }
// }

 int main() {
  S21Matrix matrix1{2, 2};
  matrix1(0,0) = 1;
  matrix1(0,1) = 2;
  matrix1(1,0) = 3;
  matrix1(1,1) = 4;
  S21Matrix matrix2{2, 2};
  
  try
  {

    printf("%lf", matrix1.Determinant() );
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  
  return 0;
}
void print_menu() {
  printf(
      "Выберите функцию:\n1- Создание матрицы\n2- Сравнение матриц\n3- "
      "Сложение  матриц\n4- Умножение матрицы на число\n5- Умножение "
      "двух матриц \n6- Транспонирование матрицы\n7- Матрица алгебраических дополнений  "
      "\n8- Нахождение oпределителья матрицы с "
      "помощью метода Гаусса\n9- Обратная матрица \n11- Считать с "
      "файла\n12- Запись в файл\n13- Вычитание матриц\n10- Выход\n");
}

