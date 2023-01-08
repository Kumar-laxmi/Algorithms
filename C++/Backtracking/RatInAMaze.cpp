#include <iostream>
#include <vector>

using namespace std;

const int N = 5;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct Node {
  int x, y;
  Node(int x, int y) : x(x), y(y) {}
};

bool isValid(int x, int y) {
  return x >= 0 && x < N && y >= 0 && y < N;
}

bool dfs(vector<vector<int>>& maze, vector<vector<bool>>& visited, int x, int y) {
  if (x == N - 1 && y == N - 1) return true;

  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (isValid(nx, ny) && !visited[nx][ny] && maze[nx][ny] == 1 && dfs(maze, visited, nx, ny)) {
      return true;
    }
  }
  visited[x][y] = false;
  return false;
}

int main() {
  vector<vector<int>> maze = {
    {1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 0, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
};

  vector<vector<bool>> visited(N, vector<bool>(N));
  cout << (dfs(maze, visited, 0, 0) ? "Solution found" : "No solution") << endl;
  return 0;
}
