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
//-----------------------------CODE----------------------
import java.io.IOException;
import java.util.*;
class BinarytoGray{
    //Function to convert given binary code to gray code and display it
    void binarytogray(String bin)
    {
        // Initializing a 2d matrice with one column for given binary code and 
        // another column for converted gray code
        char[][] matrice=new char[bin.length()][2];

        int i;
        //Assigning the Initial Values
        matrice[0][0]=(bin.charAt(0));
        matrice[0][1]=(bin.charAt(0));//MSB of Gray code is same as that of given Binary code
        for(i=1;i<bin.length();i++)
        {
            //taking the XOR of current index character of binary code with 
            // the previous index character of binary code
            char x=(bin.charAt(i)==bin.charAt(i-1))?'0':'1';
            matrice[i][1]=x;
            matrice[i][0]=bin.charAt(i);
        }
        //Printing the answer:
        System.out.println("Binary      Gray");
        for(i=0;i<bin.length();i++)
        {
            for(int j=0;j<2;j++)
            {
                System.out.print(matrice[i][j]+"            ");
            }
            System.out.println();
        }
    }

    //Function to convert given gray code to binary code and display it
    void graytobinary(String gray)
    {
        // Initializing a 2d matrice with one column for given gray code and 
        // another column for converted binary code
        char[][] matrice=new char[gray.length()][2];

        int i;
        //Assigning the Initial Values
        matrice[0][0]=(gray.charAt(0));
        matrice[0][1]=(gray.charAt(0));//MSB of binary code is same as that of given Gray code

        for(i=1;i<gray.length();i++)
        {
            matrice[i][0]=gray.charAt(i);
            // if the current character is '0' 
            // we copy the previous character of the binary code
            if(gray.charAt(i)=='0')
                matrice[i][1]=(matrice[i-1][1]);
            // else we copy the flipped value of the previous gray code character
            // i.e if its '0' we take '1' and vice-versa
            else
                matrice[i][1]=(matrice[i-1][1]=='0')?'1':'0';
        }
        //Printing the answer:
        System.out.println("Gray      Binary");
        for(i=0;i<gray.length();i++)
        {
            for(int j=0;j<2;j++)
            {
                System.out.print(matrice[i][j]+"            ");
            }
            System.out.println();
        }
    }
    public static void main(String as[]) throws IOException
    {
        BinarytoGray obj=new BinarytoGray();// Object of the Class to call the user-defined methods
        String bin="11001";//Given Binary Code
        String gray="10101";//Given Gray Code

        System.out.println("Binary to Gray Conversion:");
        obj.binarytogray(bin);//Calling the user-defined the method to convert given Binary code into Gray code

        System.out.println();

        System.out.println("Gray to Binary Conversion:");
        obj.graytobinary(gray);//Calling the user-defined the method to convert given Gray code into Binary code
    }   
}