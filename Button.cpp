#include "Button.h"

Button::Button(int _x1, int _y1, int _x2, int _y2, int _red, int _green,
               int _blue, std::string _text, bool _isTextWhite)
    : x1(_x1), y1(_y1), x2(_x2), y2(_y2), red(_red), green(_green), blue(_blue),
      text(_text), isTextWhite(_isTextWhite) {}

void Button::randomColor() {
  red = rand() % 256;
  green = rand() % 256;
  blue = rand() % 256;
}

void Button::setColor(Button b) {
  red = b.red;
  green = b.green;
  blue = b.blue;
}
