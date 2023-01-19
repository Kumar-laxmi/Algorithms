// ====================== Problem Statement ==========================
/*
Given the dimension of a sequence of matrices in an array M[], where the dimension of the ith matrix is (M[i-1] * M[i]), the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum.
That is if we have 3 matrices A,B and C then keeping the order same we have two sequences possible (A*B)*C or A*(B*C). Among these 2 sequences we have to find the most efficent sequence.

For example - M[] = {1, 2, 3, 4, 3}
Since there are 5 elements of array so we have total of 4 matrices of dimensions 1×2, 2×3, 3×4, 4×3.
Let those 4 input matrices be A, B, C and D.  
The minimum number of multiplications are obtained by putting parenthesis in following way ((AB)C)D.
The minimum number is multiplying cost of AB + multiplying Cost of (AB)C + multiplying cost of ((AB)C)D = 1*2*3 + 1*3*4 + 1*4*3 = 30
So to find this minimum cost the solution is given below -

Solution-
 We can solve this using Dynammic Programming approach.
 M i..j=Mi.. k * Mk+1..j ,i<=k<=j-1
 Find min[i,j] = min[i,k] + min[k+1,j] + Multiplication cost of Mi...k and Mk+1...j
 Mi =Di-1 Di
 Mk = D k-1 Dk
 Mj= Dj-1 Dj
 min[i,j] =min[i,k]+min[k+1,j]+Di-1DkDj where i<j
 min[i,j]=0 when i=j
*/

// // ====================== Code with C++ ==========================
#include <iostream>
#include<cmath>
using namespace std;

//function to compute the min matrix multiplication cost and print the matrix created 
int Matrix(int p[], int n)
{
        //matrix created for further calculation
	int m[n][n];

	int i, j, k, L, q;
	
	//intialize all matrix elements with 0
	for (i = 1; i < n; i++){
                m[i][i] = 0;
        }

        //finding minimum cost by dyanmic approach
	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1; 
			m[i][j] = INT32_MAX;
			for (k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}  
	
	//printing the matrix
        for(i=1;i<n;i++){
            for(j=1;j<n;j++){
                if(i<=j)
                cout<<m[i][j]<<" ";
                else
                cout<<"   ";
            }
            cout<<endl;
        }
        cout << "Minimum number of multiplications is "<<m[1][n-1]<<endl;
}

int main()
{
        int size;
        cout<<"Enter the size of array : ";
        cin>>size;
        int arr[size];
	//taking dimension of array as input
	
        cout<<"Enter the dimensions of sequence of matrices : ";
        for(int i=0;i<size;i++)
        cin>>arr[i];

        //calling function for finding minimum cost
	Matrix(arr, size);

	return 0;
}
