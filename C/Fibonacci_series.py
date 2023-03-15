'''Recursion Implementation:
Recursion is a technique where a function calls itself to solve a problem.
This definition says that the nth term of the sequence is the sum of the (n-1)th and (n-2)th terms.
The base cases are when n equals 0 or 1, in which case the function returns n.
The Fibonacci sequence can be defined recursively as follows:'''

# Recursive Approach:
def fibonacci_series(n) -> int:

    if n<0:
        return("Your INPUT is wrong! Please change it")

    if n == 0:
        return 0
    
    if n == 1:
        return 1

    return(fibonacci_series(n-1) + fibonacci_series(n-2))

'''Dynamic Programming Implementation:
Dynamic programming (DP) is a technique for solving problems by breaking them down into smaller sub-problems and solving each sub-problem only once.
The DP solution for the Fibonacci sequence uses a table to store the intermediate results so that they can be reused to compute subsequent terms.'''

# Dynamic Programming Approach: 
dic = {0:0, 1:1}

def fibonacci_series(n) -> int:

    if n<0:
        return("Your INPUT is wrong! Please change it")

    if n in dic:
        return dic[n]
    
    else:
        dic[n] = fibonacci_series(n-1) + fibonacci_series(n-2)
        return dic[n]
    

def read_input()-> int:

    n = int(input("Give the nth term you want to find: "))
    return n
    

if __name__ == "__main__":
    n = read_input()
    num = fibonacci_series(n)
    print(f"The nth fibonacci series element is: {num}\n")
