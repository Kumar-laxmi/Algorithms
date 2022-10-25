def sort(list1):
    #slection sort
    for i in range(len(list1)-1,0,-1):
        for j in range(i):
            if list1[j]>list1[j+1]:
                temp = list1[j]
                list1[j] = list1[j+1]
                list1[j+1] = temp
                

#Taking list input
list1 = [] 
num = int(input("ENTER THE NUMBER OF ELEMENTS : "))
for i in range(0, num):
    element = int(input())  
    list1.append(element)       
print(list1)

#Function call
sort(list1)

#Printing sorted array
print("SORTED LIST : ", list1)
