#include<bits/stdc++.h>
using namespace std;

//x^{2}+x-1
float f(float x)//function
{
    return x*x*x - 4*x - 9; 
}
int main()
{
    float L = 2;
    float R = 3;//range
    float M = (L+R)/2;
    int iterations = 20;
    float threshold = .00001;
    
    while(iterations--)
    {
        M = (L+R)/2;
        if(f(L) * f(M)  < 0)//root is b/w (L,M)
        {
            R = M;
        }
        else//root is b/w (M,R) 
        {
            L = M;
        }
        if(fabs(R-L) < threshold)
        {
            break;
        }
    }
    cout<<M;
}