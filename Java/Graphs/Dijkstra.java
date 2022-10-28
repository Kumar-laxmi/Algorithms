package Java.Graphs;

import java.util.Scanner;

public class Dijkstra{

    private static void dijkstra(int[][] adjacencyMatrix){
        int v = adjacencyMatrix.length;
        boolean visited[] = new boolean[v];
        int distance[] = new int[v];
        distance[0] = 0;

        //Initial value of all vertex is set to infinity except first vertex
        for(int i = 1; i < v; i++){
            distance[i] = Integer.MAX_VALUE;
        }

        //Traversing through all vertex 
        for(int i = 0; i < v-1; i++){
            int minVertex = findMinVertex(distance, visited);
            visited[minVertex] = true;

            //Exploring neighbors 
            for(int j = 0; j < v; j++){
                if(adjacencyMatrix[minVertex][j] != 0 && !visited[j] && distance[minVertex] != Integer.MAX_VALUE){
                    int newDist = distance[minVertex] + adjacencyMatrix[minVertex][j];
                    if(newDist < distance[j]){
                        distance[j] = newDist;
                    }
                }
            }
        }

        //Printing
        for(int i = 0; i < v; i++){
            System.out.println(i + " "+ distance[i]);
        }
    }

    //Finding minimum distance 
    private static int findMinVertex(int[] distance, boolean visited[]){
        int minVertex = -1;
        for(int i = 0; i < distance.length; i++){
            if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
                minVertex = i;
            }
        }
        return minVertex;
    }

    //Driver code
    public static void main(String[] args){
        try (Scanner s = new Scanner(System.in)) {
            int v = s.nextInt();
            int e = s.nextInt();
            int adjacencyMatrix[][] = new int[v][v];
            for(int i = 0; i< e; i++){
                int v1 = s.nextInt();
                int v2 = s.nextInt();
                int weight = s.nextInt();
                adjacencyMatrix[v1][v2] = weight;
                adjacencyMatrix[v2][v1] = weight;
            }
            dijkstra(adjacencyMatrix);
        }
    }
}
