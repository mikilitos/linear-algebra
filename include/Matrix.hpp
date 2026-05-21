#pragma once

#include <cstddef>
#include <vector>

class Matrix {

public:
  Matrix(std::vector<std::vector<float>> matrix);

  // TODO: Implement optimized matrix multiplication.
  Matrix operator*(const Matrix &otherMatrix) const;

  Matrix column_by_rows(const Matrix &otherMatrix) const;
  const std::vector<std::vector<float>> &matrix() const;

  Matrix permutation_rows_res(const std::vector<int> &order) const;

  Matrix permutation_cols_res(const std::vector<int> &order) const;

  Matrix permutation_rows(const std::vector<int> &order) const;

  Matrix permutation_cols(const std::vector<int> &order) const;

  void show_matrix() const;

  std::pair<size_t, size_t> matrix_size() const;
  std::size_t row_size() const;
  std::size_t column_size() const;

private:
  std::vector<std::vector<float>> matrix_;
};
