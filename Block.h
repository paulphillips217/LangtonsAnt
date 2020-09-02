#pragma once

namespace antGrid {
  enum class Color { black = 2, white = 242 };

  class Block
  {
  private:
    int x;
    int y;
    Color color;

  public:
    Block();
    Block(int initialX, int initialY, Color initialColor);
    Block(int initialX, int initialY);
    int getX();
    int getY();
    Color getColor();
    void flipColor();
  };
}
