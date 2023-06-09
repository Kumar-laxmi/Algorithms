
// ========================== Problem Statement ===========================

/*
Bounded 0-1 knapsack
(Bounded means there are limited amount of each type of items,
    here consider there are exactly one item of each type)
    
You are given a set of items, each with a weight and a value. 
You are also given a knapsack with a certain capacity. Your goal 
is to maximize the total value of items that you can put in the 
knapsack, subject to the constraint that the total weight of the 
items must not exceed the capacity of the knapsack.
For example, suppose you have the following set of items:
Item	Value	Weight
1	100	20
2	180	30
3	260	10
4	310	5
5	40	25
6	535	15
7	695	30
8	860	45
9	920	50
10	220	10
The capacity of the knapsack is 200. Your goal is to choose a subset 
of these items such that the total value is maximized, and the total 
weight is less than or equal to 200.
The 0/1 in the name refers to the fact that each item must either be 
included or excluded (as opposed to a fractional knapsack problem, 
where you can include a fraction of an item).
*/
public class _01_knapsack {

    public static int knapsack(int[] values, int[] weights, int capacity) {
        int totalItems = values.length;

        int maximumValue = 0;

        // * get the maximum value using recursive approach
        // maximumValue = recursion(totalItems - 1, values, weights, capacity);

        // * get the maximum value using memoization approach
        // int[][] dp = new int[totalItems + 1][capacity + 1];
        // for (int i = 0; i <= totalItems; i++) {
        // for (int j = 0; j <= capacity; j++) {
        // dp[i][j] = -1;
        // }
        // }
        // maximumValue = memoization(totalItems - 1, values, weights, capacity, dp);

        // * get the maximum value using tabulation approach
        // maximumValue = tabulation(values, weights, capacity);

        // * get the maximum value using spaceOptimized approach
        maximumValue = spaceOptimization(values, weights, capacity);

        return maximumValue;
    }

    // top down approach
    // time complexity: exponential
    // space complexity: 1
    // either we pick and item or we don't
    private static int recursion(int currentItem, int[] values, int[] weights, int capacity) {
        // (currentItem < 0) means we have considered every item
        // and nothing can be added any further
        if (currentItem < 0)
            return 0;

        // for each item we have two possibilities
        // to pick or to not pick
        int pick = 0;
        int notPick = 0;

        // if the weight of the currentItem is more than the capacity
        // then we can not pick it
        if (weights[currentItem] <= capacity) {
            pick = values[currentItem] + recursion(currentItem - 1, values, weights, capacity - weights[currentItem]);
        }
        notPick = recursion(currentItem - 1, values, weights, capacity);

        // maximum value of pick and notPick is return to maximize the value
        return (pick > notPick) ? pick : notPick;
    }

    // dp[x][y] = maximum value that can be achieved with x items and y bag capacity

    // top down approach
    // time complexity: O(totalItems^2)
    // space complexity: O(totalItems*capacity)
    // everything is same as recursive approach, it's just that we are avoiding
    // duplicate calculation
    // by storing the previous calculation in a 2D array (dp)
    // this significantly improves the time complexity with respect to the recursive
    // approach
    private static int memoization(int currentItem, int[] values, int[] weights, int capacity, int[][] dp) {
        if (currentItem < 0)
            return 0;

        // (dp[currentItem][capacity] != -1) means the maximum value with current
        // capacity and the current
        // item is already been calculated and we don't have to calculate it again
        if (dp[currentItem][capacity] != -1)
            return dp[currentItem][capacity];

        // the rest goes same as the recursive approach
        int pick = 0;
        int notPick = 0;

        if (weights[currentItem] <= capacity) {
            pick = values[currentItem]
                    + memoization(currentItem - 1, values, weights, capacity - weights[currentItem], dp);
        }
        notPick = memoization(currentItem - 1, values, weights, capacity, dp);

        // here we are storing the maximum value with current capacity and the current
        // item which is begin calculated for the first time
        dp[currentItem][capacity] = (pick > notPick) ? pick : notPick;

        return dp[currentItem][capacity];
    }

    // bottom up approach
    // time complexity: O(totalItems^2)
    // space complexity: O(totalItems*capacity)
    // here we are calculating the maximum values for different items and capacity
    // from the bottom
    // it eliminates the auxilary stack space which is used by the memoization
    // approach
    private static int tabulation(int[] values, int[] weights, int capacity) {

        int totalItems = values.length;
        int[][] dp = new int[totalItems + 1][capacity + 1];

        // for every item, we check for different capacities possible
        // and store that data for further calculation
        // compare this portion of code with the memoization
        // instead of calling the memoization, we are simply getting the
        // previously calculated data from the dp
        for (int currentItem = 1; currentItem <= totalItems; currentItem++) {
            for (int currentCapacity = 0; currentCapacity <= capacity; currentCapacity++) {

                int pick = 0;
                int notPick = 0;

                if (weights[currentItem - 1] <= currentCapacity) {
                    pick = values[currentItem - 1]
                            + dp[currentItem - 1][currentCapacity - weights[currentItem - 1]];
                }
                notPick = dp[currentItem - 1][currentCapacity];

                dp[currentItem][currentCapacity] = (pick > notPick) ? pick : notPick;
            }
        }

        return dp[totalItems][capacity];
    }

    // bottom up approach
    // time complexity: O(totalItems^2)
    // space complexity: O(capacity)
    // here we are calculating the maximum values for different items and capacity
    // from the bottom
    // it reduces the space used during the execution from (totalItems*capacity)
    // to 2 arrays of size(capacity)
    private static int spaceOptimization(int[] values, int[] weights, int capacity) {
        int totalItems = values.length;

        // stores the calcutations for the previous item
        int[] prev = new int[capacity + 1];

        // similar to the tabulation approach
        for (int currentItem = 1; currentItem <= totalItems; currentItem++) {
            // stores the calcutations for the current item
            int[] curr = new int[capacity + 1];

            for (int currentCapacity = 0; currentCapacity <= capacity; currentCapacity++) {

                int pick = 0;
                int notPick = 0;

                if (weights[currentItem - 1] <= currentCapacity) {
                    pick = values[currentItem - 1]
                            + prev[currentCapacity - weights[currentItem - 1]];
                }
                notPick = prev[currentCapacity];

                curr[currentCapacity] = (pick > notPick) ? pick : notPick;
            }
            prev = curr;
        }

        return prev[capacity];
    }

    public static void main(String[] args) {

        // these are the values and weights of the items
        int values[] = { 100, 180, 260, 310, 40, 535, 695, 860, 920, 220 };
        int weights[] = { 20, 30, 10, 5, 25, 15, 30, 45, 50, 10 };

        // capacity of the bag
        int capacity = 200;

        // knapsack method find the maximum value that the bag can hold
        int maximumValue = knapsack(values, weights, capacity);

        // printTheResult is just a helper method to print the result in an organized
        // manner
        // it does not have any effect on the main knapsack code
        printTheResult(values, weights, capacity, maximumValue);
    }

    // just a helper method to print the result. It does not hold any significance
    // regarding the code
    private static void printTheResult(int[] values, int[] weights, int capacity, int maximumValue) {
        int n = values.length;
        System.out.println();
        System.out.println("Items available are as follows:");
        System.out.println();
        System.out.println("value\t : \tweight");
        for (int i = 0; i < n; i++) {
            System.out.println(values[i] + "\t : \t" + weights[i]);
        }
        System.out.println();
        System.out.println("The Capacity of the bag is " + capacity);
        System.out.println();
        System.out.println("The maximum value that can fit in bag is " + maximumValue);
        System.out.println();
    }

}
