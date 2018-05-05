#include <initializer_list>
#include <iostream>
#include <vector>

class Matrix {
private:
  int rowsNb;
  int colNb;
  std::vector< std::vector< double > > matrix;

public:
  Matrix(int _colNb, int _rowNb, bool isRandom = false);

  void afficher() const;

  Matrix multiply(Matrix b) const;
};

Matrix operator*(Matrix const &a, Matrix const &b);
