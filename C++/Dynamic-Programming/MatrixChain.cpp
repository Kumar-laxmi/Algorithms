#include<iostream>
using namespace std;
long matChainOrder(int *p,int n)
{
    int m[n][n];//Solution Matrix to store the multiplication
    int i,j,k,l,q;
    for(i=1;i<n;i++)
    m[i][i]=0;//Initializing the diagnol elements to 0

    for(l=2;l<n;l++)//l is the length of how many matrices to be multiplied
    {
        for(i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;

            for(k=i;k<=j-1;k++)//Finding the operations cost
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];//Number of operations
                if(q<m[i][j])
                m[i][j]=q;
            }
        }
    }
    //Finding the minimum cost of matrix change of length n
    return m[1][n-1];
}
int main()
{

    int n;// n is the number of matrixes
    cin>>n;

    int p[n+1];//An array to store the order of each matrix
    //number of rows: p[i-1]
    //number of columns: p[i]

    cout<<"Enter the order for each matrix"<<endl;//Number of rows and columns dynamically inserted by User
    for(int i=0;i<n;i++)
    {
        cin>>p[i]>>p[i+1];
    }

    cout<<matChainOrder(p,n+1);//A function for multiplication of matrices
    return 0;
}
