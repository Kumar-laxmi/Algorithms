import random
import time
import pandas as pd
data= pd.read_csv("Stock data.csv")
df = pd.DataFrame(data)
a=df['High'].to_numpy()
n=len(a)
def Linear(a, start, end):
    Min = Max = a[start]
    for i in range(start, end):
        if a[i] < Min:
            Min = a[i]
        if a[i] > Max:
            Max = a[i]

    return (Min, Max)

def DCMaxMin(a, start, end):
    if end - start <= 1:
        if a[start] > a[end]:
            return (a[start], a[end])
        else:
            return (a[end], a[start])
    else:
        mid = int((start+end)/2)
        LMin, LMax = DCMaxMin(a, int(start), int(mid))
        RMin, RMax = DCMaxMin(a, int(mid+1), int(end))
        
        if LMin < RMin:
                min = LMin
        else:
                min = RMin

        if LMax > RMax:
                max = LMax
        else:
                max = RMax

        return (min, max)

start1 = time.perf_counter()
Min1, Max1 = DCMaxMin(a, int(0), int(n-1))
end1 = time.perf_counter()
start2 = time.perf_counter()
Min2, Max2 = Linear(a, 0, n-1)
end2 = time.perf_counter()
    
print(f'Linear Approach: Min = {Min2}, Max = {Max2}, Time required = {end2 - start2}')
print(f'DAC Approach: Min = {Min1}, Max = {Max1}, Time required = {end1 - start1}')
print()