import heapq

# huffman tree node
class node:
    def __init__(self, freq, char, leftNode=None, rightNode=None):
        # char freq
        self.freq = freq
        # char name (character)
        self.char = char
        # left node
        self.leftNode = leftNode
        # right node
        self.rightNode = rightNode
        # tree direction (0/1)
        self.huff = ''

    def __lt__(self, nxt):
        return self.freq < nxt.freq


# print huffman codes
def printNodes(node, val=''):
    # current node huffman code
    newVal = val + str(node.huff)

    # if node is not an edge node
    # then traverse inside it
    if(node.leftNode):
        printNodes(node.leftNode, newVal)
    if(node.rightNode):
        printNodes(node.rightNode, newVal)

        # if node is edge node then
        # display its huffman code
    if(not node.leftNode and not node.rightNode):
        print(f"{node.char} -> {newVal}")


def main():
    # characters
    chars = ['a', 'b', 'c', 'd', 'e', 'f']

    # characters' freq
    freq = [5, 9, 12, 13, 16, 45]

    # list having unused nodes
    nodes = []

    # convert char & freq. into huffman tree nodes
    for x in range(len(chars)):
        heapq.heappush(nodes, node(freq[x], chars[x]))

    while len(nodes) > 1:
        # sort nodes in inc. order based on freq.
        leftNode = heapq.heappop(nodes)
        rightNode = heapq.heappop(nodes)

        # directional values to nodes
        leftNode.huff = 0
        rightNode.huff = 1

        # add the 2 nodes to create new parent node
        newNode = node(leftNode.freq+rightNode.freq, leftNode.char + rightNode.char, leftNode, rightNode)
        heapq.heappush(nodes, newNode)

    printNodes(nodes[0])

main()