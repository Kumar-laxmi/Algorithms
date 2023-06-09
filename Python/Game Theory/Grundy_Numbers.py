"""
Grundy Numbers are a mathematical concept used in game theory to determine which player has the advantage in a game of two players. The Grundy value of a game state is defined recursively based on the Grundy values of its possible subsequent states. This recursive definition allows for efficient calculation of the Grundy value for any given state, which can then be used to determine the optimal moves for the player. Grundy Numbers have practical applications in game design, cryptography, and network security.

To calculate the Grundy number for a given game position, the following steps are typically followed:

1. Identify the possible moves from the current position.
2. Calculate the Grundy numbers for each of the possible moves recursively.
3. Determine the smallest non-negative integer that is not present in the set of Grundy numbers obtained from the possible moves.
4. Assign this minimum excluded value as the Grundy number for the current position.
"""


# Function to calculate Grundy number for a given position
def calculate_grundy(position, table):
    if position == 0:
        return 0

    if table[position] != -1:
        return table[position]

    st = set()

    # Calculate Grundy numbers for all possible moves
    for move in moves:
        if position >= move:
            st.add(calculate_grundy(position - move, table))

    # Find the smallest non-negative integer not present in the set
    num = 0
    while num in st:
        num += 1

    table[position] = num
    return num


n = int(input("Enter the maximum position: "))
# List of possible moves - needs to specified beforehand
moves = [1, 5, 8]  
# Memoization table
table = [-1]*(n + 1)  

# Calculate Grundy numbers for positions 0 to n(inclusive)
for i in range(n + 1):
    grundy = calculate_grundy(i, table)
    print("Grundy number for position", i, "is", grundy)
