// Cpp-program to implement famous Kruskal's Algorithm
// Kruskal's Algorithm is a greedy algorithm that is used to find the minimum spanning tree from a graph.

// The idea is to sort all edges of given graph in increasing order, and then keep on adding new edges and nodes in the spanning tree if the added edge does not form a cycle.


/* A minimum spanning tree is constructed from a weighted & undirected graph, so it has:
-> Connects all nodes / vertices
-> no cycles
-> smallest possible sum of edge weights.*/

import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main 
{
    static final int maximum = 100000;
    static int[] no = new int[maximum];
    static int nodes, edges;
    static List<Pair<Long, Pair<Integer, Integer>>> k = new ArrayList<>();

    static int base(int a) 
    {
        while (no[a] != a) 
        {
            no[a] = no[no[a]]; // Path compression optimization
            a = no[a];
        }
        return a;
    }

    static void temp(int a, int b)    //temporarily stores values
    {
        int k = base(a);
        int l = base(b);
        no[k] = no[l];
    }

    static long krus(List<Pair<Long, Pair<Integer, Integer>>> k) 
    {
        int a, b;
        long cost, minCost = 0;
        for (int i = 0; i < edges; ++i) 
        {
            a = k.get(i).second.first;
            b = k.get(i).second.second;
            cost = k.get(i).first;
            if (base(a) != base(b)) 
            {
                minCost += cost;
                temp(a, b);     // Merge sets
            }
        }
        return minCost; // returns cost
    }

    public static void main(String[] args) 
    {
        int a, b;
        long w, minCost;

        for (int i = 0; i < maximum; ++i) 
        {
            no[i] = i;      //Initialize each node as a different set
        }

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Nodes & edges: ");
        nodes = scanner.nextInt();
        edges = scanner.nextInt();

        for (int i = 0; i < edges; ++i) 
        {
            System.out.print("Enter the value of a, b, and edges: "); // takes input
            a = scanner.nextInt();
            b = scanner.nextInt();
            w = scanner.nextLong();
            k.add(new Pair<>(w, new Pair<>(a, b)));
        }
        scanner.close();

        k.sort(null); //sorting

        minCost = krus(k);
        System.out.println("Minimum cost is " + minCost);
    }

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) 
        {
            this.first = first;
            this.second = second;
        }
    }
}

// Time Complexity: O(E log N)
