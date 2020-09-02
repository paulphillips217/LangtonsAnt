#include <iostream>
#include "East.h"
#include "Grid.h"
#include "GridPrinter.h"

using namespace antGrid;

  int main()
  {
    Grid grid;
    GridPrinter gridPrinter;
    int numMoves;

    std::cout << "How many moves should the ant make? ";
    std::cin >> numMoves;

    grid.makeMoves(numMoves, East::instance());

    gridPrinter.printGrid(grid);
    std::cout << "The initial position is marked with '0' and the ant's final position is marked with 'A'" << std::endl;
  }
