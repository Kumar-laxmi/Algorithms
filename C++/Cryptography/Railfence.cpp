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



## Ouput in c++ :

![Screenshot (344)](https://user-images.githubusercontent.com/80022302/218141393-7522bb63-adbc-42da-8a52-946c23573961.png)

*/

#include <bits/stdc++.h> 
using namespace std;

int main(){
	
	string name;
	int key,len;
	//Enter the text u want to convert to railfence
	cout<<"Enter the input message"<<endl;
	cin>>name;
	cout<<"Enter the key"<<endl;
	cin>>key;
	char matrix[30][30];
	len = name.length();//len is the length of input message
    //specify the number of rows/rails
	for(int i=0;i<key;i++){
		for(int j=0;j<len;j++){
			matrix[i][j] = '*';
		}
	}
//code for obtaining railfence matrix       

    //length of input message is equal to the number of coloumns and number of rails equal to number of rows

	int k=0,l=0,temp=0,flag=0;
	 //here the input message should be stored in railfence format.
	for(int i=0;i<len;i++){
		flag=0;
		temp=0;
		 //if k value is equal to 0 or key-1 then convert the k value to negative so that it backtraverses the rows in railfence fashion.
		if(k==0 || k==key-1){
			k=k*(-1);
		}
		//since matrix index cannot be negative whenever k value is -ve convert to positive and after computation convert it back to original value
		if(k<0){
			temp=k;
			k=k*(-1);
			flag=1;
		}
		matrix[k][i]=name[l];
		if(flag==1){
			k=temp;
		}
		l++;
		k++;
	}
	cout<<endl;
	//printing the railfence matrix obtained.Railfence matrix even stores white spaces if the input message is a sentence.
	printf("Railfence matrix is: \n");
	for(int i=0;i<key;i++){
		for(int j=0;j<len;j++){
			cout<<" "<<matrix[i][j];
		}
		cout<<endl;
	}

//code for encryption

	char str[100];
	int glo=0;
	//string the encrypted message from railfence matrix if the entry of the matrix is not '*'
	for(int i=0;i<key;i++){
		for(int j=0;j<len;j++){
			if(matrix[i][j] != '*'){
				str[glo++]=matrix[i][j];
			}
		}
	}

	//printing original message
	cout<<"original message is: "<<endl;
	cout<<""<<name<<endl;
	//printing encrypted message
	cout<<"encrypted message is: "<<endl;
	cout<<str<<endl;
	char dstr[100];
	int glob=0;
//code for decryption
	cout<<"Decrypted message is: "<<endl;
	int kk=0,temp1=0;
	for(int i=0;i<len;i++){
		temp1=0;
		flag=0;
		//if k value is equal to 0 or key-1 then convert the k value to negative so that it backtraverses the rows in railfence fashion.
		if(kk==0 || kk==key-1){
			kk=kk*(-1);
		}
		 //since matrix index cannot be negative whenever k value is -ve convert to positive and after computation convert it back to original value
		if(kk<0){
			temp1=kk;
			kk=kk*(-1);
			flag=1;
		}
		//obtaining decrypted message from railfence matrix
		char ct=matrix[kk][i];
		 dstr[glob++]=ct;
		  
		 if(flag==1){
		 	kk=temp1;
		 }
		 kk++;
	}
	//printing decrypted message
	for(int i=0;dstr[i] !='\0';i++){
		cout<<""<<dstr[i];
	}
	cout<<endl;
}
