def get_next_gap(gap):
    gap = (gap * 10) // 13
    if gap < 1:
        return 1
    return gap
def comb_sort(a):
    n = len(a)
    gap = n
    swapped = True
    while gap != 1 or swapped:
        gap = get_next_gap(gap)
        swapped = False
        for i in range(n - gap):
            if a[i] > a[i + gap]:
                a[i], a[i + gap] = a[i + gap], a[i]
                swapped = True
if __name__ == "__main__":
    n = int(input("Enter the length of the array: "))
    a = []
    print("Enter the elements of the array:")
    for _ in range(n):
        element = int(input())
        a.append(element)
    print("Original array:")
    print(*a)
    comb_sort(a)
    print("Sorted array:")
    print(*a)
