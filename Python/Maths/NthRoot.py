# multiplying a given number 'm' , 'n' times
def product(m, n):
    p = 1.0
    for i in range(1, n + 1):
        p *= m
    return p

# returns the nth root using binary search
def NthRoot(n, x):
    low = 1.0
    high = x
    # loop runs until the difference between high and low reduces to 5 decimal places
    while high - low > 0.000001:
        mid = (high + low) / 2
        # If on multiplying middle value n times we get a value
        # which is greater than x then that implies the answer lies
        # before the middle value (hence high=mid)
        if product(mid, n) > x:
            high = mid
        else:
            low = mid
    return high

n, x = map(int, input("Enter the value of n and the number whose nth root has to be calculated: ").split())
result = NthRoot(n, x)
formatted_result = "{:.5f}".format(result)
print(f"{n}th root of {x} is: {formatted_result}")
