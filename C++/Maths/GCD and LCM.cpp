/* 
•GCD
Greatest common divisor (GCD) of two or more numbers is greatest common factor number that divides them.

 •Example
Greatest common divisor of 5 and 10 is 5, because both the numbers are divisible by 5.
5/5 = 1
10/5 = 2

•Method to Find GCD
In order to find gcd of numbers, all factors of the numbers is needed to be determined and find the largest common factor. 
Example, 2, 4 and 8 are three numbers. Then the factors of 2, 4 and 8 are:
2 → 1,2
4 → 1,2,4
8 → 1,2,4,8
Thus, it can be concluded that 2 is the highest common factor among all three numbers. Hence, GCD of 2,4 and 8 is 2

•LCM
LCM (Least Common Multiple) of two numbers is the smallest number which can be divided by both numbers.

• Example
Least Common Multiple of 2 and 5 is 10. As, 10 is divisible by both 2 and 5. Such, that 2 and 5 are known as the divisors of 10.

• Method to Find LCM :- Using Prime Factors
Example, 12 and 16 are two numbers. Writing factors of both the numbers individually.
• STEP-1
12 = 2 x 2 x 3
16 = 2 x 2 x 2 x 2
• STEP-2
Prime factors of both number is :-
12 x 16 = 2 x 2 x 3 x 2 x 2 x 2 x 2
• STEP-3
Pair all common prime factors and that gives LCM.
Thus, there are one 3 and four 2’s.
LCM (12, 16) = 2 x 2 x 2 x 2 x 3 = 48

• Relation Between LCM and GCD
If a and b are given numbers.Then:
a x b = LCM(a, b) * GCD (a, b)
LCM(a, b) = (a x b) / GCD(a, b)
```
 
•Sample Input
a=4 , b=8

•Sample Output
GCD = 4
LCM = 8

•Time Complexity
O(log(min(a,b)) , where a and b are the numbers whose GCD and LCM are determined.
*/  

 #include<bits/stdc++.h>
//#include <boost/math/common_factor.hpp>
using namespace std;
// RECURSION 
int gcd(int a ,int b)
{
    /* base condition*/ 
    if(b==0) return a;
    return gcd (b,a%b );
}
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}
int main(){
    int a;
    int b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    cout<<lcm(a,b)<<endl;
/* EXPLAIN->*/
/* gcd(12,18) and gcd(18,12) means same .
 /* cout<<gcd(1,0)<<endl;
    cout<<gcd(2,8)<<endl;
    cout<<gcd(12,120)<<endl;
    cout<<gcd(11,110)<<endl;*/
// GCD INBUILT FUNCTION-
cout << __gcd(a,b) << endl;  /* ----> T.c -> O(logn)*/
//cout << boost::math::lcm (a,b) << endl;  /* ----> INBUILT */
/* For 3 no. --> gcd(gcd(a,b) , c)*/
/* MINIMUM FRACTION application of gcd*/
    return 0;
}
