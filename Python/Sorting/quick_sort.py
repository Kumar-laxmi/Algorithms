import pandas as pd
import time

def quicksort(A, low, high):
    if(low<high):
        pi = partition(A, low, high)
        quicksort(A, low, pi-1)
        quicksort(A, pi+1, high)
    return A

def partition(A, low, high):
    pivot = A[high]
    i = low-1
    for j in range(low, high):
        if(A[j]<pivot):
            i+=1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[high] = A[high], A[i+1]
    return i+1

data= pd.read_csv("Stock data.csv")
df = pd.DataFrame(data)
le = ['Open','High','Low','Close']
T = []
for i in range(len(le)):
    A=df[le[i]].to_numpy()
    low = 0
    high = len(A)-1
    Start_time = time.perf_counter()
    # print(quicksort(A, low, high))
    End_time= time.perf_counter()
    t = End_time - Start_time
    print("Time taken to sort ", le[i], "is: ", t)
    T.append(t)
    print()

print("Attribute \t time")
print("===============================")
for i in range(len(le)):
    print(le[i],"\t", T[i])
