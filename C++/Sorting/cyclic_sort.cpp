#include <bits/stdc++.h>

using namespace std;

void cycleSort(vector<int> a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        int item = a[i];
        int pos = i;
        for (int j = i + 1; j < a.size(); j++)
            if (a[j] < item)
                pos++;

        swap(item, a[pos]);

        while (pos != i)
        {
            pos = i;
            for (int j = i + 1; j < a.size(); j++)
                if (a[j] < item)
                    pos++;

            swap(item, a[pos]);
        }
    }

    for (int e : a)
        cout << e << " ";
}

int main()
{
    vector<int> a = {20, 10, 50, 16, 30};
    cycleSort(a);

    return 0;
}
