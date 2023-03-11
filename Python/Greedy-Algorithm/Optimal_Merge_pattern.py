# ====================== Problem Statement ==========================
'''
Given n number of sorted files, the task is to find the minimum computations done to reach the Optimal Merge Pattern.
When two or more sorted files are to be merged altogether to form a single file, the minimum computations are done to reach this file are known as Optimal Merge Pattern

For example
Q If there are 5 files apply optimal merge pattern.(20,30,10,5,30).
Ans
Step 1: Sort files in ascending order of their sizes.
        x4 x3 x1 x2 x5
        5 10 20 30 50
Step 2: Pick the files of smaller size and merge them
        Merge x3 and x4 |z1|=5+10=15
        Merge z1 and x1|z2|=35
        Merge x2 and x5|z3|=60
        Merge z3 and z2=60+35=95
        Total no of moves= 205

205 is the minimum no of moves if we combine in different ways then moves will be greater than 205.

Approach

1)Sort files in ascending order of sizes.
2)Pick the files of smaller sizes and merge them.
'''

#====================== Code with Python ==========================

from heapq import heapify, heappush, heappop 

# Creating empty heap 
heap = [] 
heapify(heap) 

#function for finding min no of moves
def minmoves(size,lst):
    # Adding items to the heap using heappush function
    for i in range(0,size):
        heappush(heap, lst[i])
        
    count=0    
    while(len(heap)>1):
        temp=heappop(heap)
        temp1=heappop(heap)
        count+=temp+temp1
        heappush(heap,temp+temp1)
    return count

size=int(input("Enter no of files : "))
print("Enter the sizes of files : ")
files=list(map(int,input().split()))
files.sort()
print("Minimum no of moves : "+str(minmoves(size,files)))
