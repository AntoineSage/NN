#define TEXT_MAX_SIZE 500
#include <iostream>

class Button {
private:
  std::string text;
  bool isTextWhite;

public:
  int x1;
  int x2;
  int y1;
  int y2;
  int red;
  int green;
  int blue;
  Button(int _x1, int _y1, int _x2, int _y2, int _red, int _green, int _blue,
         std::string _text, bool _isTextWhite = false);

  void randomColor();
  void setColor(Button b);
};