def waveSort(arr):
    i = 0
    n = len(arr)
    while(i < n):
        if arr[i] > arr[i-1]:
            arr[i],arr[i-1] = arr[i-1], arr[i]
    
        if (i <= (n - 2))and(arr[i] > arr[i+1]) :
            arr[i],arr[i+1] = arr[i+1],arr[i]
        i+=2
    print(arr)

def main():
    arr = [10, 5, 6, 3, 2, 20, 100, 80]
    waveSort(arr)
    

if __name__ == "__main__":
    main()