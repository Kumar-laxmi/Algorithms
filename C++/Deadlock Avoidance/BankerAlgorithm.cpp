#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
int available[MAXN];
int allocation[MAXN][MAXN];
int need[MAXN][MAXN];
int request[MAXN];

bool check(int process) {
    for (int i = 0; i < m; i++) {
        if (need[process][i] < request[i]) {
            return false;
        }
    }
    return true;
}

void banker() {
    for (int i = 0; i < n; i++) {
        if (check(i)) {
            for (int j = 0; j < m; j++) {
                available[j] += allocation[i][j];
                allocation[i][j] = 0;
                need[i][j] = 0;
            }
        }
    }
}

int main() {
    // read input
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> available[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> allocation[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> need[i][j];
        }
    }

    // simulate resource requests
    while (cin >> request[0]) {
        for (int i = 1; i < m; i++) {
            cin >> request[i];
        }
        if (check(0)) {
            banker();
        } else {
            cout << "Request cannot be granted." << endl;
        }
    }

    return 0;
}
