/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
/*Problem Description
Program to convert  text sentence in CamelCase format .
Examples:
 1] INPUT: "this is camel case"
    OUTPUT "thisIsCamelCase"
 2] INPUT: "Hi Atul here"
   OUTPUT: "HiAtulHere"
Example Explanation */
#include <stdio.h>
#include <stdlib.h>
int main()                // Main function
{
    char str[100],cc[100];    //Function to remove spaces and convert into camel case
    int flag=0,i=0,j=0;
    printf("Enter a sentence\n");  //String
    gets(str);
    printf("Original String = %s\n",str);
    while(str[i]!='\0')
    {
        if(str[i]==' ')     //conversion into upper case
        {
           i++;
           flag=1;
           continue;
        }
        if(flag==1)  // new string will be reduced by the
       
        {
            cc[j]=str[i]-32;
            flag=0;
        }
        else        // size of spaces in the original string
        {
            cc[j]=str[i];
        }
        j++;
        i++;
    }
    printf("Camel Case = %s",cc);  //input text
    return 0;
}