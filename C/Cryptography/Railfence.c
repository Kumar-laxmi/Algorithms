/*
# Railfence Cipher

Railfence cipher is a cryptographic technique which is a form of transposition cipher.

Given a plain-text message and a numeric key, cipher/de-cipher the given text using Rail Fence algorithm. 

## Example:

Encryption
Input :  "hello world"
Key = 3
Output : horel ollwd
Decryption
Input : horel ollwd
Key = 3
Output : hello world

## Note:

Initially The entire matrix is filled with "*"

## Output in C :

![Screenshot (343)](https://user-images.githubusercontent.com/80022302/218140781-4e7259f8-6015-4fcb-84dc-51d998137622.png)

*/





#include<stdio.h>
#include<string.h>

int main(){

        char a[100];
        int key,len;
        //Enter the text u want to convert to railfence
        printf("Enter the input message \n");
        gets(a);
        
        len = strlen(a); //len is the length of input message
        //specify the number of rows/rails
        printf("Enter the number of rails \n");
        scanf("%d",&key);
        char matrix[30][30];

//code for obtaining railfence matrix       

        //length of input message is equal to the number of coloumns and number of rails equal to number of rows
        for(int i=0;i<key;i++){
                for(int j=0;j<len;j++){
                        matrix[i][j] = '*';
                }
        }
        int k=0,l=0,temp=0,flag=0;
        //here the input message should be stored in railfence format.
        for(int i=0;i<len;i++){
                flag=0;
                temp=0;
                //if k value is equal to 0 or key-1 then convert the k value to negative so that it backtraverses the rows in railfence fashion.
                if(k==0 || k == key-1){

                        k=k*(-1);
                }
               //since matrix index cannot be negative whenever k value is -ve convert to positive and after computation convert it back to original value
                if(k<0){
                        temp=k;
                        k = k * (-1);
                        flag=1;
                }
                
                matrix[k][i] = a[l];
                if(flag==1){
                 k=temp;

                }

                k++;
                l++;

        }
        printf("\n");
        //printing the railfence matrix obtained.Railfence matrix even stores white spaces if the input message is a sentence.
        printf("RailFence Matrix is : \n");
         for(int i=0;i<key;i++){
                for(int j=0;j<len;j++){
                        char k = matrix[i][j];
                        printf("%c \t",k);
                }
                printf("\n");
        }

//code for encryption

       char str[100];
       int p=0;
       //string the encrypted message from railfence matrix if the entry of the matrix is not '*'
       for(int i=0;i<key;i++)
       {
               for(int j=0;j<len;j++){
                       if(matrix[i][j] != '*'){
                         
                              str[p++]=matrix[i][j];
                              
                       }
               }
       }
       //printing original message
       printf("Original message is: \n");
        puts(a);
        //printing encrypted message
       printf("Encrypted text is : \n");
       for(int i=0;i<p ; i++){
               printf("%c",str[i]);
       }
       printf("\n");

//code for decryption

       char dstr[100];
    int pp=0;
      printf("Decrypted text is : \n");

      int kk=0,temp1=0;
      for(int i=0;i<len;i++){
                      temp1=0;
                      flag=0;
                      //if k value is equal to 0 or key-1 then convert the k value to negative so that it backtraverses the rows in railfence fashion.
                      if(kk==0 || kk==key-1){
                              kk = kk* (-1);
                      }
                      //since matrix index cannot be negative whenever k value is -ve convert to positive and after computation convert it back to original value
                       if(kk<0){
                        temp1=kk;
                        kk = kk * (-1);
                        flag=1;
                }
                    char ct = matrix[kk][i];
                     
                     //obtaining decrypted message from railfence matrix
                   
                    dstr[pp++]=matrix[kk][i];

                    if(flag==1){
                            kk=temp1;
                    }
                    kk++;

      }
       //printing decrypted message
       for(int i=0;i<pp ; i++){
               printf("%c",dstr[i]);
       }
       printf("\n");

 }

