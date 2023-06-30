public class Fenwick_Tree {
    private int[] tree;

    public Fenwick_Tree(int size){
        this.tree = new int[size +1];  // we added 1 to the size to create a 1-indexed tree
    }

    /*in the next method we have 2 parameters: 
        index - which represents the position to update
        toAdd - which is the amt to add to the existing value at the index
    */
     public void next(int index , int toAdd){
        while( index < tree.length){
            tree[index] += toAdd;
            index += (index & -index);  //it'll move to the next index with a different last set bit
        }
    }

    //this method is used to calculate the prefix sum up to a given index
    public int query(int index){
        int sum = 0;
        while(index > 0){
            sum += tree[index];
            index -= (index & -index);  //it'll move to the parent index by clearing the last set bit
        }
        return sum;
    }

    public static void main(String[] args){
        int[] array = {1, 9, 6, 8, 3, -5, -3, -9, 7, 1, 6, 8};
        int n = array.length;

        Fenwick_Tree fTree = new Fenwick_Tree(n);

        //building the Fenwick tree
        for(int i = 0; i < n; i++){
            fTree.next(i + 1, array[i]);
        }

        //prefix sum from index 1 to 5
        int pSum = fTree.query(5);
        System.out.println("Prefix sum from index 1 to 5:  "  + pSum);

        //updating value at index 2 to 11
        fTree.next(2,11);
    }
}
