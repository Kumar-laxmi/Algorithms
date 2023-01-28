#Name :  Garv Saxena
#Github : Volcano-Dragon
#Repositary name : Algorithms
#Problem Statement: Next Greater Element Using Stack In Python

from collections import deque
stack, found = deque([3, 2, 8, 7, 9, 17, 12]), 0

for i in range(-1,-1*(len(stack)+1),-1):
    for j in range(i+1,0):
        found = 0
        if stack[i] < stack[j]:
            print(f"{stack[i]} -- {stack[j]}")
            found = 1
            break
    if found == 0:
         print(f"{stack[i]} -- -1")
