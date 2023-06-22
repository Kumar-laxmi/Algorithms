# MColoring Algorithm in python 
def isSafe(graph, color):
 
    for i in range(4):
        for j in range(i + 1, 4):
            if (graph[i][j] and color[j] == color[i]):
                return False
    return True

def MColoring(graph, m, i, color):
 
    # if current index reached end
    if (i == 4):   
 
    
        if (isSafe(graph, color)):
 
      
            printSolution(color)
            return True
        return False
 
    # Give color from 1 to m
    for j in range(1, m + 1):
        color[i] = j
 
       
        if (MColoring(graph, m, i + 1, color)):
            return True
        color[i] = 0   #given color does not reach to solution ,remove color
    return False

def printSolution(color):
    print("Solution Exists:" " The colors assigned to vertices are:   ")
    for i in range(4):
        print(color[i], end=" ")

if __name__ == '__main__':
    # /* Given Graph  and  m = 3
    #  (3)---(2)
    #  |   / |
    #  |  /  |
    #  | /   |
    # (0)---(1)
    # */
      graph = [
        [0, 1, 1, 1],
        [1, 0, 1, 0],
        [1, 1, 0, 1],
        [1, 0, 1, 0],
      ]
      m = 3  # Number of colors

      color = [0 for i in range(4)]   #color initailized with 0
    
      if (not MColoring(graph, m, 0, color)):       
         print("Solution does not exist")
    