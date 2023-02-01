#include<bits/stdc++.h>
using namespace std;

void displayRelation(vector<vector<int>> &relation,int n) {
    // Displaying relation
    int first=1;
    cout<<"{";
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (relation[i][j] == 1) {
                if (!first) cout<<",";
                cout<<"("<<i<<","<<j<<")";
                first = 0;
            }
        }
    }
    cout<<"}"<<endl;
}

void reflexiveClosure(vector<vector<int>> relation,int n) {
    for (int i=0;i<n;i++) {
        //  Setting all (i,i) pairs to 1
        relation[i][i] = 1;
    }
    cout<<"Reflexive closure: ";
    displayRelation(relation,n);
}

void symmetricClosure(vector<vector<int>> relation,int n) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            // Setting (j,i) pair to 1 for every (i,j) pair
            if (relation[i][j] == 1 && relation[j][i] == 0)
                relation[j][i] = 1;
        }
    }

    cout<<"Symmetric closure: ";
    displayRelation(relation,n);
}

void transitiveClosure(vector<vector<int>> relation,int n) {
    // Using warshall algorithm
    for (int k=0;k<n;k++) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                // if transitive edge through k then add it to relation
                if (relation[i][k] == 1 && relation[k][j] == 1) 
                    relation[i][j] = 1;
            }
        }
    }

    cout<<"Transitive closure: ";
    displayRelation(relation,n);
}

void takeInput(vector<vector<int>> &relation,int n) {
    char ch='y';
    while (ch == 'y' || ch == 'Y') {
        int x,y;
        cout<<"Enter pair (x,y): ";
        cin>>x>>y;
        if (x<0 || x>=n || y<0 || y>=n) cout<<"Invalid pair";
        else relation[x][y] = 1;
        cout<<"Do u want to continue(Y/y): ";
        cin>>ch;
    }
}

int main() {
    int n;
    cout<<"Enter no of elements in set on which relation is: ";
    cin>>n;
    cout<<"Elements are from 0 to "<<n-1<<endl;
    vector<vector<int>> relation(n,vector<int>(n,0));
    takeInput(relation, n);
    cout<<"Relation is ";
    displayRelation(relation,n);
    reflexiveClosure(relation,n);
    symmetricClosure(relation,n);
    transitiveClosure(relation,n);
    return 0;
}