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

Below is the implementation of Boggle board Algorithm in Java Language.
*/

// Program starts

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Boggle_Algorithm {
    // A given function to check if a given string is present in the dictionary or
    // not
    private static boolean isWord(String str, List<String> dictionary) {
        // Linearly search all words
        for (String word : dictionary) {
            if (str.equals(word)) {
                return true;
            }
        }
        return false;
    }

    // A recursive function to print all words present on the boggle
    private static void findWordsUtil(int M, int N, char[][] boggle, boolean[][] visited, int i, int j,
            StringBuilder str, int n, List<String> dictionary) {
        // Mark the current cell as visited and append the current character to `str`
        visited[i][j] = true;
        str.append(boggle[i][j]);

        // If `str` is present in the dictionary, then print it
        if (isWord(str.toString(), dictionary)) {
            System.out.println(str);
        }

        // Traverse the 8 adjacent cells of boggle[i][j]
        int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };
        for (int k = 0; k < 8; k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];
            if (newi >= 0 && newi < M && newj >= 0 && newj < N && !visited[newi][newj]) {
                findWordsUtil(M, N, boggle, visited, newi, newj, str, n, dictionary);
            }
        }

        // Erase the current character from the string and mark the visited status of
        // the current cell as false
        str.deleteCharAt(str.length() - 1);
        visited[i][j] = false;
    }

    // Prints all words present in the dictionary
    private static void findWords(char[][] boggle, int M, int N, int n, List<String> dictionary) {
        // Mark all characters as not visited
        boolean[][] visited = new boolean[M][N];

        // Initialize the current string
        StringBuilder str = new StringBuilder();

        // Consider every character and look for all words starting with this character
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                findWordsUtil(M, N, boggle, visited, i, j, str, n, dictionary);
            }
        }
    }

    // Driver function
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            // Clear the screen
            System.out.print("\033[H\033[2J");
            System.out.flush();

            int M, N;
            System.out.print("\nEnter the number of rows (M): ");
            M = scanner.nextInt();

            System.out.print("\nEnter the number of columns (N): ");
            N = scanner.nextInt();

            int n;
            System.out.print("\nEnter the number of words in the dictionary (n): ");
            n = scanner.nextInt();

            List<String> dictionary = new ArrayList<>();
            System.out.print("\033[H\033[2J");
            System.out.println("\nEnter the words in the dictionary: ");

            // Input the words in the dictionary
            for (int i = 0; i < n; i++) {
                System.out.print("Enter Word " + (i + 1) + ": ");
                dictionary.add(scanner.next());
            }

            char[][] boggle = new char[M][N];
            System.out.print("\033[H\033[2J");
            System.out.println("\nEnter the boggle board: ");

            // Input the boggle board
            for (int i = 0; i < M; i++) {
                System.out.println("\nEnter Row " + (i + 1) + "\n");
                for (int j = 0; j < N; j++) {
                    System.out.print("Enter Letter " + (j + 1) + ": ");
                    boggle[i][j] = scanner.next().charAt(0);
                }
            }

            // Clear the screen
            System.out.print("\033[H\033[2J");
            System.out.flush();

            // Print the boggle board
            System.out.println("Your Boggle Board\n");
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    System.out.print(boggle[i][j] + " ");
                }
                System.out.println();
            }

            System.out.println("\nYour Dictionary\n");

            // Printing the dictionary
            for (String word : dictionary) {
                System.out.println(word);
            }

            // Find and print the words present in the boggle board
            System.out.println("\nFollowing words are present in the Boggle Board");
            findWords(boggle, M, N, n, dictionary);
        }

        System.out.println();
    }
}
