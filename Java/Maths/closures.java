import java.util.Scanner;
import java.util.Arrays;

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