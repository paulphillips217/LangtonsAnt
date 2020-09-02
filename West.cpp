#include <iostream>
#include "North.h"
#include "South.h"
#include "West.h"

namespace antGrid {
  West::West()
  {
    //std::cout << "constructor ";
  }

  Direction* West::turnClockwise()
  {
    return North::instance();
  }

  Direction* West::turnCounterClockwise()
  {
    return South::instance();
  }

  Block West::moveForward(Block currentBlock)
  {
    return Block(currentBlock.getX() - 1, currentBlock.getY());
  }

  West* West::instance()
  {
    if (!inst)
      // do "lazy initialization" in the accessor function
      inst = new West();
    return inst;
  }

  West* West::inst = 0;
}
