#include "Matrix.hpp"
#include <vector>

int main() {

  std::vector<std::vector<float>> matrix1 = {{1, 2, 3}, {4, 5, 2}};
  std::vector<std::vector<float>> matrix2 = {{2, 3}, {4, 5}, {1, 1}};

  Matrix myMatrix1(matrix1);
  Matrix myMatrix2(matrix2);

  Matrix product = myMatrix1.column_by_rows(myMatrix2);
  product.show_matrix();

  return 0;
}
