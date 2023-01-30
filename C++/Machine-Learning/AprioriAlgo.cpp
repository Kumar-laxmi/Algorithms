#include <iostream>
#include <vector>
#include <map>
using namespace std;

int m, n, minSupport;
vector<string> items;
vector<vector<int>> transactionTable;
map<string, int> itemCount;

void enterData() {
    int ele;
    string item;
    vector<int> transactions;

    cout << "\nEnter Minimum Support: ";
    cin >> minSupport;
    cout << "\nEnter no. of items : ";
    cin >> m;
    cout << "\nEnter " << m << " items (space-separated) : ";
    for (int i = 0; i < n; i++) {
        cin >> item;
        items.push_back(item);
    }
    cout << "\nEnter no. of transactions : ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "\nEnter transations for each item in T" << i << " : ";
        for (int j = 0; j < items.size(); j++) {
            cin >> ele;
            transactions.push_back(ele);
        }
        transactionTable.push_back(transactions);
        transactions.clear();
    }
    cout << "\nTransaction Table :\n\t";
    for (string s : items) cout << s << "\t";
    for (int i = 0; i < n; i++) {
        cout << "\nT" << i + 1 << "\t";
        for (int j = 0; j < transactionTable[i].size(); j++)
            cout << transactionTable[i][j] << "\t";
    }
}

void AprioriAlgo(int n, int minSup) {
    for(int i = 0; i < transactionTable.size(); i++) {
        for(int j = 0; j < n; j++) {
            if(transactionTable[j][i] == 1) itemCount[items[i]]++;
        }
    }

    for(auto i = itemCount.begin(); i != itemCount.end(); i++)
        if(i->second < minSup) itemCount.erase(i);

    cout << "\nResult after 1st filtering : ";
    
}

int main() {
    char ch = 'y';


    cout << "\t======= APRIORI ALGORITHM =====" << endl;

    while (ch == 'y') {
        enterData();
        AprioriAlgo(n, minSupport);
    }

    return 0;
}