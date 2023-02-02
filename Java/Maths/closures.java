import java.util.Scanner;
import java.util.Arrays;

// In this program, we are trying to find the closures of a relation(symmetric, reflexive and transitive closure).
// Closure of a relation is the smallest relation which contains original relation and follows the desired property.

// The relation is represented using a n x n matrix where n represents size of set on which relation is defined.
// For every pair (a,b) in relation, we set value at (a,b) indices to 1 in the matrix value else 0.
// For reflexive closure, we need to make sure that all (a,a) pairs are present
// So we set all values at (a,a) indices in matrix to 1.
// For symmetric closure, we need to make sure that for every (a,b) pair we have (b,a) pair.
// So we set all (b,a) indices to 1 where (a,b) indices is set to 1.
// For transitive closure, we use Warshall algorithm.
// Warshall algorithm first detects the transitive edges through first element then considering first 2 elements and so on upto the size of matrix.

public class closures {
    public static int[][] copy(int[][] src) {
        // Creating a copy of original relation so it does not modify original
        int[][] copy = new int[src.length][];
        for (int i = 0; i < src.length; i++) {
            copy[i] = src[i].clone();
        }
        return copy;
    }
    
    static void displayRelation(int[][] relation, int n) {
        // Displaying relation
        int first = 1;
        System.out.print("{");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (relation[i][j] == 1) {
                    if (first == 0) System.out.println(',');
                    System.out.print("(" + i + "," + j + ")");
                    first = 0;
                }
            }
        }
        System.out.println("}");
    }

    static void reflexiveClosure(int[][] relation, int n) {
        relation = copy(relation);
        for (int i = 0; i < n; i++) {
            //  Setting all (i,i) pairs to 1
            relation[i][i] = 1;
        }
        System.out.print("Reflexive closure: ");
        displayRelation(relation, n);
    }

    static void symmetricClosure(int[][] relation, int n) {
        relation = copy(relation);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (relation[i][j] == 1 && relation[j][i] == 0) {
                    // Setting (j,i) pair to 1 for every (i,j) pair
                    relation[j][i] = 1;
                }
            }
        }
        System.out.print("Symmetric closure: ");
        displayRelation(relation, n);
    }

    static void transitiveClosure(int[][] relation, int n) {
        // Using warshall algorithm
        relation = copy(relation);
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) { 
                    // if transitive edge through k then add it to relation
                    if (relation[i][k] == 1 && relation[k][j] == 1) 
                        relation[i][j] = 1;
                }
            }
        }
        System.out.print("Transitive closure: ");
        displayRelation(relation, n);
    }

    static void takeInput(int[][] relation, int n) {
        Scanner sc = new Scanner(System.in);
        char ch = 'y';
        while (ch == 'y' || ch == 'Y') {
            System.out.print("Enter pair (x,y): ");
            int x = sc.nextInt();
            int y = sc.nextInt();
            if (x < 0 || x >= n || y < 0 || y >= n) {
                System.out.println("Invalid pair");
            } else {
                relation[x][y] = 1;
            }
            System.out.print("Do u want to continue(Y/y): ");
            ch = sc.next().charAt(0);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no of elements in set on which relation is: ");
        int n = sc.nextInt();
        System.out.println("Elements are from 0 to " + (n - 1));
        int[][] relation = new int[n][n];
        takeInput(relation, n);
        System.out.println("Relation is ");
        displayRelation(relation, n);
        reflexiveClosure(relation, n);
        symmetricClosure(relation, n);
        transitiveClosure(relation, n);
        sc.close();
    }
}