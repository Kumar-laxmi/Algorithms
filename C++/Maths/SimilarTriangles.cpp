// // Similar Triangles Program
// It can be used to check whether the two traingles are similar or not.
// Author: @swastik-akhil

#include <iostream>

using namespace std;

int main() {
    // SSS property
    int a1 = 3, b1 = 4, c1 = 5;
    int a2 = 6, b2 = 8, c2 = 10;
    if (a1 * b2 == a2 * b1 && b1 * c2 == b2 * c1 && a1 * c2 == a2 * c1) {
        cout << "The triangles are similar" << endl;
    } else {
        cout << "The triangles are not similar" << endl;
    }

    // AA property
    int x1 = 40, x2 = 70;
    int y1 = 40, y2 = 70;
    if (x1 == y1 && x2 == y2) {
        cout << "The triangles are similar" << endl;
    } else {
        cout << "The triangles are not similar" << endl;
    }

    // SAS property
    int a3 = 3, m = 50, b3 = 4;
    int a4 = 6, n = 50, b4 = 8;
    if (a3 * b4 == a4 * b3 && m == n) {
        cout << "The triangles are similar" << endl;
    } else {
        cout << "The triangles are not similar" << endl;
    }

    return 0;
}
