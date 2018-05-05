#include "Matrix.h"
#include <cassert>
#include <cstdarg>
#include <initializer_list>
#include <iostream>
#include <vector>

using namespace std;

Matrix::Matrix(int _rowNb, int _colNb, bool isRandom)
    : rowsNb(_rowNb), colNb(_colNb) {

  for (int i = 0; i < rowsNb; i++) {
    std::vector< double > v;
    for (int j = 0; j < colNb; j++) {
      if (isRandom) {
        v.push_back(2.0 * ((double)rand() / (double)RAND_MAX) - 1.0);
      } else {
        v.push_back(0);
      }
    }
    matrix.push_back(v);
  }
}

void Matrix::init(int _rowNb, int _colNb, bool isRandom) {
  colNb = _colNb;
  rowsNb = _rowNb;

  for (int i = 0; i < rowsNb; i++) {
    std::vector< double > v;
    for (int j = 0; j < colNb; j++) {
      if (isRandom) {
        v.push_back(2.0 * ((double)rand() / (double)RAND_MAX) - 1.0);
      } else {
        v.push_back(0);
      }
    }
    matrix.push_back(v);
  }
}

void Matrix::afficher() const {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

void Matrix::map(double (*activationFunction)(double)) {
  for (int i = 0; i < rowsNb; i++) {
    for (int j = 0; j < colNb; j++) {
      matrix[i][j] = activationFunction(matrix[i][j]);
    }
  }
}

Matrix Matrix::multiply(Matrix b) const {
  assert(colNb == b.rowsNb);

  Matrix m(rowsNb, b.colNb);
  for (int i = 0; i < m.rowsNb; i++) {
    for (int j = 0; j < m.colNb; j++) {

      double sum = 0;
      for (int k = 0; k < rowsNb; k++) {
        sum += matrix[i][k] * b.matrix[k][j];
      }

      m.matrix[i][j] = sum;
    }
  }

  return m;
}

Matrix Matrix::add(Matrix b) const {
  assert(colNb == b.colNb);
  assert(rowsNb == b.rowsNb);

  Matrix m(rowsNb, colNb);
  for (int i = 0; i < m.rowsNb; i++) {
    for (int j = 0; j < m.colNb; j++) {
      m.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
    }
  }

  return m;
}

Matrix operator*(Matrix const &a, Matrix const &b) { return a.multiply(b); }

Matrix operator+(Matrix const &a, Matrix const &b) { return a.add(b); }

void Matrix::operator=(std::vector< double > v) {
  assert(colNb == 1);
  assert(rowsNb == v.size());
  matrix[0] = v;
}
