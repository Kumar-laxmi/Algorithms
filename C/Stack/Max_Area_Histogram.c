/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
//Problem Statement To determine the largest area in a given histogram.
// C++ program to find largest rectangle area in histogram using stack
#include <stdio.h>
void largestRectangleArea(int *,int );
int main() 
{
   int i, j;
   int inputValue;
   printf("Input the amount of values: \n");  
   scanf("%d", &inputValue);
   int hist[inputValue];
   printf("Input the values between 0 and 9 (separated by space): \n");
   for (i = 0; i < inputValue; ++i) 
   {
    scanf("%d", &hist[i]);  
   }
    largestRectangleArea(hist,inputValue);
    return 0;
}
void largestRectangleArea(int* heights, int heightsSize) 
{  
    int st[heightsSize+1], top=0;   //  stack for keeping track of bars position, top indicates the 
                                    //  index of current top element in the stack             
    int ts;                         //  To store top of stack
    int max_area = 0;               //  initial maximum area         
    int new_area;                   //  getting area with top bar
    int i = 0;    
	while (i < heightsSize)       //  working with all bars
    {        
        if ((top == 0) || heights[st[top-1]] <= heights[i])  //  if the current bar's height is bigger or equal than the top of stack
            { st[top]=i++; top++;} 
 
        else    //  if the current bar's height is less than the top of stack
        {
            ts = st[--top];                          
            if(top>0) new_area = heights[ts] * (i - st[top-1] - 1);   //  finding the new area
            else new_area = heights[ts] * i;                        
            
            if (max_area < new_area) max_area = new_area;  // update max area, if needed             
        }              
    }
    //  finding area for the rest of the bars still in stack    
    while (top>0)
    {
        ts = st[--top];        
        if(top>0) new_area = heights[ts] * (i - st[top-1] - 1);   //  finding the new area
            else new_area = heights[ts] * i;
 
        if (max_area < new_area) max_area = new_area;
    } 
    printf("%d",max_area);        
}