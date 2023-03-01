// ====================== Problem Statement ==========================
/*
Given n number of sorted files, the task is to find the minimum computations done to reach the Optimal Merge Pattern.
When two or more sorted files are to be merged altogether to form a single file, the minimum computations are done to reach this file are known as Optimal Merge Pattern

For example
Q If there are 5 files apply optimal merge pattern.(20,30,10,5,30).
Ans
Step 1: Sort files in ascending order of their sizes.
        x4 x3 x1 x2 x5
        5 10 20 30 50
Step 2: Pick the files of smaller size and merge them
        Merge x3 and x4 |z1|=5+10=15
        Merge z1 and x1|z2|=35
        Merge x2 and x5|z3|=60
        Merge z3 and z2=60+35=95
        Total no of moves= 205

205 is the minimum no of moves if we combine in different ways then moves will be greater than 205.

Approach

1)Sort files in ascending order of sizes.
2)Pick the files of smaller sizes and merge them.
*/

// // ====================== Code with Java ==========================

import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Arrays;
 
public class OMP{
    // Function to find minimum no of moves
    static int minmoves(int size, int file[])
    {
        // create a min heap
        PriorityQueue<Integer> p = new PriorityQueue<>();
        for (int i = 0; i < size; i++) {
            // add size of files to min heap
            p.add(file[i]);
        }
        int count = 0;
        //Running loop until one entry remains
        while (p.size() > 1) {
 
            // pop two smallest size element from the min heap
            int res = p.poll() + p.poll();
 
            // count storing total computation cost till now
            count += res;
 
            // push res to min heap
            p.add(res);
        }
        //returning the total computation cost
        return count;
    }
 
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in); 
        System.out.println("Enter the no of files : ");
        int size = sc.nextInt();
        int i;
        int file[] = new int[size];
        System.out.println("Enter the size of different files : ");
        for(i=0;i<size;i++){
            file[i]=sc.nextInt();
        }
        Arrays.sort(file);
        System.out.println("Minimum number of file moves = "+ minmoves(size, file));
    }
}
