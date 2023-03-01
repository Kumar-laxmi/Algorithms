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

// // ====================== Code with C ==========================

#include<stdio.h>
#include<limits.h>
 
int heap[1000000], heapSize;

void Init() {
    heapSize = 0;
    heap[0] = -INT_MAX;
}
 
void swap(int *a, int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

/*Insert an element into the heap */
void Insert(int element) {
    heapSize++;
    //Insert in the last place
    heap[heapSize] = element;
    //Adjust its position
    int now = heapSize;
    
    while (heap[now / 2] > element) {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = element;
}
 
int DeleteMin() {
    /* heap[1] is the minimum element. So we remove heap[1]. Size of the heap is decreased.
     Now heap[1] has to be filled. We put the last element in its place and see if it fits.
     If it does not fit, take minimum element among both its children and replaces parent with it.
     Again See if the last element fits in that place.*/
    int minElement, lastElement, child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    /* now refers to the index at which we are now */
    for (now = 1; now * 2 <= heapSize; now = child) {
        /* child is the index of the element which is minimum among both the children */
        /* Indexes of children are i*2 and i*2 + 1*/
        child = now * 2;
        /*child!=heapSize beacuse heap[heapSize+1] does not exist, which means it has only one
         child */
        if (child != heapSize && heap[child + 1] < heap[child]) {
            child++;
        }
        /* To check if the last element fits ot not it suffices to check if the last element
         is less than the minimum element among both the children*/
        if (lastElement > heap[child]) {
            heap[now] = heap[child];
        } else /* It fits there */
        {
            break;
        }
    }
    heap[now] = lastElement;
    return minElement;
}

//Function declaration for computing minimum no of moves
int minmoves(int fsize, int file[]);
 
int main() {
    int size,i,j;
    //Taking the no of files as input
    printf("Enter the no. of files : ");
    scanf("%d",&size);
    int file[size];
    
    //Taking the Size of files as input
    printf("Enter the sizes of files : ");
    for(i=0;i<size;i++){
        scanf("%d",&file[i]);
    }
    
    //To sort all files in ascending order
    for(i=0;i<size;i++){
        int temp=i;
        for(j=i+1;j<size;j++){
            if(file[temp]>file[j]){
                temp=j;
            }
        }
        swap(&file[temp],&file[i]);
    }
    
    //Printing the minimum no of moves
    printf("Minimum No of moves = %d",minmoves(size,file));
    return 0;
}

int minmoves(int fsize, int file[])
{
	
	int i,count;
	
	Init();
	
	//Inserting all file sizes to min heap
    for(i=0;i<fsize;i++){
        Insert(file[i]);
    }
    
    count=0;
    
    //Running loop until one entry remains
    while (heapSize > 1) {
    	//get first smallest element
        int first_smallest = DeleteMin();
        
        //get second smallest element
        int second_smallest =DeleteMin();
        
        //add the two smallest file sizes
        int temp = first_smallest + second_smallest;
        
        //count storing total computation cost
        count+=temp;
        
        //push temp to min heap
        Insert(temp);
    }
    //returning the total computation cost
    return count;
}
