#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<int> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board.size(); j++) {
      cout << board[i * board.size() + j] << " ";
    }
    cout << endl;
  }
}

bool isSafe(vector<int> board, int row, int col) {
  for (int i = 0; i < row; i++) {
    if (board[i] == col || (row - i) == abs(col - board[i])) {
      return false;
    }
  }
  return true;
}

void solveNQueens(vector<int> board, int row) {
  if (row == board.size()) {
    printBoard(board);
    return;
  }

  for (int col = 0; col < board.size(); col++) {
    if (isSafe(board, row, col)) {
      board[row] = col;
      solveNQueens(board, row + 1);
    }
  }
}

int main() {
  int n = 8;
  vector<int> board(n * n);

  solveNQueens(board, 0);

  return 0;
}