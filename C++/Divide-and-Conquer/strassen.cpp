#include <iostream>

using namespace std;
#include <iostream>

using namespace std;

void strassen_multiply(int A[][100], int B[][100], int C[][100], int n) {
    if (n == 1) {  // base case
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int m = n / 2;  // divide matrices into submatrices

    int A11[100][100], A12[100][100], A21[100][100], A22[100][100];
    int B11[100][100], B12[100][100], B21[100][100], B22[100][100];
    int C11[100][100], C12[100][100], C21[100][100], C22[100][100];
    int M1[100][100], M2[100][100], M3[100][100], M4[100][100], M5[100][100], M6[100][100], M7[100][100];

    // divide matrices into submatrices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+m];
            A21[i][j] = A[i+m][j];
            A22[i][j] = A[i+m][j+m];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+m];
            B21[i][j] = B[i+m][j];
            B22[i][j] = B[i+m][j+m];
        }
    }

    // recursive calls
    strassen_multiply(A11, B11, M1, m);
    strassen_multiply(A12, B21, M2, m);
    strassen_multiply(A11, B12, M3, m);
    strassen_multiply(A12, B22, M4, m);
    strassen_multiply(A21, B11, M5, m);
    strassen_multiply(A22, B21, M6, m);
    strassen_multiply(A21, B12, M7, m);

    // calculate C submatrices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C11[i][j] = M1[i][j] + M2[i][j];
            C12[i][j] = M3[i][j] + M4[i][j];
            C21[i][j] = M5[i][j] + M6[i][j];
            C22[i][j] = M7[i][j] - M2[i][j] + M4[i][j] + M5[i][j];
        }
    }

    // combine C submatrices into final matrix C
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = C11[i][j];
            C[i][j+m] = C12[i][j];
            C[i+m][j] = C21[i][j];
            C[i+m][j+m] = C22[i][j];}}

            for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<C[i][j]<<" ";
    } cout<<endl;

}}

int main(){

int A[100][100],B[100][100],C[100][100],n;
cin>>n;
cout<<"For a";
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>A[i][j];
    }
}cout<<"for B";
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>B[i][j];
    }


}
 strassen_multiply(A,B,C,n);}

