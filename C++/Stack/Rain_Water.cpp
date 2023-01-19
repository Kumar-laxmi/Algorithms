// program to solve rain water problem using stack
#include <bits/stdc++.h>
using namespace std;
int TrapWater(int arr[], int n)            //Function that return maximum water that is stored
{
    int s = n - 1;
    int previous = arr[0];               //start loop from index 1
    int prev_index = 0;                  // store previous wall's index
    int water = 0;
    int tempo = 0;                       // if no walls then delete temp value from water
    for (int i = 1; i <= s; i++)
    {  
        if (arr[i] >= previous)         // If the current wall is taller than the previous wall then make current wall as the previous wall
        {
            previous = arr[i];
            prev_index = i;
            tempo = 0;                  //  if same height wall found
        }
        else
        {
            water += previous - arr[i];  // subtract previous wall's height from the current wall height and add it to the water
            tempo += previous - arr[i];     // If we dont find any larger wall then we will subtract temp from water
        }
    }
        if (prev_index < s)         // If we didn't find a wall greater than or equal  to the previous wall from the left then prev_index must be less than the index of the last element
    {
        water -= tempo;                       // if no larger wall was found that it has excess water and remove that from water variable
        previous = arr[s];                         // We start from the end of the array
        for (int i = s; i >= prev_index; i--)       // Loop from index which would contain the largest wall from the left
        {
            if (arr[i] >= previous)                // Right end wall will smaller than the 'previous index' wall
            {
                previous = arr[i];
            }
            else
            {
                water += previous - arr[i];
            }
        }
    }
    return water; // Return the maximum water
}
int main() // Main function
{
     int input[] = {1, 1, 5, 2, 1, 8 , 1, 0, 2, 1, 2, 6};
    int N = sizeof(input) / sizeof(input[0]);
    cout << TrapWater(input, N);
    return 0;
}