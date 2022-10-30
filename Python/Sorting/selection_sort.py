def sort(list1):
    
    for i in range(num-1):
        minpos = i;
        for j in range(i,num):
            if list1[j] < list1[minpos]:
                minpos = j
                
        temp = list1[j]
        list1[i] = list1[minpos]
        list1[minpos] = temp
        
        print(list1)
        
        
list1 = [] 
num = int(input("ENTER THE NUMBER OF ELEMENTS : "))
for i in range(0, num):
    element = int(input())  
    list1.append(element)       
print(list1)

sort(list1)
print("SORTED LIST : ", list1)