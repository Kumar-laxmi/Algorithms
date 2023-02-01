def displayRelation(relation,n):
    # Displaying relation
    first = True
    print("{", end='')
    for i in range(n):
        for j in range(n):
            if relation[i][j] == 1:
                if not first:
                    print(",", end='')
                print("({},{})".format(i,j), end='')
                first = False
    print("}")

def reflexiveClosure(relation,n):
    # Creating a copy of original relation so it does not modify original
    relation = [row[:] for row in relation]
    
    for i in range(n):
        #  Setting all (i,i) pairs to 1
        relation[i][i] = 1
    print("Reflexive closure: ", end='')
    displayRelation(relation,n)

def symmetricClosure(relation,n):
    relation = [row[:] for row in relation]
    for i in range(n):
        for j in range(n):
            if relation[i][j] == 1 and relation[j][i] == 0:
                # Setting (j,i) pair to 1 for every (i,j) pair
                relation[j][i] = 1
    print("Symmetric closure: ", end='')
    displayRelation(relation,n)

def transitiveClosure(relation,n):
    # Using warshall algorithm
    relation = [row[:] for row in relation]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                # if transitive edge through k then add it to relation
                if relation[i][k] == 1 and relation[k][j] == 1:
                    relation[i][j] = 1
    print("Transitive closure: ", end='')
    displayRelation(relation,n)

    

n = int(input("Enter no of elements in set on which relation is: "))
print("Elements are from 0 to {}".format(n-1))
relation = [[0]*n for i in range(n)]

ch = 'y'
while ch == 'y' or ch == 'Y':
    x,y = map(int, input("Enter pair (x,y): ").split())
    if x<0 or x>=n or y<0 or y>=n:
        print("Invalid pair")
    else:
        relation[x][y] = 1
    ch = input("Do u want to continue(Y/y): ")

print("Relation is ", end='')
displayRelation(relation,n)
reflexiveClosure(relation,n)
symmetricClosure(relation,n)
transitiveClosure(relation,n)
