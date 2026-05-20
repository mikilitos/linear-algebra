#pragma once

#include <cstddef>
#include <vector>

class Matrix {

public:
  Matrix(std::vector<std::vector<float>> matrix);

  // TODO: Implement optimized matrix multiplication.
  Matrix operator*(const Matrix &otherMatrix) const;

  std::vector<std::vector<float>>
  column_by_rows(const Matrix &otherMatrix) const;
  const std::vector<std::vector<float>> &matrix() const;

  void show_matrix() const;

  std::pair<size_t, size_t> matrix_size() const;
  std::size_t row_size() const;
  std::size_t column_size() const;

private:
  std::vector<std::vector<float>> matrix_;
};
