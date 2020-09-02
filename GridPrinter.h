#pragma once

#ifndef _WIN_
  #define _WIN_
#endif

#include <iostream>
#ifdef _WIN_
  #include <windows.h> // WinApi header
#else
  #include <stdio.h>  // non-windows
#endif
#include "Block.h"
#include "Grid.h"

namespace antGrid {

  // constants used for printing
  constexpr int blockWidth = 3;

  class GridPrinter
  {
  private:
    #ifdef _WIN_
      HANDLE hConsole;
    #else
      #define GREEN_TEXT   "\x1B[32m"
      #define WHITE_BACK   "\x1B[47m"
      #define BLACK_BACK   "\x1B[40m"
      #define RESET        "\x1B[0m"
    #endif

    void setConsoleColors(Color color);
    void printHorizontalLine(int gridWidth);
    void printVerticalLineSegment(bool includeEndLine = false);
    void printBlock(Color color, char character = NULL);

  public:
    GridPrinter();
    void printGrid(Grid grid);
  };
}
