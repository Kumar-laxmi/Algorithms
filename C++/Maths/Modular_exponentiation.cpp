/* C++ Program for Modular Exponentiation */
#include <iostream>
using namespace std;

// Function to calculate (x^y)%p
int power(int x, int y, int p)
{
    // Initialize answer
    int ans = 1;

    // Check till the number becomes zero
    while (y > 0)
    {
        // If y is odd, multiply x with answer
        if (y % 2 == 1)
        {
            ans = ans * x;
        }

        // Change y to half
        y = y / 2;

        // Change x to x^2
        x = x * x;
    }
    return ans % p;
}

int main()
{
    int x, y, p;
    cin >> x >> y >> p; // Taking input of x, y and p

    // Function Call
    cout << "Power is " << power(x, y, p);
    return 0;
}

// Time Complexity:- O(log y)
// Space Complexity:- O(1)