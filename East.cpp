#include <iostream>
#include "East.h"
#include "North.h"
#include "South.h"

namespace antGrid {
  East::East()
  {
    //std::cout << "East constructor ";
  }

  Direction* East::turnClockwise()
  {
    return South::instance();
  }

  Direction* East::turnCounterClockwise()
  {
    return North::instance();
  }

  Block East::moveForward(Block currentBlock)
  {
    return Block(currentBlock.getX() + 1, currentBlock.getY());
  }

  East* East::instance()
  {
    if (!inst)
      // do "lazy initialization" in the accessor function
      inst = new East();
    return inst;
  }

  East* East::inst = 0;
}
