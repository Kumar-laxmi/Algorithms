 •INTRODUCTION
 
 The traveling salesman problem (TSP) is an algorithmic problem tasked with finding the shortest route between a set of points and locations that must be visited. 
 In the problem statement, the points are the cities a salesperson might visit. The salesman‘s goal is to keep both the travel costs and the distance traveled as 
 low as possible.
 
 •PROBLEM STATEMENT
 
 A traveler needs to visit all the cities from a list, where distances between all the cities are known and each city should be visited just once. What is the
 shortest possible route that he visits each city exactly once and returns to the origin city?
 
•ALGORITHM : TRAVELLING SALESMAN PROBLEM
 
      C ({1}, 1) = 0  

      for s = 2 to n do

      for all subsets S Є {1, 2, 3, … , n} of size s and containing 1
   
      C (S, 1) = ∞
      
      for all j Є S and j ≠ 1
   
      C (S, j) = min {C (S – {j}, i) + d(i, j) for i Є S and i ≠ j} 
      
      Return minj C ({1, 2, 3, …, n}, j) + d(j, i) 
      

•COMPLEXITY

1)Time Complexity: There are a total of 2N subproblems for each node. So the total number of subproblems would be N*2N. Each of the sub-problems requires linear time

to solve. If the origin node is not specified, we have to run loops for N nodes.

So the total time complexity for an optimal solution would be the Number of nodes * Number of subproblems * time to solve each sub-problem. The time complexity can be

defined as O(N2 * 2^N).

2)Space Complexity: The dynamic programming approach uses memory to store C(S, i), where S is a subset of the vertices set. There is a total of 2N subsets for each

node.

So, the space complexity is O(2^N).

