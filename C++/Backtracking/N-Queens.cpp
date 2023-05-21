#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& topLeftDiagonal, vector<int>& bottomLeftDiagonal, int n){
    
    if(col == n){
        ans.push_back(board);
        return;
    }
    // try to put Q at every row for the given col
    for(int row = 0; row < n; row++){
        if(leftRow[row] == 1 || bottomLeftDiagonal[row + col] == 1 || topLeftDiagonal[n - 1 + col - row] == 1) continue;

        board[row][col] = 'Q';
        leftRow[row] = 1;
        bottomLeftDiagonal[row + col] = 1;
        topLeftDiagonal[n - 1 + col - row] = 1;
        solve(col + 1, board, ans, leftRow, topLeftDiagonal, bottomLeftDiagonal, n);
        board[row][col] = '.';
        leftRow[row] = 0;
        bottomLeftDiagonal[row + col] = 0;
        topLeftDiagonal[n - 1 + col - row] = 0;
    }
}

int main() {
    int n = 4;
    vector<vector<string>> ans;
    vector<string> board;
    string s(n, '.');       // s = '....'
    vector<int> leftRow(n, 0);
    vector<int> topLeftDiagonal(2 * n - 1, 0);      // (2n-1) because we will add row and col to get the index
    vector<int> bottomLeftDiagonal(2 * n - 1, 0);

    auto start = chrono::high_resolution_clock::now();

    for(int i = 0; i < n; i++){     // [['....'],
        board.push_back(s);         //  ['....'],
    }                               //  ['....'],
                                    //  ['....']]

    solve(0, board, ans, leftRow, topLeftDiagonal, bottomLeftDiagonal, n);    // (column, board, answer, n)

    auto end = chrono::high_resolution_clock::now();
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Elapsed time: " << duration << " milliseconds" << endl;
}