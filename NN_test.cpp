#include "NN.h"
#include <SDL2/SDL.h>
#include <initializer_list>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <typeinfo>
#include <vector>
// -LC:/msys64/mingw64/include/SDL2 -lmingw32 -lSDLmain -lSDL
// "C:/msys64/mingw64/lib/*",
// "C:/msys64/mingw64/include",
// "C:/msys64/mingw64/include/c++/7.3.0",
// "C:/msys64/mingw64/include/c++/7.3.0/tr1",
// "C:/msys64/mingw64/include/c++/7.3.0/x86_64-w64-mingw32",
// "C:/msys64/mingw64/x86_64-w64-mingw32/include"

int main(int argc, char **argv) {
  srand(time(NULL));

  // NN test(1, 1, 1);
  // test.afficher();
  // std::vector< double > _Input(1.0);
  // test.feedForward(_Input);
  // test.afficher();
  
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *window =
      SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       600, 400, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);

  SDL_Delay(3000);

  return 0;
}