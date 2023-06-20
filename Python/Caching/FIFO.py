from queue import Queue
def pageFaults(pages, n, capacity):
	s = set()
	indexes = Queue()
	page_faults = 0
	for i in range(n):
		if (len(s) < capacity):
			if (pages[i] not in s):
				s.add(pages[i])
				page_faults += 1
				indexes.put(pages[i])
		else:
			if (pages[i] not in s):
				val = indexes.queue[0]
				indexes.get()
				s.remove(val)
				s.add(pages[i])
				indexes.put(pages[i])
				page_faults += 1

	return page_faults

print("Enter the length of array: ")
n=int(input())
pages=[]
print("Enter the elements of array")
for i in range(n):
    pages.append(int(input()))
print("Enter the capacity")
capacity=int(input())
print("Answer:")
print(pageFaults(pages, n, capacity))

