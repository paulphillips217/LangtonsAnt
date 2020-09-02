#pragma once
#include <vector>
#include "Block.h"
#include "Direction.h"

namespace antGrid {

  // this class represents the locations on the grid that the ant visits, stored in a vector
  struct Location {
    int x;
    int y;
  };

  class Grid
  {
  private:
    std::vector<Block> visitedBlocks;
    Location antLocation;

  public:
    Grid();
    void makeMoves(int numMoves, Direction* initialDirection);
    Location getAntLocation();
    Block* getGridByCoordinates(int x, int y);
    int getGridMinX();
    int getGridMaxX();
    int getGridMinY();
    int getGridMaxY();
  };
}
