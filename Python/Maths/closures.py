

# In this program, we are trying to find the closures of a relation(symmetric, reflexive and transitive closure).
# Closure of a relation is the smallest relation which contains original relation and follows the desired property.

# The relation is represented using a n x n matrix where n represents size of set on which relation is defined.
# For every pair (a,b) in relation, we set value at (a,b) indices to 1 in the matrix value else 0.
# For reflexive closure, we need to make sure that all (a,a) pairs are present
# So we set all values at (a,a) indices in matrix to 1.
# For symmetric closure, we need to make sure that for every (a,b) pair we have (b,a) pair.
# So we set all (b,a) indices to 1 where (a,b) indices is set to 1.
# For transitive closure, we use Warshall algorithm.
# Warshall algorithm first detects the transitive edges through first element then considering first 2 elements and so on upto the size of matrix.

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
