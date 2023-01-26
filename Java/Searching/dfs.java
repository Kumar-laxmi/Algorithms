// Java program to print DFS traversal of a graph with the help of adjancecy list

import java.util.Scanner;
import java.util.Stack;
import java.util.LinkedList;

class dfs {
    static int V;     //Number of vertices 
    static boolean[] visited; 
    static LinkedList<Integer>[] adj; // Intialization of Linked List

    // Function used by DFS
    static void DFS_iterative(int v) {
        Stack<Integer> stack = new Stack<>(); 
        stack.push(v);       // Push vertices into the Stack
        while (!stack.isEmpty()) {    // If stack is not empty
            v = stack.pop();   // Pop elements from the stack untill the stack becomes empty
            if (!visited[v]) {
                System.out.print(v + " "); // Print the vertex if the vertex is visited (has been poped out of the stack)
                visited[v] = true;     // Make boolean value of the vertex as true
            }
            for (Integer i : adj[v]) 
            {
                if (!visited[i]) {
                    stack.push(i);    // push the vertex into the stack if the vertex has boolean value as false
                }
            }
        }
    }

    public static void main(String[] args) {
        int E,count = 1, to = 0, from = 0;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        V = sc.nextInt();    // Take input of number of vertices from the user 
        visited = new boolean[V];
        adj = new LinkedList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new LinkedList<>();   // add vertices into the linked list
        }

        System.out.print("Enter the number of edges: ");
        E = sc.nextInt();
        System.out.println("Enter the edges in the format <to> <from> : ");
         while (count <= E)         // Loop to take input of edges of the graph in the form of adjancecy list
            {
                to = sc.nextInt();
                from = sc.nextInt();
 
                adj[to].add(from);        // adding to to from list
                count++;
            }
        System.out.print("Enter the starting vertex: "); // Determines the source vertex for DFS traversal
        int start = sc.nextInt();

        DFS_iterative(start);
    }
}
