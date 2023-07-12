def bingoSort(arr):
    min_val = min(arr)
    max_val = max(arr)

    flags = [0] * (max_val - min_val + 1)
    for num in arr:
        flags[num - min_val] = 1

    sorted_arr = []
    for i in range(len(flags)):
        if flags[i]:
            sorted_arr.append(i + min_val)

    return sorted_arr


def main():
    n = int(input("Enter the length of the array: "))
    a = []
    print("Enter the elements of the array:")
    for _ in range(n):
        num = int(input())
        a.append(num)

    print("Original array:")
    for num in a:
        print(num, end=" ")

    sorted_arr = bingoSort(a)

    print("\nSorted array:")
    for num in sorted_arr:
        print(num, end=" ")


if __name__ == "__main__":
    main()
