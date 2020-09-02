#include <iostream>
#include "North.h"
#include "East.h"
#include "West.h"

namespace antGrid {
  North::North()
  {
    //std::cout << "constructor ";
  }

  Direction* North::turnClockwise()
  {
    return East::instance();
  }

  Direction* North::turnCounterClockwise()
  {
    return West::instance();
  }

  Block North::moveForward(Block currentBlock)
  {
    return Block(currentBlock.getX(), currentBlock.getY() + 1);
  }

  North* North::instance()
  {
    if (!inst)
      // do "lazy initialization" in the accessor function
      inst = new North();
    return inst;
  }

  North* North::inst = 0;
}
