#include <iostream>
#include <cstring>

using namespace std;

void printBoard(char grid[][3]) {
  cout << "____________________________________________" << endl;
  cout             <<"  1"         <<"2"         <<"3"   << endl;
  cout << "a " << grid[0][0] << grid[1][0] << grid[2][0] << endl;
  cout << "b " << grid[0][1] << grid[1][1] << grid[2][1] << endl;
  cout << "c " << grid[0][2] << grid[1][2] << grid[2][2] << endl;
}

bool checkWin(char grid[][3], char player, char any, char none) {
  // WIN CONDITION LIBRARY:
  // horizontal wins:
  char winH0[][3] = {
    {any,  any,  any},
    {none, none, none},
    {none, none, none}
  };
  char winH1[][3] = {
    {none, none, none},
    {any,  any,   any},
    {none, none, none}
  };
  char winH2[][3] = {
    {none, none, none},
    {none, none, none},
    {any,  any,  any}
  };
  
  // vertical wins: 
  char winV0[][3] = {
    {any, none, none},
    {any, none, none},
    {any, none, none}
  };
  char winV1[][3] = {
    {none, any, none},
    {none, any, none},
    {none, any, none}
  };
  char winV2[][3] = {
    {none, none, any},
    {none, none, any},
    {none, none, any}
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

  int h0win = 0;
  int h1win = 0;
  int h2win = 0;
  int v0win = 0;
  int v1win = 0;
  int v2win = 0;
  int dlwin = 0;
  int drwin = 0;
  
  // check if stuff meets win conditions
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      // current value for convenience
      char value = grid[x][y];

      // check for wins: 
      if (value == player) {
	// check for horizontal wins:
	if (winH0[x][y] == any) {
	  h0win++;
	}
	if (winH1[x][y] == any) {
	  h1win++;
	}
	if (winH2[x][y] == any) {
	  h2win++;
	}

	// check for vertical wins:
	if (winV0[x][y] == any) {
	  v0win++;
	}
	if (winV1[x][y] == any) {
	  v1win++;
	}
	if (winV2[x][y] == any) {
	  v2win++;
	}

	// check for diagonal left wins:
	if (winDL[x][y] == any) {
	  dlwin++;
	}

	// check for diagonal right wins:
	if (winDR[x][y] == any) {
	  drwin++;
	}
      }
    }
  }

  // does the player meet the win conditions?
  if (h0win == 3 || h1win == 3 || h2win == 3
      || v0win == 3 || v1win == 3|| v2win == 3
      || dlwin == 3 || drwin == 3) return true;
  else return false;
}

int emptySpaces(char grid[][3], char none) {
  int empty = 0;
  
  // check how many spots are empty;
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
    // game loop
    else {
      // print board
      printBoard(grid);
      
      // turn message
      if (state == XTURN) {
	cout << "X's turn" << endl;
      }
      else if (state == OTURN) {
	cout << "O's turn" << endl;
      }
      // game over message
      else {
	cout << "Game Over!" << endl;
	
	// draw message
	if (state == DRAW) {
	  cout << "it was a draw" << endl;
	}
	// x win message
	else if (state == XWON) {
	  cout << "X won" << endl;
	}
	// o win message
	else if (state == OWON) {
	  cout << "O won" << endl;
	}

	// end game
	isRunning = false;
	return 0;
      }
      
      // get players input
      char input[3];
      cin >> input;
      
      // convert input to grid position
      int xpos = int(input[1]) - 48 - 1; // already a number value, but offset down to a 0
      int ypos = int(input[0]) - 96 - 1; // offset char to get number value
      char value = grid[xpos][ypos];

      // place into grid
      if (value == none) {
	// place X
	if (state == XTURN) {
	  grid[xpos][ypos] = X;
	  state = OTURN;
	}
	// place O
	else if (state == OTURN) {
	  grid[xpos][ypos] = O;
	  state = XTURN;
	}
      }
      else {
	cout << "Invalid Move!" << endl;
      }

      // check for a draw
      if (emptySpaces(grid, none) == 0) {
	state = DRAW;
      }
      // check if X has won
      else if (checkWin(grid, X, any, none) == true) {
	state = XWON;
      }
      // check if O has won
      else if (checkWin(grid, O, any, none) == true) {
	state = OWON;
      }
    }
  }
  
  return 0;
}
  
