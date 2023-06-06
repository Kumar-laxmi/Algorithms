#include<iostream>
using namespace std;
void floydWarshall(int **arr,int num)
{
    for(int k=0;k<num;k++)
    {
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
            {
                if(i==j)
                    arr[i][j]=0; //shortest distance to itself
                else
                    arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]); //calculating shortest distance to all other nodes
            }
        }
    }
    cout<<"\nAll pair shortest paths are"<<endl;
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            cout<<i<<"--->"<<j<<" "<<arr[i][j]<<endl; //printing the output
        }
        cout<<endl;
    }
}
int main()
{
    int num;
    cout<<"\nEnter the number of nodes"<<endl;
    cin>>num;     //input of number of nodes in the graph
    int *arr[num];
    for(int i=0;i<num;i++)
    {
        arr[i]=new int[num];
    }
    cout<<"\nPopulate adjacency matrix, For infinity use '-2.1'"<<endl;
    double temp;
    int infi=500;
    for(int i=0;i<num;i++)   //input of the adjacency matrix for the graph
    {
        for(int j=0;j<num;j++)  
        {
            cin>>temp;
            if(temp==-2.1)
            arr[i][j]=infi;
            else
            arr[i][j]=temp;
        }
    }
    floydWarshall(arr,num); 
    return 0;
}
