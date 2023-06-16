#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> s;
    queue<int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
    }

    return page_faults;
}

int main()
{
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    int pages[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    int capacity;
    cout << "Enter the capacity: ";
    cin >> capacity;

    cout << "Answer: " << pageFaults(pages, n, capacity) << endl;

    return 0;
}
