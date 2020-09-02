#pragma once
#include "Direction.h"

namespace antGrid {

  // singleton class for west direction
  class West : public Direction
  {
  public:
    // define a public static accessor func
    static West* instance();
    virtual Direction* turnClockwise() override;
    virtual Direction* turnCounterClockwise() override;
    virtual Block moveForward(Block currentBlock) override;

  protected:
    // define all constructors to be protected
    West();

    // define a private static attribute
  private:
    static West* inst;
  };
}
