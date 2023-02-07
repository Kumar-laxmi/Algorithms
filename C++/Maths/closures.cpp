#include<bits/stdc++.h>
using namespace std;

// In this program, we are trying to find the closures of a relation(symmetric, reflexive and transitive closure).
// Closure of a relation is the smallest relation which contains original relation and follows the desired property.

// The relation is represented using a n x n matrix where n represents size of set on which relation is defined.
// For every pair (a,b) in relation, we set value at (a,b) indices to 1 in the matrix value else 0.
// For reflexive closure, we need to make sure that all (a,a) pairs are present
// So we set all values at (a,a) indices in matrix to 1.
// For symmetric closure, we need to make sure that for every (a,b) pair we have (b,a) pair.
// So we set all (b,a) indices to 1 where (a,b) indices is set to 1.
// For transitive closure, we use Warshall algorithm.
// Warshall algorithm first detects the transitive edges through first element then considering first 2 elements and so on upto the size of matrix.

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