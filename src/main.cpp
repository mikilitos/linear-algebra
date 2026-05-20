#include "../include/Matrix.hpp"
#include <vector>

int main() {

  std::vector<std::vector<float>> matrix1 = {{1, 2, 3}, {4, 3, 2}};
  std::vector<std::vector<float>> matrix2 = {{3}, {2}, {1}};

  Matrix myMatrix1(matrix1);
  Matrix myMatrix2(matrix2);

  Matrix product = myMatrix1.column_by_rows(matrix2);
  product.show_matrix();

  return 0;
}
