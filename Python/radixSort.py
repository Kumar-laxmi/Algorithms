def csort(ip_array, i, arr_len):
    output = [0] * (arr_len)
    temp = [0] * (10)
    for ele in range(0, arr_len):
        idx = (ip_array[ele]/i)
        temp[int((idx)%10)] += 1

    for ele in range(1,10):
        temp[ele] += temp[ele-1]

    ele = arr_len-1
    while ele >= 0:
        idx = (ip_array[ele]/i)
        output[ temp[ int((idx)%10) ] - 1] = ip_array[ele]
        temp[int((idx)%10)] -= 1
        ele -= 1


    ele = 0
    for ele in range(0,len(ip_array)):
        ip_array[ele] = output[ele]
def sort(ip_array):
    max_ele = max(ip_array)
    i = 1
    while max_ele/i > 0:
        csort(ip_array,i, len(ip_array))
        i *= 10
       
ip_arr = [78,88,99,199,101]
sort(ip_arr)
print("The sorted array is :")
for i in range(len(ip_arr)):
    print(ip_arr[i])
