class DSU{
     
    // Declaring two arrays to hold
    // information about parent and 
    // rank of each node. 
    int *parent;
    int *rank;
public:
    // Constructor
    DSU(int n){
        
        // Defining size of the arrays.
        parent=new int[n];
        rank=new int[n];
        
        // Initializing their values 
        // by is and 0s.
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    // Find function
    int find(int node){
        
        // If the node is the parent of 
        // itself then it is the leader 
        // of the tree. 
        if(node==parent[node]) return node;
        
        //Else, finding parent and also 
        // compressing the paths.
        return parent[node]=find(parent[node]);
    }
    
    // Union function 
     void Union(int u,int v){
        
        // Make u as a leader 
        // of its tree.
        u=find(u);
        
        // Make v as a leader 
        // of its tree.
        v=find(v);
        
        // If u and v are not equal,
        // because if they are equal then
        // it means they are already in 
        // same tree and it does not make 
        // sense to perform union operation.
        if(u!=v)
        {
            // Checking tree with 
            // smaller depth/height.
            if(rank[u]<rank[v])
            {
                int temp=u;
                u=v;
                v=temp;
            }
            // Attaching lower rank tree
            // to the higher one. 
            parent[v]=u;
            
            // If now ranks are equal
            // increasing rank of u. 
            if(rank[u]==rank[v])
                rank[u]++;
        }
    }
};