#include "Button.h"
#include "NN.h"
#include <SDL2/SDL.h>
#include <initializer_list>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <typeinfo>
#include <vector>

NN nn(3, 5, 2);
std::string text = "Is this better in black or white ?";
Button leftBlack(0, 0, 400, 800, 255, 0, 0, text);
Button rightWhite(400, 0, 800, 800, 255, 0, 0, text, true);

SDL_Window *window;
SDL_Renderer *renderer;

const SDL_Rect rectLeft = {leftBlack.x1, leftBlack.y1,
                           leftBlack.x2 - leftBlack.x1,
                           leftBlack.y2 - leftBlack.y1};
const SDL_Rect rectRight = {rightWhite.x1, rightWhite.y1,
                            rightWhite.x2 - rightWhite.x1,
                            rightWhite.y2 - rightWhite.y1};

void initWindow() {
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("NN_1", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, 0);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, leftBlack.red, leftBlack.green,
                         leftBlack.blue, 255);
  SDL_RenderFillRect(renderer, &rectLeft);
  SDL_RenderFillRect(renderer, &rectRight);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderDrawLine(renderer, 400, 0, 400, 800);

  SDL_RenderPresent(renderer);
}

void updateWindow() {
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, leftBlack.red, leftBlack.green,
                         leftBlack.blue, 255);
  SDL_RenderFillRect(renderer, &rectLeft);
  SDL_RenderFillRect(renderer, &rectRight);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderDrawLine(renderer, 400, 0, 400, 800);

  SDL_RenderPresent(renderer);
}

void buttonPressed(SDL_Keycode e) {
  if (e == SDLK_LEFT || e == SDLK_RIGHT) {
    int r;
    int g;
    int b;

    // bool isTextWhite;
    // if (e == SDLK_LEFT) {
    //   isTextWhite = false;
    // } else if (e == SDLK_RIGHT) {
    //   isTextWhite = true;
    // }
    // nn.train(r, g, b, isTextWhite);

    leftBlack.randomColor();
    rightWhite.setColor(leftBlack);
    // bool isLeftBlack = nn.guess(r, g, b);

    // if (isLeftBlack) {
    //   leftBlack.setBorder(true);
    //   rightWhite.setBorder(false);
    // } else {
    //   leftBlack.setBorder(false);
    //   rightWhite.setBorder(true);
    // }

    updateWindow();
  }
}

int main(int argc, char **argv) {
  srand(time(NULL));

  initWindow();

  SDL_Event e;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
      if (e.type == SDL_KEYDOWN) {
        buttonPressed(e.key.keysym.sym);
      }
    }
  }
}

// -LC:/msys64/mingw64/include/SDL2 -lmingw32 -lSDLmain -lSDL
// "C:/msys64/mingw64/lib/*",
// "C:/msys64/mingw64/include",
// "C:/msys64/mingw64/include/c++/7.3.0",
// "C:/msys64/mingw64/include/c++/7.3.0/tr1",
// "C:/msys64/mingw64/include/c++/7.3.0/x86_64-w64-mingw32",
// "C:/msys64/mingw64/x86_64-w64-mingw32/include"

// FAIRE EN SORTE QUE CA MARCHE SOUS LINUX :
/*
Debugger version Linux
Build task version Linux
.clang-format
Paramétrage de visual studio
Paramétrage de git
*/

// // NN test(1, 1, 1);
// // test.afficher();
// // std::vector< double > _Input(1.0);
// // test.feedForward(_Input);
// // test.afficher();

// SDL_Init(SDL_INIT_EVERYTHING);
// SDL_Window *window =
//     SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED,
//     SDL_WINDOWPOS_CENTERED,
//                      600, 400, SDL_WINDOW_SHOWN);
// SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

// SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

// SDL_RenderClear(renderer);

// SDL_RenderPresent(renderer);

// SDL_Delay(3000);