#include <initializer_list>
#include <iostream>
#include <vector>

class Matrix {
private:
  int rowsNb;
  int colNb;
  std::vector< std::vector< double > > matrix;

public:
  Matrix(int _colNb = 0, int _rowNb = 0, bool isRandom = false);

  void init(int _rowNb = 1, int _colNb = 1, bool isRandom = false);
  void afficher() const;
  void map(double (*activationFunction)(double));

  Matrix multiply(Matrix b) const;
  Matrix add(Matrix b) const;

  void operator=(std::vector< double > v);
};

Matrix operator*(Matrix const &a, Matrix const &b);
Matrix operator+(Matrix const &a, Matrix const &b);

// int g(int x(int)) { return x(1); }
// int g(int (*x)(int)) { return x(1); }
// int g(int (&x)(int)) { return x(1); }
// ... int f(int n) { return n * 2; }
// g(f); // all three g's above work the same