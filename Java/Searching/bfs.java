// Java program to print BFS traversal of a graph with the help of adjancecy list

import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

class bfs {
    static int V;  // Number of vertices 
    static int E;  // Number of edges 
    static boolean[] visited;
    static LinkedList<Integer>[] adj;   // Intialization of Linked List

    // Function used by BFS
    static void BFS_iterative(int v) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(v);    // Add all the given vertices into the queue
        visited[v] = true;  // Set boolean value of the visited vertex as true
        while (!queue.isEmpty()) {  // If queue is not empty
            v = queue.poll();       // Remove the vertex from the front end of the queue and print it
            System.out.print(v + " ");  
            for (Integer i : adj[v]) {   
                if (!visited[i]) {
                    visited[i] = true;
                    queue.add(i);  // add the vertex to the top of the queue if the vertex is not visited 
                }
            }
        }
    }

    public static void main(String[] args) {
        int count = 1, to = 0, from = 0;
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        V = sc.nextInt();       // Take input of number of vertices from the user 
        
        visited = new boolean[V];
        adj = new LinkedList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new LinkedList<>();    // add vertices into the linked list
        }

        
        System.out.print("Enter the number of edges: ");
        E = sc.nextInt();
        System.out.println("Enter the edges in the format <to> <from> : ");
         while (count <= E)            // Loop to take input of edges of the graph in the form of adjancecy list
            {
                to = sc.nextInt();
                from = sc.nextInt();
 
                adj[to].add(from);     // adding to to from list
                count++;
            }

        System.out.print("Enter the starting vertex: ");  // Determines the source vertex for BFS traversal
        int start = sc.nextInt();

        BFS_iterative(start);
    }
}