from ast import For
from email.policy import strict
import heapq


while(True):
    chars = []
    nodes = []
    freq = []
    MyText = input(f"_")
    msg = MyText
    msgset = set(msg)
    
    count = 0

    for j in msgset:
        for i in msg:
            if i == j:
                count = count + 1
        chars.append(j)
        freq.append(count)
        count=0

    # print(chars)
    # print(freq)

    class node:
        def __init__(self, freq, symbol, left=None, right=None):
            self.freq = freq
            self.symbol = symbol
            self.left = left
            self.right = right
            self.huff = ''
            
        def __lt__(self, nxt):
            return self.freq < nxt.freq
            
        
    def add_element(dict, key, value):
        if key not in dict:
            dict[key] = []
        dict[key].append(value)

    Dict = {} 

    def printNodes(msg,node, val=''):
            

        newVal = val + str(node.huff)

        if(node.left):
            printNodes(msg,node.left, newVal)
                    
        if(node.right):
            printNodes(msg,node.right, newVal)

        if(not node.left and not node.right):
                    
                    print(f"{node.symbol} -> {newVal}")
                    # print(msg)
                    add_element(Dict,f"{node.symbol}",f"{newVal}")

    for x in range(len(chars)):
        heapq.heappush(nodes, node(freq[x], chars[x]))

    while len(nodes) > 1:
        
        left = heapq.heappop(nodes)
        right = heapq.heappop(nodes)

        left.huff = 0
        right.huff = 1

        newNode = node(left.freq+right.freq, left.symbol+right.symbol, left, right)

        heapq.heappush(nodes, newNode)

    printNodes(msg,nodes[0])

    # print(Dict)

    for i,j in Dict.items():
            msg = msg.replace(f"{i}",f"{j[0]}")

    print(MyText+" -> "+msg)