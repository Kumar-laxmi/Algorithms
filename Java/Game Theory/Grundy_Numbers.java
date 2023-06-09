/*
 Grundy Numbers are a mathematical concept used in game theory to determine which player has the advantage in a game of two players. The Grundy value of a game state is defined recursively based on the Grundy values of its possible subsequent states. This recursive definition allows for efficient calculation of the Grundy value for any given state, which can then be used to determine the optimal moves for the player. Grundy Numbers have practical applications in game design, cryptography, and network security.

 To calculate the Grundy number for a given game position, the following steps are typically followed:

 1. Identify the possible moves from the current position.
 2. Calculate the Grundy numbers for each of the possible moves recursively.
 3. Determine the smallest non-negative integer that is not present in the set of Grundy numbers obtained from the possible moves.
 4. Assign this minimum excluded value as the Grundy number for the current position.
 */



 import java.util.*;

 public class Grundy_Numbers {
    
    // Function to calculate Grundy number for a given position
    public static int calculateGrundy(int position, int[] table, int[] moves) {
        if(position == 0){
            return 0;
        }

        if(table[position] != -1){
            return table[position];
        }

        Set<Integer> grundySet = new HashSet<>();

        // Calculate Grundy numbers for all possible moves
        for(int move : moves){
            if(position >= move){
                grundySet.add(calculateGrundy(position - move, table, moves));
            }
        }

        // Find the smallest non-negative integer not present in the set
        int num = 0;
        while(grundySet.contains(num)){
            num++;
        }

        table[position] = num;
        return num;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the maximum position: ");
        int n = scanner.nextInt();

        // List of possible moves - needs to be specified beforehand
        int[] moves = {1, 5, 8};

        // Memoization table
        int[] table = new int[n + 1];
        Arrays.fill(table, -1);

        // Calculate Grundy numbers for positions 0 to n (inclusive)
        for(int i = 0; i <= n; i++){
            int grundy = calculateGrundy(i, table, moves);
            System.out.println("Grundy number for position " + i + " is " + grundy);
        }
        scanner.close();
    }
 }
