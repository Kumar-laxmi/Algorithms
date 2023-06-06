import java.util.*;

public class TopologicalSortKahnsAlgorithm {



    static int [] topologicalSortAlgorithm(ArrayList<ArrayList<Integer>> adj, int v){


        /* get an answer array to store the answers wrt to index
        also get an inDegree array, which stores the counts of inward connections(which is initially 0

         */
        int []ans = new int[v];
        int index =0;
        int [] inDegree = new int[v];
        for(int i=0; i<v; i++){
            inDegree[i]=0;
        }


        //run a loop to detect the connection and increment it wrt its occurrence
        for(int i=0; i<v; i++){
            for(int j=0; j<adj.get(i).size(); i++){
                int connection = adj.get(i).get(j);
                inDegree[connection] ++;
            }
        }
        //if the inDegree is 0 then store it in queue for further calculations
        Queue<Integer> q = new LinkedList<>();
        for(int i=0; i<v; i++){
            if(inDegree[i]==0){
                q.add(i);
            }
        }
        //until the queue gets emptied, remove the element from the queue, add it in answer
        //decrement the inDegree of its connections, since we removed the elements,
        // if any of the connections' inDegree gets 0 then add that connection in the queue as well and repeat the process
        while(!q.isEmpty()){
            int current = q.remove();
            ans[index] = current;
            index++;
            for(int i=0; i<adj.get(current).size(); i++){
                int connection = adj.get(current).get(i);
                inDegree[connection] --;

                if(inDegree[connection]==0){
                    q.add(connection);
                }
            }
        }  return ans;
    }


    public static void main(String[] args) {
        
    }
}