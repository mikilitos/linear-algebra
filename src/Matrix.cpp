// TODO
#include "Matrix.hpp"

#include <iostream>
#include <stdexcept>
#include <unordered_set>

Matrix::Matrix(std::vector<std::vector<float>> matrix)
    : matrix_(std::move(matrix)) {
  if (matrix_.size() < 1) {
    return;
  }

  // Check if is a valid matrix
  int valid = matrix_[0].size();
  for (const auto &rows : matrix_) {
    if (valid != rows.size()) {
      throw std::invalid_argument("Sizes of matrix is incosistent.");
    }
  }
}

void Matrix::show_matrix() const {
  for (const auto &row : matrix_) {
    for (auto number : row) {
      std::cout << number << " ";
    }
    std::cout << "\n";
  }
}

std::vector<std::vector<float>>
Matrix::column_by_rows(const Matrix &otherMatrix) const {

  std::vector<std::vector<float>> product(row_size());

  // First check if we can multiply the matrix
  if (matrix_.size() == 0 && otherMatrix.matrix().size() == 0) {
    return product;
  } else if (matrix_.size() == 0 || otherMatrix.matrix().size() == 0 ||
             column_size() != otherMatrix.row_size()) {
    throw std::invalid_argument(
        "To multiply two matrices, the number of columns in the first matrix "
        "must equal the number of rows in the second matrix");
  }

  // Calculation
  for (int row = 0; row < matrix_.size(); ++row) {
    for (int otherMatrixCols = 0; otherMatrixCols < otherMatrix.column_size();
         ++otherMatrixCols) {

      float productRes = 0;
      for (int otherMatrixRows = 0; otherMatrixRows < otherMatrix.row_size();
           ++otherMatrixRows) {
        productRes += matrix_[row][otherMatrixRows] *
                      otherMatrix.matrix()[otherMatrixRows][otherMatrixCols];
      }
      product[row].push_back(productRes);
    }
  }

  return product;
}

std::vector<std::vector<float>>
Matrix::permutation(const std::vector<int> &order) const {
  if (order.size() != column_size()) {
    throw std::invalid_argument(
        "Invalid permutation: the number of permutation indices must match the "
        "number of columns");
  }

  std::vector<std::vector<float>> matrixPermutation(
      column_size(), std::vector<float>(column_size(), 0));

  std::unordered_set<int> seen;

  for (int row = 0; row < order.size(); ++row) {
    if (seen.count(order[row])) {
      throw std::invalid_argument("You cant repeat the column in permutations");
    }
    if (order[row] > order.size() || order[row] < 0) {
      throw std::invalid_argument("Column does not exist");
    }
    seen.insert(order[row]);
    matrixPermutation[row][order[row]] = 1;
  }

  return matrixPermutation;
}

const std::vector<std::vector<float>> &Matrix::matrix() const {
  return matrix_;
}

std::size_t Matrix::column_size() const {
  for (const auto &row : matrix_) {
    return row.size();
  }
  return 0;
}

std::size_t Matrix::row_size() const { return matrix_.size(); }
