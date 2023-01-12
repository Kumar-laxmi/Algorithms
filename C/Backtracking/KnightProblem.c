/**
 *  @author - @Abhinavkar
 *  The Knight’s tour problem in C 
 *  Refrence from Clrs Book 
 * 
 *  This code is an implementation of the Knight's tour problem using the Warnsdorff's heuristic. 
 *  The problem is to find a way for a knight to move on a chessboard such that it visits every square exactly once.

	The code defines a two-dimensional array path of size BOARD_SIZE x BOARD_SIZE to represent the chessboard.
	The function `is_valid_move` checks if the move is inside the chessboard and the square is unvisited.
	The function get_valid_moves_count returns the number of valid moves from the current position.
	The function solve_kt_util is a recursive function that tries to find a solution by making moves to the squares with the least number of available next moves. 
	The function starts from the top-left corner of the board and it continues until it reaches the last square or it finds that it is not possible to continue.
	The function print_solution prints the solution found by the solve_kt_util function.
	The main function sets all the squares of the chessboard to unvisited and calls the solve_kt_util function to find a solution, 
	if it finds a solution, it calls the print_solution function to display it, otherwise, it prints "Solution does not exist"
	The program uses Warnsdorff's heuristic to prioritize moves to squares with the fewest available next moves, 
	which can help to reduce backtracking and increase the chances of finding a solution.

	Please let me know if you have any more question.
 * Time Complexity : 
There are N2 Cells and for each, we have a maximum of 8 possible moves to choose from,
so the worst running time is O(8N^2).
*/#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

int path[BOARD_SIZE][BOARD_SIZE];

bool is_valid_move(int x, int y) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && path[x][y] == -1);
}

int get_valid_moves_count(int x, int y) {
    int count = 0;
    int x_move[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int y_move[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    for (int i = 0; i < 8; i++) {
        int next_x = x + x_move[i];
        int next_y = y + y_move[i];
        if (is_valid_move(next_x, next_y))
            count++;
    }
        
    return count;
}

bool solve_kt_util(int x, int y, int move_count) {
    if (move_count == BOARD_SIZE * BOARD_SIZE)
        return true;
    int x_move[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int y_move[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int next_x, next_y;
    int min_valid_moves_count = BOARD_SIZE * BOARD_SIZE;
    int min_valid_moves_index = -1;
    for (int i = 0; i < 8; i++) {
        next_x = x + x_move[i];
        next_y = y + y_move[i];
        if (is_valid_move(next_x, next_y)) {
            int valid_moves_count = get_valid_moves_count(next_x, next_y);
            if (valid_moves_count < min_valid_moves_count) {
                min_valid_moves_count = valid_moves_count;
                min_valid_moves_index = i;
            }
        }
    }
    if (min_valid_moves_index == -1)
        return false;
    next_x = x + x_move[min_valid_moves_index];
    next_y = y + y_move[min_valid_moves_index];
    path[next_x][next_y] = move_count;
    if (solve_kt_util(next_x, next_y, move_count + 1))
        return true;
    path[next_x][next_y] = -1;
    return false;
}

void print_solution() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++)
            printf(" %2d ", path[i][j]);
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            path[i][j] = -1;
    path[0][0] = 0;
    if (!solve_kt_util(0, 0, 1))
        printf("Solution does not exist\n");
    else
        print_solution();
    return 0;
}

