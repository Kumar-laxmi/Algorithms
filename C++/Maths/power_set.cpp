//Program to generate power set of a set of elements in C++ language.

/*In C++, we can calculate the power set of a set of elements using a combination of
 recursion and bitwise operations. Here's an approach and explanation of how to implement it:*/


 //APPROACH AND EXPLANATION

/*In the above code, the powerSet function calculates the size of the power set using the formula 2^N, 
where N is the size of the input set. It then iterates from 0 to powerSetSize - 1 and uses bitwise operations
to check which elements should be included in the subset.
The bitwise operation i & (1 << j) checks if the j-th bit of i is set (1). 
If it is, the j-th element of the input set is included in the current subset.
The resulting subsets are stored in the result vector, which is then returned by the function. 
In the main function, the subsets are printed using nested loops, with the outer loop iterating 
over each subset and the inner loop printing each element of the subset.*/


//  Start by including the necessary headers in our C++ program:


#include <iostream>
#include <vector>
#include <cmath>

/*Define a function that calculates the power set. This function will take the input set and return a
 vector of vectors representing the power set. Each inner vector will contain a subset of the input set.*/

  std::vector<std::vector<int>> powerSet(const std::vector<int>& set) {
  std::vector<std::vector<int>> result;
  int setSize = set.size();
  int powerSetSize = pow(2, setSize);

  for (int i = 0; i < powerSetSize; i++) {
    std::vector<int> subset;
    for (int j = 0; j < setSize; j++) {
      if (i & (1 << j)) {
        subset.push_back(set[j]);
      }
    }
    result.push_back(subset);
  }

  return result;
}
  /*In the main function, create an example set and call the powerSet function
   to calculate the power set. Then, iterate over the result and print each subset.*/

int main() {
  std::vector<int> set = {1, 2, 3};
  std::vector<std::vector<int>> result = powerSet(set);

  std::cout << "Power Set:" << std::endl;
  for (const auto& subset : result) {
    std::cout << "{ ";
    for (const auto& element : subset) {
      std::cout << element << " ";
    }
    std::cout << "}" << std::endl;
  }

  return 0;
}







