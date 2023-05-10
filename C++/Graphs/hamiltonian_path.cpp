// Check Hamiltonian Path using Dynamic Programming and Bit Masking
 
#include <bits/stdc++.h>

using namespace std;
 
// Hamiltonian Path Function
bool Is_Hamiltonian(vector<vector<int>>& Vec, int N) { 
    int table[N][(1 << N)];
 
    // Set the table values to 0
    memset(table, 0, sizeof table);
 
    // Set to true for all vertices of i
    for (int i = 0; i < N; i++)
    table[i][(1 << i)] = true;
        
    // Iterate through each subset of nodes
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            // Check the jth nodes are included in subset
            if (i & (1 << j)) {
                // Find the neighbor of j is also present in the current subset
                for (int k = 0; k < N; k++) {
                    if (i & (1 << k) && Vec[k][j] && j != k && table[k][i ^ (1 << j)]) {
                        // Change table[j][i] to true
                        table[j][i] = true;
                        break;
                    }
                }
            }
        }
    }
 
    // Loop through the vertices to check if the Hamiltonian Path exists
    for (int i = 0; i < N; i++) {
        if (table[i][(1 << N) - 1])
            return true;
    }
 
    return false;
}
 
// Driver
int main()
{
    // Input Example
    vector<vector<int> > Vec = { { 0, 1, 0, 0, 0},
                                 { 1, 0, 1, 1, 0},
                                 { 0, 1, 0, 1, 1},
                                 { 0, 1, 1, 0, 1}};
    int N = Vec.size();
 
    // Call Hamiltonian Path Function
    Is_Hamiltonian(Vec, N) ? cout << "YES" : cout << "NO"; 
 
    return 0;
}


