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

 
