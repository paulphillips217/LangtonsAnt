#include <iostream>
#include <algorithm>    // std::min_element, std::max_element
#include "Grid.h"

namespace antGrid {

  Grid::Grid()
  {
    visitedBlocks.clear();
    antLocation = { 0, 0 };
  }

  void Grid::makeMoves(int numMoves, Direction* initialDirection)
  {
    // initialization
    visitedBlocks.push_back(Block());
    Direction* currentDirection = initialDirection;
    Block* currentBlock = &visitedBlocks[0];

    for (int moveIndex = 0; moveIndex < numMoves; moveIndex++)
    {
      Color currentColor = currentBlock->getColor();
      if (currentColor == Color::white)
      {
        // At a white square, turn 90 degrees right(clockwise)
        currentDirection = currentDirection->turnClockwise();
      }
      else if (currentColor == Color::black)
      {
        // At a black square, turn 90 degrees left(counter - clockwise)
        currentDirection = currentDirection->turnCounterClockwise();
      }

      // flip the color of the square and move forward one unit
      currentBlock->flipColor();
      Block nextBlock = currentDirection->moveForward(*currentBlock);
      antLocation = { nextBlock.getX(), nextBlock.getY() };

      // if we're revisiting an old block, point to that one
      currentBlock = getGridByCoordinates(antLocation.x, antLocation.y);
      if (!currentBlock)
      {
        // else add a new block to the vector
        visitedBlocks.push_back(nextBlock);
        currentBlock = &visitedBlocks.back();
      }
    }
  }

  Location Grid::getAntLocation()
  {
    return antLocation;
  }

  // return a block from the grid if it exists (has been visited)
  Block* Grid::getGridByCoordinates(int x, int y)
  {
    auto it = find_if(visitedBlocks.begin(), visitedBlocks.end(), [x, y](Block block)
      {
        return (block.getX() == x && block.getY() == y);
      });
    
    if (it != visitedBlocks.end())
      return &(*it);

    return NULL;
  }

  int Grid::getGridMinX()
  {
    auto min = std::min_element(visitedBlocks.begin(), visitedBlocks.end(),
      [](Block a, Block b)
      {
        return a.getX() < b.getX();
      });

    return (*min).getX();
  }

  int Grid::getGridMaxX()
  {
    auto max = std::max_element(visitedBlocks.begin(), visitedBlocks.end(),
      [](Block a, Block b)
      {
        return a.getX() < b.getX();
      });

    return (*max).getX();
  }

  int Grid::getGridMinY()
  {
    auto min = std::min_element(visitedBlocks.begin(), visitedBlocks.end(),
      [](Block a, Block b)
      {
        return a.getY() < b.getY();
      });

    return (*min).getY();
  }

  int Grid::getGridMaxY()
  {
    auto max = std::max_element(visitedBlocks.begin(), visitedBlocks.end(),
      [](Block a, Block b)
      {
        return a.getY() < b.getY();
      });

    return (*max).getY();
  }
}
