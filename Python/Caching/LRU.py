def pageFaults(pages, n, capacity):
	s = set()
	indexes = {}
	page_faults = 0
	for i in range(n):
		if len(s) < capacity:
			if pages[i] not in s:
				s.add(pages[i])
				page_faults += 1
			indexes[pages[i]] = i
		else:
			if pages[i] not in s:
				lru = float('inf')
				for page in s:
					if indexes[page] < lru:
						lru = indexes[page]
						val = page
				s.remove(val)
				s.add(pages[i])
				page_faults += 1
			indexes[pages[i]] = i
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

