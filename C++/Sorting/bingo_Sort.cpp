#include <iostream>
#include <vector>
using namespace std;
void bingoSort(vector<int> &arr)
{
    int min = arr[0], max = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }

    vector<int> flags(max - min + 1, 0);

    for (int i = 0; i < arr.size(); i++)
        flags[arr[i] - min] = 1;

    int index = 0;
    for (int i = 0; i < max - min + 1; i++)
    {
        if (flags[i])
        {
            arr[index] = i + min;
            index++;
        }
    }
}

int main()
{
    cout << "Enter the length of the array: ";
    int n;
    cin >> n;

    vector<int> a(n);

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Original array:" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    bingoSort(a);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
