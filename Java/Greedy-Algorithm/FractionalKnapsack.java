/* The Fractional Knapsack problem is a classic optimization problem often solved using a greedy algorithm. 
It involves selecting items from a set, each with a given weight and value, to maximize 
the total value while respecting a weight constraint.
Unlike the 0/1 knapsack problem, items can be divided (fractional) to maximize the value. 
This means that a fraction of an item can be included in the knapsack, rather than just selecting or excluding the entire item.*/

import java.util.Scanner;

class FractionalKnapsack {
    public static void main(String[] args) {
        float sum = 0;
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        /* Creating an array to store weights and profits.
        Each column represents an item, and the first row stores the weights, while the second row stores the profits.*/
        int array[][] = new int[2][n];

        int i, j = 0;
        System.out.println("Enter the weight of each item:");
        for (i = 0; i < n; i++) {
            array[0][i] = sc.nextInt();
        }
        System.out.println("Enter the profit of each item:");
        for (i = 0; i < n; i++) {
            array[1][i] = sc.nextInt();
        }
        System.out.print("Enter maximum volume of knapsack: ");
        int totalWeight = sc.nextInt();

        int m = totalWeight;
        while (m >= 0) {

            /* Finding the item with the maximum profit-to-weight ratio */
            float max = 0;
            for (i = 0; i < n; i++) {
                if (((float) array[1][i]) / ((float) array[0][i]) > max) {
                    max = ((float) array[1][i]) / ((float) array[0][i]);
                    j = i;
                }
            }

            /* If the weight of the item (array[0][j]) is greater than the remaining capacity of the knapsack (m), 
            it means the item cannot be fully added. In that case, the program outputs a message indicating 
            the quantity of the item added and calculates the profit contribution (m * max) of the partially added item. 
            Then, it sets m to -1 to exit the while loop. */
            if (array[0][j] > m) {
                System.out.println("Quantity of item number " + (j + 1) + " added is " + m);
                sum += m * max;
                m = -1;
            }
            
            /* If the item can be fully added to the knapsack, the program outputs a message indicating 
            the quantity of the item added. It updates m by subtracting the weight of the added item, 
            subtracts the profit of the added item from the sum, and sets the profit of the added item to 0 to mark it as already added. */
            else {
                System.out.println("Quantity of item number " + (j + 1) + " added is " + array[0][j]);
                m -= array[0][j];
                sum += (float) array[1][j];
                array[1][j] = 0;
            }
        }

        /* Displays the total profit calculated */
        System.out.println("Total Profit " + sum);

        sc.close();
    }
}