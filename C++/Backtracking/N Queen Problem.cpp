// ====================PROBLEM STATEMENT===============================
/*
The N Queen Problem is a classic problem in computer science that involves 
placing N queens on an N x N chessboard such that no two queens are able to 
attack each other. A queen can attack another queen if it is in the same row,
column, or diagonal as the other queen.

The problem can be formulated as follows:

Input:

An integer N representing the size of the chessboard.

Output:

All possible configurations of the N queens on the chessboard such that 
no two queens are able to attack each other.
*/

// ===============CODE==================================

#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

bool isValid(vector<int>& cols, int col) {
  int row = cols.size();
  for (int i = 0; i < row; i++) {
    if (cols[i] == col || abs(cols[i] - col) == row - i) {
      return false;
    }
  }
  return true;
}

void dfs(vector<vector<int>>& res, vector<int>& cols) {
  if (cols.size() == N) {
    res.emplace_back(cols);
    return;
  }

  for (int col = 0; col < N; col++) {
    if (isValid(cols, col)) {
      cols.emplace_back(col);
      dfs(res, cols);
      cols.pop_back();
    }
  }
}

int main() {
  vector<vector<int>> res;
  vector<int> cols;
  dfs(res, cols);

  cout << res.size() << " solutions found" << endl;
  for (auto& sol : res) {
    for (int col : sol) {
      cout << col << " ";
    }
    cout << endl;
  }
  return 0;
}
