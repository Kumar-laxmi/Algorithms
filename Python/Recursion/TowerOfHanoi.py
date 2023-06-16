"""
The Tower of Hanoi is a problem that involves moving n disks from one tower to another, 
following specific rules. 

It consists of three towers, usually labeled A, B, and C.

The puzzle starts with a number of disks of different sizes arranged in increasing order from top to bottom
(i.e. smallest on top and then so on...) on one tower, typically tower A. 

The objective is to move the entire stack of disks to another tower, following these rules:

Only one disk can be moved at a time.
Each move involves taking the top disk from one tower and placing it onto another tower.
The larger disk should never be placed on top of a smaller disk. The disks must always be arranged 
in decreasing order from bottom to top on any tower.

Algorithm: We will be using Recursion to solve this problem

S1: First we move top (n-1) disks from source(i.e. the starting tower) to helper(i.e. the middle tower)
S2: Now we are left with one disk at source which we will transfer directly to the destination(i.e. the last tower)
S3: Now we will move the (n-1) disk at the helper to the destination tower

"""


def display():
    num_disks = int(input("Enter the number of disks: "))
    process(num_disks,"A","B","C")
    #A, B, C are the names of the towers, starting from A and delivering all the disks to C



def process(n, src, helper, dest):
    if(n == 1): # base case
        print("Transfer disk" , n , "from" , src , "to" , dest)
        return 
    process(n-1,src,dest,helper)
    #moving the top (n-1) disks from A to B
    print("Transfer disk" , n , "from" , src , "to" , dest)
    #moving the remaining one disk from A to C
    process(n-1,helper,src,dest)
    #now moving the (n-1) disks on B to C

display()