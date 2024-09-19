#include <iostream>
#include <cstring>

int main() {
  // tic tac toe grid
  int width = 3;
  int height = 3;
  
  int grid[width][height] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  };

  bool isRunning = true;

  int START = 0;
  int XTURN = 1;
  int OTURN = 2;
  int XWON = 3;
  int OWON = 4;
  int DRAW = 5;
  
  int state = START;

  // game loop
  while (isRunning) {
    // print board
    cout << "          1             2              3"    << endl;
    cout << "A" << grid[0][0] << grid[1][0] << grid[2][0] << endl;
    cout << "B" << grid[0][1] << grid[1][1] << grid[2][1] << endl;
    cout << "C" << grid[0][2] << grid[1][2] << grid[2][2] << endl;
    
    // get players input
    char input[2] << cin;

    // convert to grid position
  }
  
  return 0;
}
