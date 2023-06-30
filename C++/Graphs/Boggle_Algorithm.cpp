/*
------------------------------------- Boggle Board Algorithm -------------------------------------

Approach

1. Input the number of rows (M), number of columns (N), number of words in the dictionary (n), and the words in the dictionary.

2. Create a 2D character array to represent the boggle board.

3. Input the letters for each cell of the boggle board.

4. Initialize an empty visited array of size M x N to keep track of visited cells.

5. Implement a function `isWord` that checks if a given string is present in the dictionary or not. This function compares the string with each word in the dictionary and returns true if a match is found.

6. Implement a recursive function `findWordsUtil` that performs a depth-first search (DFS) to find words on the boggle board. This function takes the current cell's coordinates (i, j), the current string formed so far, and the visited array.

7. In the findWordsUtil function:
    1. Mark the current cell as visited and append the current character to the string.

    2. If the string is present in the dictionary, print it.

    3. Traverse the 8 adjacent cells of the current cell (top-left to bottom-right direction):

    4. Check if the adjacent cell is within the boundaries of the boggle board and not visited.

    5. If so, recursively call findWordsUtil for the adjacent cell.

    6. Erase the last character from the string and mark the visited status of the current cell as false to backtrack.

Below is the implementation of Boggle board Algorithm in C++ Language.
*/

// Program starts

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

// A given function to check if a given string is present in the dictionary or not
bool isWord(string &str, int n, vector<string> &dictionary)
{
    // Linearly search all words
    for (int i = 0; i < n; i++)
        if (str.compare(dictionary[i]) == 0)
            return true;
    return false;
}

// A recursive function to print all words present on the boggle
void findWordsUtil(int &M, int &N, char boggle[][100], bool visited[][100], int i, int j, string &str, int n, vector<string> &dictionary)
{
    // Mark the current cell as visited and append the current character to `str`
    visited[i][j] = true;
    str = str + boggle[i][j];

    // If `str` is present in the dictionary, then print it
    if (isWord(str, n, dictionary))
        cout << str << endl;

    // Traverse the 8 adjacent cells of boggle[i][j]
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int k = 0; k < 8; k++)
    {
        int newi = i + dx[k];
        int newj = j + dy[k];
        if (newi >= 0 && newi < M && newj >= 0 && newj < N && !visited[newi][newj])
            findWordsUtil(M, N, boggle, visited, newi, newj, str, n, dictionary);
    }

    // Erase the current character from the string and mark the visited status of the current cell as false
    str.erase(str.length() - 1);
    visited[i][j] = false;
}

// Prints all words present in the dictionary
void findWords(char boggle[][100], int &M, int &N, int n, vector<string> &dictionary)
{
    // Mark all characters as not visited
    bool visited[100][100] = {{false}};

    // Initialize the current string
    string str = "";

    // Consider every character and look for all words starting with this character
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            findWordsUtil(M, N, boggle, visited, i, j, str, n, dictionary);
        }
    }
}

// Driver function
int main()
{
    // Clear the screen
    cout << "\033[2J\033[1;1H";

    int M, N;
    cout << "\nEnter the number of rows (M): ";
    cin >> M;

    cout << "\nEnter the number of columns (N): ";
    cin >> N;

    int n;
    cout << "\nEnter the number of words in the dictionary (n): ";
    cin >> n;

    vector<string> dictionary(n);
    cout << "\033[2J\033[1;1H";
    cout << "\nEnter the words in the dictionary: " << endl;

    // Input the words in the dictionary
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Word " << i + 1 << ": ";
        cin >> dictionary[i];
    }

    char boggle[100][100];
    cout << "\033[2J\033[1;1H";
    cout << "\nEnter the boggle board: " << endl;

    // Input the boggle board
    for (int i = 0; i < M; i++)
    {
        cout << "\nEnter Row " << i + 1 << "\n";
        for (int j = 0; j < N; j++)
        {
            cout << "Enter Letter " << j + 1 << ": ";
            cin >> boggle[i][j];
        }
    }

    // Clear the screen
    cout << "\033[2J\033[1;1H";

    // Print the boggle board
    cout << "Your Boggle Board\n\n";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << boggle[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nYour Dictionary\n";

    // Printing the dictionary
    for (int i = 0; i < n; i++)
    {
        cout << dictionary[i] << endl;
    }

    // Find and print the words present in the boggle board
    cout << "\nFollowing words are present in the Boggle Board\n";
    findWords(boggle, M, N, n, dictionary);

    cout << endl;

    return 0;
}
