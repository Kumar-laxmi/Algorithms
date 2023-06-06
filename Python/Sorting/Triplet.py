#Name :  Atul Kumar
#Github username : atul1510
#Repositary name : Algorithms
# Problem Statement: C++ program to find find the minimum number of jumps to reach the other end of the array starting from the 0th index. 
# And if the end isn’t reachable, return -1 as the output.
#Example:Given an array and a value, find if there is a triplet in the array whose sum is equal to the given value. 
#If there is such a triplet present in the array, then print the triplet and return true. Else return false.
#EXAMPLES:
#1] Input: array = { 7, 10, 6, 14, 4, 9 }, sum = 25;
#Output: Triplet is 4, 7, 14 */
# Python program to find a triplet
def find_triplet(A, arr_size, sum):
    # Sort the elements of the array in ascending order
    A.sort()
    # Fix the first element of the triplet and find all other possible elements
    for i in range(arr_size - 2):
        # For the other two elements, start two index variables from two ends of the array and move them toward each other
        x = i + 1 # index of the first element of the remaining elements
        y = arr_size - 1 # index of the last element
        while x < y:
            # If the triplet's sum equals the given sum, print it and return True
            if A[i] + A[x] + A[y] == sum:
                print("Triplet is {}, {}, {}".format(A[i], A[x], A[y]))
                return True
            # If the triplet's sum is less than the given sum, move the left pointer to the right
            elif A[i] + A[x] + A[y] < sum:
                x += 1
            # If the triplet's sum is greater than the given sum, move the right pointer to the left
            else:
                y -= 1
    # If no triplet is found, return False
    return False
# Main function
if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))
    A = []
    print("Enter {} integers in the array:".format(n))
    for i in range(n):
        A.append(int(input()))
    sum = int(input("Enter the sum value: "))
    arr_size = len(A)
    found = find_triplet(A, arr_size, sum)
    if not found:
        print("No triplet found with the given sum.")