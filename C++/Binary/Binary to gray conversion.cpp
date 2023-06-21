
/*
Author: Abdul Kadir
Github username: AK3847
Topic: Binary to gray conversion and vice-versa:

--------------LOGIC----------------
1.Binary to Gray:
--> Here the most significant bit of the gray code is same as the given binary code
    so we don't need to make any changes
--> Further traversing the binary from 1st index(i.e 2nd position) we take the xor of current
    index character  of binary code with the previous index character of binary code 
    and add it to our converted gray code

2. Gray to Binary:
--> Here the most significant bit of the Binary code is same as the given Gray code, so we direclty copy it.
--> Further traversing the Gray code we check if the current character of Gray code is '0', if it is '0'
    we copy the value of previous index of converted Binary code,else we copy the flipped value of current Gray character
    to our binary code.

*/

//-----------------CODE------------------
#include<bits/stdc++.h>
using namespace std;

//Function to convert given binary string to gray code stored in a 2d matrice
void binarytogray(string bin)
{
    // Initializing a 2d matrice with one column for given binary code and 
    // another column for converted gray code
    char matrice[bin.size()][2]; 
    
    //Assigning the initial values
    matrice[0][0]=(bin[0]); 
    matrice[0][1]=(bin[0]); //MSB of Gray code is same as that of given Binary code

    for(int i=1;i<bin.size();i++)
    {
        //taking the XOR of current index character of binary code with the previous index character of binary code
        char xr=(bin[i]==bin[i-1])?'0':'1'; 
        matrice[i][1]=xr;

        matrice[i][0]=bin[i];
    }

    //Printing the answer:
    cout<<"Binary  "<<"Gray"<<"\n";
    for(int i=0;i<bin.size();i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<matrice[i][j]<<"         ";
        }
        cout<<"\n";
    }
}

//Function to convert the given gray code string into binary and store it in a 2d Matrice
void graytobinary(string gray)
{
    // Initializing a 2d matrice with one column for given gray code and 
    // another column for converted binary code
    char matrice[gray.size()][2];

    //Assigning the initial values
    matrice[0][0]=(gray[0]);
    matrice[0][1]=(gray[0]); //MSB of binary code is same as that of given Gray code
    for(int i=1;i<gray.size();i++)
    {
        matrice[i][0]=gray[i];
        // if the current character is '0' 
        // we copy the previous character of the binary code
        if(gray[i]=='0') 
            matrice[i][1]=(matrice[i-1][1]);
        // else we copy the flipped value of the previous binary code character
        // i.e if its '0' we take '1' and vice-versa
        else
            matrice[i][1]=(matrice[i-1][1]=='0')?('1'):('0');
    }

    //Printing the answer:
    cout<<"Gray   "<<"Binary"<<"\n";
    for(int i=0;i<gray.size();i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<(char)matrice[i][j]<<"         ";
        }
        cout<<"\n"; 
    }
}
int main()
{
    string bin="11001"; //Given Binary code string 
    string gray="10101";//Given Gray code string
    cout<<"Binary to Gray Conversion:\n";
    binarytogray(bin); //calling the user-defined function to convert given Binarycode into Graycode and display it
    cout<<"\n";
    cout<<"Gray to Binary conversion:\n";
    graytobinary(gray); //calling the user-defined function to convert given Graycode into BinaryCode and display it
   return 0;
}