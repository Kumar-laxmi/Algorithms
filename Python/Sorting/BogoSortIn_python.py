import random

def shuffle(arr):
    for i in range(len(arr)):
        j = random.randrange(len(arr))
        t = arr[i]
        arr[i] = arr[j]
        arr[j] = t

def is_sorted(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i - 1]:
            return False
    return True

def bogosort(arr):
    randShuffles = 0
    while not is_sorted(arr):
        shuffle(arr)
        randShuffles += 1
    print("Number of randShuffles:", randShuffles)

def main():
    arr = [random.randint(0, 100) for _ in range(10)]
    print("The unsorted arr is:", arr)
    bogosort(arr)
    print("The sorted arr is:", arr)

if __name__ == "__main__":
    main()
