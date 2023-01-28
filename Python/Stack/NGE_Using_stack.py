#Name :  Garv Saxena
#Github : https://github.com/Volcano-Dragon
#Repositary name : Algorithms
#Problem Statement: Print the Next Greater Element (NGE) for each element in an array using stack.

#Algorithms Explanation:-
'''
The first greater element in the array to the right of an element x is known as the Next Greater Element for that element.
Note:- When there is no greater element for an element, the next greater element is treated as -1

Example: 
Input: stack = [3, 2, 8, 7, 9, 17, 12]
Output: 
12 -- -1
17 -- -1
9 -- 17
7 -- 9
8 -- 9
2 -- 8
3 -- 8
There is no greater element on the right side of 12, so -1 is NGE; similarly, there is no greater element on the right side of 17, so -1 is NGE. 
'''

from collections import deque
#stack is the input array
#found is check varibale for NGE is found or not if NGE is found then found == 1; else 0

stack, found = deque([3, 2, 8, 7, 9, 17, 12]), 0
#                   |^---------------------^| is input stack

#NOte: if input stack is empty loop not starts
for i in range(-1,-1*(len(stack)+1),-1): #Takes the element and looks for NGE for it on right side of it.
    for j in range(i+1,0): #Loop for comparing all elements on the right side of the current element.
        found = 0
        if stack[i] < stack[j]:  #if current element is lesser then next element then that is NGE for that current element (So print it)
            print(f"{stack[i]} -- {stack[j]}") # stack[j] is NGE
            found = 1  #Becuase stack[i] < stack[j] (That means NGE found).
            break  
    if found == 0: #if no NGE found for the current element then NGE is (-1)
         print(f"{stack[i]} -- -1")
