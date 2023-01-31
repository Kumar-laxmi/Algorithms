memory = []
for i in range(20):
    memory.append(-1)

def fibbo(num):
    if num == 0:
        return 0
    if num == 1:
        return 1

    if memory[num] != -1:
        return memory[num]
    
    memory[num] = fibbo(n-1) + fibbo(n-2)
    return memory[num]

print(fib(8))