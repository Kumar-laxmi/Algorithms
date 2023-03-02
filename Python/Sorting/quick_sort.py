#About quick sort
#Quick sort is a divide and conquer algorithm
#It picks an element as a pivot and partitions the given array around the picked pivot.

#function for getting the partition element
def partition(list1,low,high):
   i = ( low-1 )
   pivot = list1[high]# pivot element: Taking the last element as pivot element
   for j in range(low , high):
      # If current element is smaller
      if list1[j] <= pivot:
         # increment
         i = i+1
         list1[i],list1[j] = list1[j],list1[i]
   list1[i+1],list1[high] = list1[high],list1[i+1]
   return ( i+1 )


# sorting function
def quicksort(list1,low,high):
   if low < high:
      # index
      partitioning_element = partition(list1,low,high)
      # sort the partitions
      quicksort(list1, low, partitioning_element-1)
      quicksort(list1, partitioning_element+1, high)             

#function with only the list as the argument
def quick_sort(list1):
    quicksort(list1,0,len(list1)-1)

#Taking list input
list_to_be_sorted = [] 
num = int(input("ENTER THE NUMBER OF ELEMENTS : "))
for i in range(0, num):
    element = int(input())  
    list_to_be_sorted.append(element)       
print("INPUT/UNSORTED LIST : ",list_to_be_sorted)

#Function call
quick_sort(list_to_be_sorted)

#Printing sorted array
print("SORTED LIST : ", list_to_be_sorted)