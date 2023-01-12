// ==================== PROBLEM STATEMENT =========================

/*
The Subset Sum problem is a problem in computer science that involves finding a subset 
of a given set of integers such that the sum of the elements in the subset is a given 
target value.

The problem can be formulated as follows:

Input:

A set of integers S
An integer target

Output:

true if there exists a subset of S that sums to target, and false otherwise.
For example, given the set S = {1, 2, 3, 4, 5} and the target value target = 9, 
the solution to the Subset Sum problem is true, because the subset {4, 5} sums to 9.
*/

// =================== CODE =================================

#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int>& nums, int target, int index) {
  if (target == 0) return true;
  if (index == nums.size()) return false;
  return dfs(nums, target - nums[index], index + 1) || dfs(nums, target, index + 1);
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  int target = 9;
  cout << (dfs(nums, target, 0) ? "Subset found" : "No subset found") << endl;
  return 0;
}
