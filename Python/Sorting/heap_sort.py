# max heap
def heapify(ar, n, i):
    maxIdx = i
    leftChild, rightChild = 2 * i + 1, 2 * i + 2
    # left child greater than root
    if leftChild < n and ar[leftChild] > ar[maxIdx]:
        maxIdx = leftChild
    # right child greater than root
    if rightChild < n and ar[rightChild] > ar[maxIdx]:
        maxIdx = rightChild

    #swap and heapify until max ele not found
    if maxIdx != i:
        ar[i], ar[maxIdx] = ar[maxIdx], ar[i]
        heapify(ar, n, maxIdx)

def heapSort(ar):
    n = len(ar)
    # max heapify
    for i in range(n // 2 - 1, -1, -1):
        heapify(ar, n, i)
    # heap sort
    for i in range(n - 1, 0, -1):
        ar[i], ar[0] = ar[0], ar[i]
        heapify(ar, i, 0)

# main method
def main():
    # input code
    n = int(input("Enter array size : "))
    print("Enter array elements :", end=" ")
    ar = [int(i) for i in input().split()][:n]

    # function call
    heapSort(ar)
    # display sorted array
    print("Sorted Array :", end=" ")
    for i in ar:
        print(i, end=" ")

# main method call
main()