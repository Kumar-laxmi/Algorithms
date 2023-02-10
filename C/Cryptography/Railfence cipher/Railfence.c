#include<stdio.h>
#include<string.h>

int main(){

        char a[100];
        int key,len;
        printf("Enter the input message \n");
        gets(a);
        
        len = strlen(a);
        printf("Enter the number of rails \n");
        scanf("%d",&key);
        char matrix[30][30];

        for(int i=0;i<key;i++){
                for(int j=0;j<len;j++){
                        matrix[i][j] = '*';
                }
        }
        int k=0,l=0,temp=0,flag=0;
        for(int i=0;i<len;i++){
                flag=0;
                temp=0;
                if(k==0 || k == key-1){

                        k=k*(-1);
                }
               
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
        printf("RailFence Matrix is : \n");
         for(int i=0;i<key;i++){
                for(int j=0;j<len;j++){
                        char k = matrix[i][j];
                        printf("%c \t",k);
                }
                printf("\n");
        }

       char str[100];
       int p=0;

       for(int i=0;i<key;i++)
       {
               for(int j=0;j<len;j++){
                       if(matrix[i][j] != '*'){
                         
                              str[p++]=matrix[i][j];
                              
                       }
               }
       }
       printf("Original message is: \n");
        puts(a);
       printf("Encrypted text is : \n");
       for(int i=0;i<p ; i++){
               printf("%c",str[i]);
       }
       printf("\n");

       char dstr[100];
    int pp=0;
      printf("Decrypted text is : \n");

      int kk=0,temp1=0;
      for(int i=0;i<len;i++){
                      temp1=0;
                      flag=0;
                      if(kk==0 || kk==key-1){
                              kk = kk* (-1);
                      }

                       if(kk<0){
                        temp1=kk;
                        kk = kk * (-1);
                        flag=1;
                }
                    char ct = matrix[kk][i];
                    
                   
                    dstr[pp++]=matrix[kk][i];

                    if(flag==1){
                            kk=temp1;
                    }
                    kk++;

      }

       for(int i=0;i<pp ; i++){
               printf("%c",dstr[i]);
       }
       printf("\n");

 }

