#include <iostream>
#include<cmath>
using namespace std;
const int N=5;

int S(int s[][N],int i, int j){
    if(i==j){
        cout<<"M"<<i;
    }
    else{
        cout<<"(";
        S(s,i,s[i][j]);
        S(s,s[i][j]+1,j);
        cout<<")";
    }
}

int Matrix(int p[], int n)
{
	int m[n][n],s[N][N];

	int i, j, k, L, q;

	for (i = 1; i < n; i++){
        m[i][i] = 0;
        s[i][i] = 0;
    }

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
                    s[i][j] = k;
			}
		}
	}

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

    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            if(i<=j)
            cout<<s[i][j]<<" ";
            else
            cout<<"  ";
        }
        cout<<endl;
    }
    i=1;
    j=n-1;
    S(s,i,j);    

}

int main()
{
	int arr[] = {5,4,6,2,7};
	int size = sizeof(arr) / sizeof(arr[0]);

	Matrix(arr, size);

	return 0;
}