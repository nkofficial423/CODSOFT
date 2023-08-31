#include <iostream>

using namespace std;

const int BOARD_SIZE = 3;

char board[BOARD_SIZE][BOARD_SIZE];
char currentPlayer = 'X';

void initializeBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = '-';
    }
  }
}

void displayBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

int getUserInput() {
  int row, col;

  do {
    cout << "Enter your move (row, col): ";
    cin >> row >> col;
  } while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != '-');

  return row * BOARD_SIZE + col;
}

bool checkForWin(char player) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    } else if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }

  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  } else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }

  return false;
}

bool checkForDraw() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == '-') {
        return false;
      }
    }
  }

  return true;
}

void switchPlayers() {
  currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void displayResult() {
  if (checkForWin(currentPlayer)) {
    cout << currentPlayer << " has won!" << endl;
  } else if (checkForDraw()) {
    cout << "The game is a draw." << endl;
  } else {
    cout << "Game is still ongoing." << endl;
  }
}

bool playAgain() {
  char response;

  do {
    cout << "Would you like to play again (y/n)? ";
    cin >> response;
  } while (response != 'y' && response != 'n');

  return response == 'y';
}

int main() {
  initializeBoard();

  do {
    displayBoard();

    while (!checkForWin(currentPlayer) && !checkForDraw()) {
      int move = getUserInput();
      board[move / BOARD_SIZE][move % BOARD_SIZE] = currentPlayer;
      switchPlayers();
    }

    displayBoard();
    displayResult();
  } while (playAgain());

  return 0;
}
