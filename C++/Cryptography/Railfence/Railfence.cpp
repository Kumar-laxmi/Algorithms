#include <bits/stdc++.h> 
using namespace std;

int main(){
	
	string name;
	int key,len;
	cout<<"Enter the input message"<<endl;
	cin>>name;
	cout<<"Enter the key"<<endl;
	cin>>key;
	char matrix[30][30];
	len = name.length();
	for(int i=0;i<key;i++){
		for(int j=0;j<len;j++){
			matrix[i][j] = '*';
		}
	}
	int k=0,l=0,temp=0,flag=0;
	for(int i=0;i<len;i++){
		flag=0;
		temp=0;
		if(k==0 || k==key-1){
			k=k*(-1);
		}
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
	printf("\n");
	printf("Railfence matrix is: \n");
	for(int i=0;i<key;i++){
		for(int j=0;j<len;j++){
			printf("%c \t",matrix[i][j]);
		}
		printf("\n");
	}
	char str[100];
	int glo=0;
	for(int i=0;i<key;i++){
		for(int j=0;j<len;j++){
			if(matrix[i][j] != '*'){
				str[glo++]=matrix[i][j];
			}
		}
	}
	printf("encrypted message is: \n");
	cout<<str<<endl;
	char dstr[100];
	int glob=0;
	printf("Decrypted message is: \n");
	int kk=0,temp1=0;
	for(int i=0;i<len;i++){
		temp1=0;
		flag=0;
		if(kk==0 || kk==key-1){
			kk=kk*(-1);
		}
		if(kk<0){
			temp1=kk;
			kk=kk*(-1);
			flag=1;
		}
		char ct=matrix[kk][i];
		 dstr[glob++]=ct;
		 if(flag==1){
		 	kk=temp1;
		 }
		 kk++;
	}
	for(int i=0;dstr[i] !='\0';i++){
		printf("%c",dstr[i]);
	}
	printf("\n");
}