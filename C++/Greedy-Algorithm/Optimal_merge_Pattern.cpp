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

// // ====================== Code with C++ ==========================

#include<iostream>
#include<cmath>
#include <bits/stdc++.h>
using namespace std;

//Function declaration for computing minimum no of moves
int minmoves(int fsize, int file[]);

int main(){
    int size,i,j;
    //Taking the no of files as input
    cout<<"Enter the no. of files : ";
    cin>>size;
    int file[size];
    
    //Taking the Size of files as input
    cout<<"Enter the sizes of files : ";
    for(i=0;i<size;i++){
        cin>>file[i];
    }
    
    //To sort all files in ascending order
    for(i=0;i<size;i++){
        int temp=i;
        for(j=i+1;j<size;j++){
            if(file[temp]>file[j]){
                temp=j;
            }
        }
        swap(file[temp],file[i]);
    }
    
    //Printing the minimum no of moves
    cout << "Minimum No of moves = "<< minmoves(size,file);
    return 0;
}

//Function definition for computing minimum no of moves
int minmoves(int fsize, int file[])
{
	//creating a min heap 
    priority_queue<int, vector<int>, greater<int> > p;
	
	int i,count;
	
	//Inserting all file sizes to min heap
    for(i=0;i<fsize;i++){
        p.push(file[i]);
    }
    
    count=0;
    
    //Running loop until one entry remains
    while (p.size() > 1) {
    	//get first smallest element
        int first_smallest = p.top();
        p.pop();
        
        //get second smallest element
        int second_smallest = p.top();
        p.pop();
        
        //add the two smallest file sizes
        int temp = first_smallest + second_smallest;
        
        //count storing total computation cost
        count+=temp;
        
        //push temp to min heap
        p.push(temp);
    }
    //returning the total computation cost
    return count;
}
