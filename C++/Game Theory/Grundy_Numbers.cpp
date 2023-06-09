/*
Grundy Numbers are a mathematical concept used in game theory to determine which player has the advantage in a game of two players. The Grundy value of a game state is defined recursively based on the Grundy values of its possible subsequent states. This recursive definition allows for efficient calculation of the Grundy value for any given state, which can then be used to determine the optimal moves for the player. Grundy Numbers have practical applications in game design, cryptography, and network security.

To calculate the Grundy number for a given game position, the following steps are typically followed:

1. Identify the possible moves from the current position.
2. Calculate the Grundy numbers for each of the possible moves recursively.
3. Determine the smallest non-negative integer that is not present in the set of Grundy numbers obtained from the possible moves.
4. Assign this minimum excluded value as the Grundy number for the current position.
*/


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to calculate Grundy number for a given position
int calculate_grundy(int position, vector<int>& table, const vector<int>& moves) {
    if(position == 0){
        return 0;
    }

    if(table[position] != -1){
        return table[position];
    }

    unordered_set<int> grundySet;

    // Calculate Grundy numbers for all possible moves
    for(int move : moves){
        if(position >= move){
            grundySet.insert(calculate_grundy(position - move, table, moves));
        }
    }

    // Find the smallest non-negative integer not present in the set
    int num = 0;
    while(grundySet.count(num)){
        num++;
    }

    table[position] = num;
    return num;
}

int main() {
    int n;
    cout<<"Enter the maximum position: ";
    cin>>n;

    // List of possible moves - needs to be specified beforehand
    vector<int> moves = {1, 5, 8};
    // Memoization table
    vector<int> table(n + 1, -1);

    // Calculate Grundy numbers for positions 0 to n (inclusive)
    for (int i = 0; i <= n; i++) {
        int grundy = calculate_grundy(i, table, moves);
        cout<<"Grundy number for position " << i << " is "<<grundy<<endl;
    }

    return 0;
}
