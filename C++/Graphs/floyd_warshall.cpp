#include <iostream>
#include <conio.h>
using namespace std;
void floyd_warshall(int a[][7])
{
    int i, j, k;
    for (k = 0; k < 7; k++)
    {
        for (i = 0; i < 7; i++)
        {
            for (j = 0; j < 7; j++)
            {
                if ((a[i][k] * a[k][j] != 0) && (i != j))
                {
                    if ((a[i][k] + a[k][j] < a[i][j]) || (a[i][j] == 0))
                    {
                        a[i][j] = a[i][k] + a[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < 7; i++)
    {
        cout << "\nMINIMUM COST WITH RESPECT TO NODE:" << i << endl;
        for (j = 0; j < 7; j++)
        {
            cout << a[i][j] << "\t";
        }
    }
}
int main()
{
    int a[7][7];
    cout << "ENTER VALUES OF ADJACENCY MATRIX\n\n";
    for (int i = 0; i < 7; i++)
    {
        cout << "ENTER THE VALUES FOR " << (i + 1) << " ROW" << endl;
        for (int j = 0; j < 7; j++)
        {
            cin >> a[i][j];
        }
    }
    floyd_warshall(a);
    getch();
}