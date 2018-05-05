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

  NN test(1, 1, 1);
  test.afficher();
  std::vector< double > _Input(1.0);
  test.feedForward(_Input);
  test.afficher();
  return 0;
}