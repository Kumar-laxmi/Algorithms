def MaxActivities(arr, n):
    selected = []
    # Sort jobs according to finish time
    Activity.sort(key=lambda x: x[1])
    # The first activity always gets selected
    i = 0
    selected.append(arr[i])
    for j in range(1, n):
        '''If this activity has start time greater than or
           equal to the finish time of previously selected
           activity, then select it'''
        if arr[j][0] >= arr[i][1]:
            selected.append(arr[j])
            i = j
    return selected
 
# Driver code
if __name__ == '__main__':
    print("Enter no. of elements")
    n=int(input())
    print("Enter the starting and ending time as integer elements")
    Activity=[]
    for i in range(n):
        a=[]
        for j in range(2):
            a.append(int(input()))
        Activity.append(a)

    # Function call
    selected = MaxActivities(Activity, n)
    print("Following activities are selected :")
    print(selected[0], end = "")
    for i in range (1, len(selected)):
        print(",", end = " ")
        print(selected[i], end = "")
 