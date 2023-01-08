// =====================PROBLEM STATEMENT===========================
/*
The Knight's Tour problem is a classic problem in computer science that involves 
finding a path for a knight on a chessboard such that the knight visits every 
square on the board exactly once. The knight is allowed to move in an L-shaped 
pattern, moving two squares horizontally and one square vertically, or two squares 
vertically and one square horizontally.

The problem can be formulated as follows:

Input:

A chessboard of size N x N, where N is an integer greater than or equal to 5.

Output:

A sequence of moves for the knight such that it visits every square on the board 
exactly once, or a message indicating that no such sequence of moves exists.
*/

// =======================CODE=============================
#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

struct Node {
  int x, y, step;
  Node(int x, int y, int step) : x(x), y(y), step(step) {}
};

bool isValid(int x, int y) {
  return x >= 0 && x < N && y >= 0 && y < N;
}

bool bfs(vector<vector<int>>& board, int x, int y) {
  vector<Node> q{{x, y, 0}};
  while (!q.empty()) {
    auto [x, y, step] = q.back();
    q.pop_back();
    if (step == N * N) return true;

    board[x][y] = step;
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (isValid(nx, ny) && board[nx][ny] == -1) {
        q.emplace_back(nx, ny, step + 1);
      }
    }
  }
  return false;
}

int main() {
  vector<vector<int>> board(N, vector<int>(N, -1));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (bfs(board, i, j)) {
        for (int x = 0; x < N; x++) {
          for (int y = 0; y < N; y++) {
            cout << board[x][y] << " ";
          }
          cout << endl;
        }
        return 0;
      }
    }
  }

  cout << "No solution found" << endl;
  return 0;
}
