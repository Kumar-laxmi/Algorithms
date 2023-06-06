#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "ENTER THE SIZE OF ARRAY: : ";
    cin >> n;

    int array[n];
    cout << "ENTER THE ELEMENTS: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "UNSORTED ARRAY: " << endl;
    for (int j = 0; j < n; j++)
    {
        cout << array[j] << " ";
    }
    cout << endl;

    int temp;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    cout << "SORTED ARRAY: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
