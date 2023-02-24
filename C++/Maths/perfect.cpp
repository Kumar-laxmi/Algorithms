// C++ program to check if the number is a Perfect number or not

#include<iostream>
using namespace std;

int main ()
{  
    // initialize variable for loop, input number and to store sum 
    int i, num, sum=0;
    
    // take user input 
    cout << "Enter the number: ";
    cin >> num;
    
    // iterate from 1 to N and if the number is a factor of N then add it to sum
    for (i=1; i < num; i++)
    {
        int div = num % i;
        if (div == 0)
            sum = sum + i;
    }
    
    // if sum of factors of N is equal to N then it is a perfect number
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
