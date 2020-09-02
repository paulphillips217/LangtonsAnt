#include <iostream>
#include "Block.h"

namespace antGrid {

  Block::Block()
  {
    // all defaults
    x = 0;
    y = 0;
    color = Color::white;
  }

  Block::Block(int initialX, int initialY, Color initialColor)
  {
    x = initialX;
    y = initialY;
    color = initialColor;
  }

  Block::Block(int initialX, int initialY)
  {
    // default color
    x = initialX;
    y = initialY;
    color = Color::white;
  }

  int Block::getX()
  {
    return x;
  }

  int Block::getY()
  {
    return y;
  }

  Color Block::getColor()
  {
    return color;
  }

  void Block::flipColor()
  {
    color = (color == Color::white) ? Color::black : Color::white;
  }
}
