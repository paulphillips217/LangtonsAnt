#pragma once
#include "Direction.h"

namespace antGrid {

  // singleton class for south direction
  class South : public Direction
  {
  public:
    // define a public static accessor func
    static South* instance();
    virtual Direction* turnClockwise() override;
    virtual Direction* turnCounterClockwise() override;
    virtual Block moveForward(Block currentBlock) override;

  protected:
    // define all constructors to be protected
    South();

    // define a private static attribute
  private:
    static South* inst;
  };
}
