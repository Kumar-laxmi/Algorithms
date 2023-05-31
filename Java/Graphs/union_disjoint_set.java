package Floyd_Warshall;

import java.util.Scanner;

public class union_disjoint_set {
    static int parent[];
    static void create(){
        int n = parent.length;
        for(int i=0;i<n;i++) parent[i] = i;
    }
    static int find_parent(int n){
        if(parent[n]!=n) return parent[n] = find_parent(parent[n]);
        return parent[n];
    }
    static void union(int a,int b){
        a = find_parent(a);
        b = find_parent(b);
        if(a!=b) parent[b] = a;
    }
    public static void main(String args[]){
        Scanner obj = new Scanner(System.in);
        int n = obj.nextInt(); // n>=1
        parent = new int[n+1];
        create();
        int w = obj.nextInt();
        for(int i=0;i<w;i++){
            int a = obj.nextInt(),b = obj.nextInt(); // 1<=a<=n && 1<=b<=n
            union(a,b);
        }
    }
}
