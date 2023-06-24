#include <iostream>
#include <vector>

// Board size
#define N 8

// Function to check if a move is valid
bool isMoveValid(int x, int y, std::vector<std::vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Function to print the board
void printBoard(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << board[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Function to solve the Knight's Tour problem using backtracking
bool solveKnightTour(int x, int y, int moveCount, std::vector<std::vector<int>>& board, const std::vector<int>& moveX, const std::vector<int>& moveY) {
    if (moveCount == N * N) {
        printBoard(board);
        return true; // Solution found
    }

    for (int k = 0; k < 8; ++k) {
        int nextX = x + moveX[k];
        int nextY = y + moveY[k];
        
        if (isMoveValid(nextX, nextY, board)) {
            board[nextX][nextY] = moveCount;
            
            if (solveKnightTour(nextX, nextY, moveCount + 1, board, moveX, moveY))
                return true; // Solution found
            
            board[nextX][nextY] = -1; // Backtrack
        }
    }

    return false; // Solution not found
}

// Function to initialize and start the Knight's Tour
void startKnightTour() {
    std::vector<std::vector<int>> board(N, std::vector<int>(N, -1));
    std::vector<int> moveX = {2, 1, -1, -2, -2, -1, 1, 2};
    std::vector<int> moveY = {1, 2, 2, 1, -1, -2, -2, -1};
    int startX = 0, startY = 0; // Starting position of the knight

    board[startX][startY] = 0; // Mark the starting position

    if (solveKnightTour(startX, startY, 1, board, moveX, moveY)) {
        std::cout << "Solution found!" << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }
}

// Main function
int main() {
    startKnightTour();

    return 0;
}
