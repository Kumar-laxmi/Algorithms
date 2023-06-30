'''
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

Below is the implementation of Boggle board Algorithm in PYTHON Language.
'''

# Program starts

# A given function to check if a given string is present in the dictionary or not
def isWord(string, n, dictionary):
    # Linearly search all words
    for i in range(n):
        if string == dictionary[i]:
            return True
    return False

# A recursive function to print all words present on the boggle
def findWordsUtil(M, N, boggle, visited, i, j, string, n, dictionary):
    # Mark the current cell as visited and append the current character to `string`
    visited[i][j] = True
    string += boggle[i][j]

    # If `string` is present in the dictionary, then print it
    if isWord(string, n, dictionary):
        print(string)

    # Traverse the 8 adjacent cells of boggle[i][j]
    dx = [-1, -1, -1, 0, 0, 1, 1, 1]
    dy = [-1, 0, 1, -1, 1, -1, 0, 1]
    for k in range(8):
        newi = i + dx[k]
        newj = j + dy[k]
        if 0 <= newi < M and 0 <= newj < N and not visited[newi][newj]:
            findWordsUtil(M, N, boggle, visited, newi, newj, string, n, dictionary)

    # Erase the current character from the string and mark the visited status of the current cell as false
    string = string[:-1]
    visited[i][j] = False

# Prints all words present in the dictionary
def findWords(boggle, M, N, n, dictionary):
    # Mark all characters as not visited
    visited = [[False] * N for _ in range(M)]

    # Initialize the current string
    string = ""

    # Consider every character and look for all words starting with this character
    for i in range(M):
        for j in range(N):
            findWordsUtil(M, N, boggle, visited, i, j, string, n, dictionary)

# Driver function
if __name__ == "__main__":
    # Clear the screen
    print("\033[2J\033[1;1H")

    M = int(input("Enter the number of rows (M): "))
    N = int(input("\nEnter the number of columns (N): "))

    n = int(input("\nEnter the number of words in the dictionary (n): "))
    dictionary = []
    print("\033[2J\033[1;1H")
    print("\nEnter the words in the dictionary: \n")

    # Input the words in the dictionary
    for i in range(n):
        print("Enter Word {}: ".format(i + 1), end="")
        word = input()
        dictionary.append(word)

    boggle = [[""] * N for _ in range(M)]
    print("\033[2J\033[1;1H")
    print("\nEnter the boggle board: \n")

    # Input the boggle board
    for i in range(M):
        print("\nEnter Row {}: ".format(i + 1))
        for j in range(N):
            print("Enter Letter {}: ".format(j + 1), end="")
            letter = input()
            boggle[i][j] = letter

    # Clear the screen
    print("\033[2J\033[1;1H")
    print("Your Boggle Board\n")

    # Printing boggle board
    for i in range(M):
        for j in range(N):
            print(boggle[i][j], end=" ")
        print()

    print("\nYour Dictionary\n")
    
    # Printing the dictionary
    for i in range(n):
        print(dictionary[i])
    
    # Find and print the words present in the boggle board
    print("\nFollowing words are present in the Boggle Board")
    findWords(boggle, M, N, n, dictionary)

    print()
