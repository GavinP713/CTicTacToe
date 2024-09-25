#include <iostream>
#include <cstring>

using namespace std;

bool checkWin(char grid[][3], char player, char any, char none) {
  // win condition library
  // horizontal win
  char winH[][3] = {
    {none, none, none},
    {any,  any,   any},
    {none, none, none}
  };
  // vertical win 
  char winV[][3] = {
    {none, any, none},
    {none, any, none},
    {none, any, none}
  };
  // left diagonal win
  char winDL[][3] = {
    {any,  none,  none},
    {none, any,   none},
    {none, none,  any}
  };
  // right diagonal win
  char winDR[][3] = {
    {none, none, any},
    {none, any,  none},
    {any,  none, none}
  };

  int hwin = 0;
  int vwin = 0;
  int dlwin = 0;
  int drwin = 0;

  // 
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      char value = grid[x][y];
      
      if (value == player) {
	if (winH[x][y] == any) hwin++;
	if (winV[x][y] == any) vwin++;
	if (winDL[x][y] == any) dlwin++;
	if (winDR[x][y] == any) vwin++;
      }
    }
  }

  if ((hwin || vwin || dlwin || drwin) == 3) return true;
  else return false;
}

int emptySpaces(char grid[][3], char none) {
  int empty = 0;
  
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      char value = grid[x][y];

      if (value == none) empty++;
    }
  }

  return empty;
}

int main() {
  // game array and misc visuals
  char none = '.';
  char any = '?';
  char X = 'X';
  char O = 'O';
  char grid[][3] = {
    {none, none, none},
    {none, none, none},
    {none, none, none}
  };

  // game states
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

    // start the game
    if (state == START) {
      state = XTURN;

      cout << "Welcome to TicTacToe!" << endl;
    }

    // turn message
    if (state == XTURN) {
      cout << "X's turn" << endl;
    }
    else if (state == OTURN) {
      cout << "O's turn" << endl;
    }
    
    // print board
    cout             <<"  1"         <<"2"         <<"3"   << endl;
    cout << "a " << grid[0][0] << grid[1][0] << grid[2][0] << endl;
    cout << "b " << grid[0][1] << grid[1][1] << grid[2][1] << endl;
    cout << "c " << grid[0][2] << grid[1][2] << grid[2][2] << endl;
    
    // get players input
    char input[2];
    cin >> input;

    // convert to grid position
    int xpos = int(input[1]) - 48 - 1; // already a number value, but offset down to a 0
    int ypos = int(input[0]) - 96 - 1; // offset char to get number value
    char value = grid[xpos][ypos];


    // place into grid
    if (value == none) {
      if (state == XTURN) {
	grid[xpos][ypos] = X;
	state = OTURN;
      }
      else if (state == OTURN) {
	grid[xpos][ypos] = O;
	state = XTURN;
      }
    }
    else {
      cout << "Invalid Move!" << endl;
    }

    // check for a win or draw
    if (emptySpaces(grid, none) == 0) {
      cout << emptySpaces(grid, none) << endl;
      state = DRAW;
    }
    else if (checkWin(grid, X, any, none) == true) {
      state = XWON;
    }
    else if (checkWin(grid, O, any, none) == true) {
      state = OWON;
    }
  }
  
  return 0;
}
  
