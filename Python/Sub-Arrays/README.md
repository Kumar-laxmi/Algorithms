# Algorithms on Sub-Arrays

## 1. Boyer-Moore majority voting algorithm

This script takes a list of integers as input and finds the majority element.  
The majority element is defined as the element with number of occurances greater than N/2,  
where N is the length of the array. If no majority element is present, it displays None.  
Comparison of time and space complexity:

1. Brute force approach: O(n^2) time and O(1) space
2. Map approach: O(n) time and O(n) space
3. Boyer-Moore algorithm: O(n) time and O(1) space

Reference: [topcoder - Boyer-Moore majority vote algorithm](https://www.topcoder.com/thrive/articles/boyer-moore-majority-vote-algorithm)  
Python: 3.10.8  
External packages: None
