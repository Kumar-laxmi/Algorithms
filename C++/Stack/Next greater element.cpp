
/*
PROBLEM STATEMENT

Given an array, print the Next Greater Element (NGE) for every element using stack. 

The Next Greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1. 

Example: 

Input: arr[] = [ 4 , 5 , 2 , 25 ]
Output: 4 –> 5
        5 –> 25
        2 –> 25
        25 –> -1

Explanation: except 25 every element has an element greater than them present on the right side
*/

#include <bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all
elements of arr[] of size n */
void printNGE(int arr[], int n)
{
    stack<int> s;

    for (int i = 0; i < n; i++) {
        /* if stack is not empty, then
           pop an element from stack.
           If the popped element is smaller
           than next, then
        a) print the pair
        b) keep popping while elements are
        smaller and stack is not empty */
        while (!s.empty() && s.top() < arr[i]) {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }
        /* push next to stack so that we can find
        next greater for it */
        s.push(arr[i]);
    }
 
    /* After iterating over the loop, the remaining
    elements in stack do not have the next greater
    element, so print -1 for them */
    while (!s.empty()) {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

int main()
{
    int n;  
    cin>>n;     //taking input the number of elements in the array
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];                //taking input of all the elements of the array
    }

    /*calling the printNGE to print the next
    greater element of all the elements of
    the array*/
    printNGE(arr, n);

    return 0;
}