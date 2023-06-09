#include <bits/stdc++.h>
using namespace std;
int main(){
    /*  
          XOR TABLE
            X Y Z
            0 0 0
            0 1 1
            1 0 1
            1 1 0
    */
    int x = 0, y =0, count=0; // taking two values as test cases
    cout << "Enter value of X: ";
    cin >> x;
    cout << "Enter value of Y: ";
    cin >> y;
    int res = x ^ y ; // taking xor of the two values to get different bits

    // counting number of 1 present in the res 
    while(res>0){
        count += res & 1;
        res >>= 1;
    }
    cout << "The result is: " << count; // printing the value of bits
    return 0;
}