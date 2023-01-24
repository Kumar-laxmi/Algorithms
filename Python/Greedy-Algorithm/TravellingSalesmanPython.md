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
      
•EXAMPLE

![image](https://user-images.githubusercontent.com/59620280/214214981-746cd44a-1315-447a-ab7f-9ac9c612ada3.png)

The following table is prepared based on above diagram:

           1	2	 3	 4
         1 0	10	15	20
         2 5	0	 9	 10
         3	6	13	0	 12
         4	8	8	 9	 0 
         
The minimum cost path is 35.

Start from cost {1, {2, 3, 4}, 1}, we get the minimum value for d [1, 2]. When s = 3, select the path from 1 to 2 (cost is 10) then go backwards. When s = 2, we get

the minimum value for d [4, 2]. Select the path from 2 to 4 (cost is 10) then go backwards.

When s = 1, we get the minimum value for d [4, 3]. Selecting path 4 to 3 (cost is 9), then we shall go to then go to s = Φ step. We get the minimum value for d [3, 1]

(cost is 6).   

![image](https://user-images.githubusercontent.com/59620280/214215355-a850b9b8-b158-4795-8b09-02216f4b8b21.png)


•PROGRAM

     from sys import maxsize
     from itertools, import permutations
     V = 4
     def tsp(graph, s):
	            vertex = []
	            for i in range(V):
		             if i != s:
			                    vertex.append(i)
         min_cost = maxsize
	            next_permutation=permutations(vertex)
	            for i in next_permutation:
		                   current_cost = 0
		                   k = s
		                   for j in i:
			                          current_cost += graph[k][j]
			                          k = j
		current_cost += graph[k][s]
		min_cost = min(min_cost, current_cost)
		return min_cost
     graph = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
		       s = 0
     print(tsp(graph, s))


•APPLICATION OF TRAVELLING SALESMAN PROBLEM
 
1)Planning, logistics, and manufacturing microchips: Chip insertion problems naturally arise in the microchip industry. Those problems can be planned as traveling

  salesman problems.
  
2)DNA sequencing: Slight modification of the traveling salesman problem can be used in DNA sequencing. Here, the cities represent the DNA fragments, and the distance

  represents the similarity measure between two DNA fragments.

3)Astronomy: The Travelling Salesman Problem is applied by astronomers to minimize the time spent observing various sources.

•COMPLEXITY

1)Time Complexity: There are a total of 2N subproblems for each node. So the total number of subproblems would be N*2N. Each of the sub-problems requires linear time

to solve. If the origin node is not specified, we have to run loops for N nodes.

So the total time complexity for an optimal solution would be the Number of nodes * Number of subproblems * time to solve each sub-problem. The time complexity can be

defined as O(N2 * 2^N).

2)Space Complexity: The dynamic programming approach uses memory to store C(S, i), where S is a subset of the vertices set. There is a total of 2N subsets for each

node.

So, the space complexity is O(2^N).
