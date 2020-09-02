#pragma once
#include "Direction.h"

namespace antGrid {

  // singleton class for east direction
  class East : public Direction
  {
  public:
    // define a public static accessor func
    static East* instance();
    virtual Direction* turnClockwise() override;
    virtual Direction* turnCounterClockwise() override;
    virtual Block moveForward(Block currentBlock) override;

  protected:
    // define all constructors to be protected
    East();

    // define a private static attribute
  private:
    static East* inst;
  };
}
