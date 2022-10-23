def sort(list1):
    for i in range(len(list1)-1,0,-1):
        for j in range(i):
            if list1[j]>list1[j+1]:
                temp = list1[j]
                list1[j] = list1[j+1]
                list1[j+1] = temp
                


list1 = [] 
num = int(input("ENTER THE NUMBER OF ELEMENTS : "))
for i in range(0, num):
    element = int(input())  
    list1.append(element)       
print(list1)

sort(list1)
print("SORTED LIST : ", list1)
