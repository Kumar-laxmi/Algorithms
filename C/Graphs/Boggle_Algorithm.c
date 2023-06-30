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

Below is the implementation of Boggle board Algorithm in C Language.
*/

// Program starts

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// A given function to check if a given string is present in the dictionary or not
bool isWord(char *str, int n, char dictionary[][MAX_SIZE])
{
    // Linearly search all words
    for (int i = 0; i < n; i++)
    {
        if (strcmp(str, dictionary[i]) == 0)
            return true;
    }
    return false;
}

// A recursive function to print all words present on the boggle
void findWordsUtil(int M, int N, char boggle[][MAX_SIZE], bool visited[][MAX_SIZE], int i, int j, char *str, int n, char dictionary[][MAX_SIZE])
{
    // Mark the current cell as visited and append the current character to `str`
    visited[i][j] = true;
    str[strlen(str)] = boggle[i][j];
    str[strlen(str) + 1] = '\0';

    // If `str` is present in the dictionary, then print it
    if (isWord(str, n, dictionary))
        printf("%s\n", str);

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
    str[strlen(str) - 1] = '\0';
    visited[i][j] = false;
}

// Prints all words present in the dictionary
void findWords(char boggle[][MAX_SIZE], int M, int N, int n, char dictionary[][MAX_SIZE])
{
    // Mark all characters as not visited
    bool visited[MAX_SIZE][MAX_SIZE] = {false};

    // Initialize the current string
    char str[MAX_SIZE] = "";

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
    system("cls");

    int M, N;
    printf("\nEnter the number of rows (M): ");
    scanf("%d", &M);

    printf("\nEnter the number of columns (N): ");
    scanf("%d", &N);

    int n;
    printf("\nEnter the number of words in the dictionary (n): ");
    scanf("%d", &n);

    system("cls");
    char dictionary[MAX_SIZE][MAX_SIZE];
    printf("\nEnter the words in the dictionary: \n");

    // Input the words in the dictionary
    for (int i = 0; i < n; i++)
    {
        printf("Enter Word %d: ", i + 1);
        scanf("%s", dictionary[i]);
    }

    char boggle[MAX_SIZE][MAX_SIZE];
    printf("\nEnter the boggle board: \n");

    // Input the boggle board
    system("cls");
    for (int i = 0; i < M; i++)
    {
        printf("\nEnter Row %d\n", i + 1);
        for (int j = 0; j < N; j++)
        {
            printf("Enter Letter %d: ", j + 1);
            scanf(" %c", &boggle[i][j]);
        }
    }

    // Clear the screen
    system("cls");

    // Print the boggle board
    printf("Your Boggle Board\n\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c ", boggle[i][j]);
        }
        printf("\n");
    }

    printf("\nYour Dictionary\n");

    // Printing the dictionary
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", dictionary[i]);
    }

    // Find and print the words present in the boggle board
    printf("\nFollowing words are present in the Boggle Board\n");
    findWords(boggle, M, N, n, dictionary);

    printf("\n");

    return 0;
}
