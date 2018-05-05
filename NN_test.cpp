#include "Matrix.h"
#include "NN.h"
#include <initializer_list>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <typeinfo>
#include <vector>

// "C:/msys64/mingw64/lib/*",
// "C:/msys64/mingw64/include",
// "C:/msys64/mingw64/include/c++/7.3.0",
// "C:/msys64/mingw64/include/c++/7.3.0/tr1",
// "C:/msys64/mingw64/include/c++/7.3.0/x86_64-w64-mingw32",
// "C:/msys64/mingw64/x86_64-w64-mingw32/include"

int main() {
  srand(time(NULL));

  Matrix m(3, 3, true);
  Matrix n(3, 3, true);
  Matrix l = m * n;
  m.afficher();
  n.afficher();

  l.afficher();

  return 0;
}