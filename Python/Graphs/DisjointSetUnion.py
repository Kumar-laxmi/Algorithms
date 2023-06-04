class DSU:
     
    
    # Constructor
    def __init__(self, n):
        # Declaring two arrays to hold
        # information about parent and 
        # rank of each node. 
        #           &
        # Defining size of the arrays.
        # Initializing their values 
        # by is and 0s.
        self.parent = [i for i in range(n)]
        self.rank = [0 for i in range(n)]
        
        # for i in range(n):
        #     self.parent.add(i)
        #     self.rank.add(0);
        
    
    # Find function
    def find(self, node):
        
        # If the node is the parent of 
        # itself then it is the leader 
        # of the tree. 
        if(node==self.parent[node]):
            return node
        
        #Else, finding parent and also 
        # compressing the paths.
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]
    
    # Union function 
    def union(self,u, v):
        
        # Make u as a leader 
        # of its tree.
        u=self.find(u)
        
        # Make v as a leader 
        # of its tree.
        v=self.find(v)
        
        # If u and v are not equal,
        # because if they are equal then
        # it means they are already in 
        # same tree and it does not make 
        # sense to perform union operation.
        if(u!=v):
            # Checking tree with 
            # smaller depth/height.
            if(self.rank[u]<self.rank[v]):
                temp=u
                u=v
                v=temp

            # Attaching lower rank tree
            # to the higher one. 
            self.parent[v]=u
            
            # If now ranks are equal
            # increasing rank of u. 
            if(self.rank[u]==self.rank[v]):
                self.rank[u]=self.rank[u]+1