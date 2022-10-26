def Sort(a, n):
    for i in range(1, n):
        k = a[i]
        j = i - 1
        
        while j>=0 and a[j] > k:
            a[j+1] = a[j]
            j = j-1
        a[j+1] = k
        
    for i in range(0, n):
        print(a[i], " ")
        
        
arr = [45, 55, 20, 3, 5]
n = len(arr)
Sort(arr, n)