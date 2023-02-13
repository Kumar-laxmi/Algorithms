// C++ program to check if the number is a Perfect number or not

#include<iostream>
using namespace std;

int main ()
{  
    int i, num, div, sum=0;
    cout << "Enter the number: ";
    cin >> num;
    for (i=1; i < num; i++)
    {
        div = num % i;
        if (div == 0)
            sum = sum + i;
    }
    if (sum == num)
        cout << "\n" << num <<" is a perfect number";
    else
        cout << "\n" << num <<" is not a perfect number";
    return 0;
}

/*******************************************************
Case 1:
Enter the number: 153
153 is not a perfect number

Case 2:
Enter the number: 496
496 is a perfect number
*******************************************************/
