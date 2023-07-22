'''
------------------------------------- Lucas Lehmer Series -------------------------------------

Approach
1. In this series, 4 is the starting term i.e., 0th term

2. By considering 4 as the 0th terms, then calculate the nth term of lucas-lehmer series.

3. To calculate the nth term use the formula, ``` nextTerm = currentTerm * currentTerm - 2 ```

4. Using this formula, we can find the nth term of lucas-lehmer series.

Below is the implementation of lucas-lehmer series in PYTHON
'''

# Program starts

# Function to calculate the series upto the nth term
def LucasLehmer(n):

    # the 0th term of the series is 4.
    currentTerm = 4

    # create an array to store the terms.
    series = []

    # compute each term and add it to the array.
    series.append(currentTerm)

    for i in range(n):
        currentTerm = currentTerm * currentTerm - 2
        series.append(currentTerm)

    # print out the terms one by one.
    for i in range(n + 1):
        print("Term", i, ":", series[i])
    print('\n')

# Main driver function
if __name__=='__main__':
    # nth term upto which user want to display the lucas-lehmer series
    # Taking input from the user
    n = int(input("\nEnter the value of n: "))
    
    print(f"\n######## Lucas-Lehmer Series ########\n")

    # Function triggered to calculate the lucas-lehmer series upto the nth term
    LucasLehmer(n)
        
# This code is contributed by Avdhesh Varshney (https://github.com/Avdhesh-Varshney)
