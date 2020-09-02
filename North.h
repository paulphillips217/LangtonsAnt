#pragma once
#include "Direction.h"

namespace antGrid {

  // singleton class for north direction
  class North : public Direction
  {
  public:
    // define a public static accessor func
    static North* instance();
    virtual Direction* turnClockwise() override;
    virtual Direction* turnCounterClockwise() override;
    virtual Block moveForward(Block currentBlock) override;

  protected:
    // define all constructors to be protected
    North();

    // define a private static attribute
  private:
    static North* inst;
  };
}
