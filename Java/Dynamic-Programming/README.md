# Dynamic Programming

# COIN CHANGE PROBLEM
- [Problem Statement](#problem-statement)
   -[Examples](#examples)
- [Explanation](#explanation)
- [Complexity](#complexity)

# Problem Statement

We are given an integer array coins[] of size n representing different types of currency and an integer sum, The task is to find the number of ways to make sum by using different combinations from coins[].
Note: Assume that you have an infinite supply of each type of coin.

## Constraints
1 <= sum, N <= 1000

## Examples

Example 1: 
Input: n = 3, sum = 4, coins [] = {1, 2, 3}
Output: 4

Example 2:
Input: n = 4, sum = 10, coins [] = {2, 5, 3, 6}
Output: 5

## Explanation

Since we are given an infinite supply of coins, we can pick any coin any number of times.

Let's understand with the 1st example.

Coins[] = {1,2,3} , sum = 4

So the total number of ways are

1. {1,1,1,1}
2. {1,1,2}
3. {2,2}
4. {1,3}

**Intuition**
We can only pick coin if they are less than or equal to the given sum.

**if** the coin <= sum, we will have two choices, either we pick it or we do not pick it.
**else**, we do not pick it.

**Dry Run**
In the first example, let's iterate from the end.

coins = {1,2,3}, sum = 4

(3<4) so we will have two options here:
**Case 1: When we pick 3**

picked = {3}, sum = 4-3 = 1

- we will stay at the same index because there might be possibility that it can be picked once again.

- now 3 > sum, so we can't pick it and we will move to the next coin which is 2. 2 can also not be picked because it is greater than the sum so we will move to the next coin which is 1. now since 1 is less than the sum, we will pick it and our first way of forming the sum from the given coins becomes:

**picked = {1,3}**

**Case 2: When we didn't pick 3**

if we didn't pick 3, we will move on to the next coin which is 2.

coins = {1,2,3} , sum = 4

- since (2<sum), it has two options, whether we pick it or not.
-  **let's say we pick 2**.

    picked = {2}, sum = 2

- Again we will stay at the same index because if it is less than sum, it can be picked again.
- let's say this time also we picked 2.

   **picked = {2,2}**, sum = 0

- suppose we didn't pick 2 in the second time, then we will move to the next coin which is 1.
- And it also has two choices whether we pick it or not as it is smaller than the sum which is 2.
- so this time we picked 1 and again picked one in next turn.

  **picked = {1,1,2}**, sum = 0
  
 -  **let's say we don't pick 2**

  - if we don't pick 2, we will move to the next coin which is 1.
  - coins = {1,2,3} , sum = 4
  - 1<4, so it can be picked again and again until sum becomes 0
  - so **picked = {1,1,1,1}**

So in this way we get all of the possible ways.

## Complexity

**Time Complexity** : O(sum*N)
**Space Complexity** : O(sum)
