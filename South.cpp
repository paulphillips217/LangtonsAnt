#include <iostream>
#include "South.h"
#include "East.h"
#include "West.h"

namespace antGrid {
  South::South()
  {
    //std::cout << "constructor ";
  }

  Direction* South::turnClockwise()
  {
    return West::instance();
  }

  Direction* South::turnCounterClockwise()
  {
    return East::instance();
  }

  Block South::moveForward(Block currentBlock)
  {
    return Block(currentBlock.getX(), currentBlock.getY() - 1);
  }

  South* South::instance()
  {
    if (!inst)
      // do "lazy initialization" in the accessor function
      inst = new South();
    return inst;
  }

  South* South::inst = 0;
}
