//C++ program to check if given number is Kaprekar Number or not

#include<iostream>
#include<math.h>
using namespace std;

bool kaprekar_num(int num)
{
    if(num==1)
    {
        return true;
    }

    int squre=num*num;   //Here we calculate squre of the given number
    
    int number=squre;
    
    int digits=0;  //Initialy we assign 0 to this variable as we calculate digits we just increment it by one

    while(squre)  //In this while loop we just calculate digits 
    {
        digits++;

        squre=squre/10;
    }

    for(int i=1;i<digits;i++)
    {
        int power_of_10=pow(10,i);

        if(power_of_10==num)  //This means the power of nuber is like 10 ,100 and so on 
             continue;        //this are not kaprekar numbers
        

        //Now actual part begins

        //int num1 = number/power_of_10 ;
        //int num2 = number%power_of_10;

        int summation= number/power_of_10 + number%power_of_10;

        if(summation==num)
        {
            return true;
        }
    }

    return false;
    
}

int main()
{   
   int n;
   cout<<"ENTER NUMBER"<<endl;
   cin>>n;
   
   int ans;

  // ans=kaprekar_num(n);

   if(kaprekar_num(n))    //IF this condition get true then output wil be simply "Given number is kaprekar number"
   {
    cout<<n<<" "<<"Given number is kaprekar number"<<endl;
   }
   else
   {
    cout<<n<<" "<<"Given number is not Kaprekar number"<<endl;    //Else this line will be printed
   }
}

//*******************************
// Case 1 : Enter Number 45 

// output : This is kaprekar number

// Case 2 : Enter Number 128

// output : This is Not Kaprekar Number

//*********************************