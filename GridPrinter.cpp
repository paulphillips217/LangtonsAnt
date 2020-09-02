#include "GridPrinter.h"

namespace antGrid {

  GridPrinter::GridPrinter()
  {
    #ifdef _WIN_
      hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    #endif
  }

  void GridPrinter::setConsoleColors(Color color)
  {
    #ifdef _WIN_
      SetConsoleTextAttribute(hConsole, (int)color);
    #else
      printf((color == Color::black) ? BLACK_BACK : WHITE_BACK);
      printf(GREEN_TEXT);
    #endif
  }

  void GridPrinter::printHorizontalLine(int gridWidth)
  {
    setConsoleColors(Color::black);
    std::string str(gridWidth * (blockWidth + 1) + 1, '-');
    std::cout << str << std::endl;
  }

  void GridPrinter::printVerticalLineSegment(bool includeEndLine)
  {
    setConsoleColors(Color::black);
    std::cout << "|";
    if (includeEndLine)
      std::cout << std::endl;
  }

  void GridPrinter::printBlock(Color color, char character)
  {
    std::string str(blockWidth, ' ');
    if (character)
      str[(blockWidth-1)/2] = character;
    setConsoleColors(color);
    std::cout << str;
  }

  void GridPrinter::printGrid(Grid grid)
  {
    // get the extents in each direction of how far the ant has traveled
    // set printed grid to be one block bigger than the traveled grid on each side
    int minX = grid.getGridMinX() - 1;
    int maxX = grid.getGridMaxX() + 1;
    int minY = grid.getGridMinY() - 1;
    int maxY = grid.getGridMaxY() + 1;
    int gridWidth = maxX - minX + 1;
    Location antLocation = grid.getAntLocation();

    for (int y = maxY; y >= minY; y--)
    {
      printHorizontalLine(gridWidth);
      for (int x = minX; x <= maxX; x++)
      {
        printVerticalLineSegment();
        Color blockColor = Color::white;
        Block* currentBlock = grid.getGridByCoordinates(x, y);
        if (currentBlock)
          blockColor = currentBlock->getColor();

        if (x == antLocation.x && y == antLocation.y)
          // put an A at the ant's location
          printBlock(blockColor, 'A');
        else if (x == 0 && y == 0)
          // put a zero at the origin
          printBlock(blockColor, '0');
        else
          printBlock(blockColor);
      }
      printVerticalLineSegment(true);
    }
    printHorizontalLine(gridWidth);
  }
}
