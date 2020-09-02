#pragma once
#include <vector>
#include "Block.h"

namespace antGrid {

  // rather than use switch statements to determine which direction is 
  // clockwise or couter-clockwise, or what to increment for a move, 
  // use the strategy pattern so each direction has a class to implement those things

  // abstract class (to be inherited by the 4 directions)
  class Direction
  {
  public:
    virtual Direction* turnClockwise() = 0;
    virtual Direction* turnCounterClockwise() = 0;
    virtual Block moveForward(Block currentBlock) = 0;
  };
}
