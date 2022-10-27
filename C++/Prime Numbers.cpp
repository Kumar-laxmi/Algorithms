// program for print all prime numders between a&b

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    for (int num = a; num <= b; num++)
    {
        int i;
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                break;
            }
        }
        if (i == num)
        {
            cout << num << endl;
        }
    }
}