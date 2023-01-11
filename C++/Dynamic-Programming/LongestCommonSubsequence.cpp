// ====================== Problem Statement ==========================
/*
 Given two sequences A and B, sequence C is a common subsequence of A and B if C is subsequence of both A and B. Our task is to find the maximum length common subsequence between two given sequences. A subsequence is a sequence that appears in the same relative order need not to be continuous.

 For example if- A= MOON and B=MORN, then longest common subsequence is - MON

 Solution-
 We can solve this using Dynammic Programming approach.
 If A= {A1,A2,...Am}, B={B1,B2,...,Bn}, and the longest common subsequence(LCS) is C= {C1,C2,...Ck}
    If Am=Bn then Ck=Am=Bn then Ck-1 is  LCS of Am-1 & Bn-1.
        else if Ck!=Am then Ck is LCS of Am-1 & Bn.
        else if Ck!=Bm then Ck is LCS of Am & Bn-1.
*/

// // ====================== Code with C++ ==========================
#include<iostream>
using namespace std;

//for computing the sequence
string direction[10][10];

//recursive function to compute the subsequence and print it
void printSubseq(string s1,int i, int j){
	if(i==-1 ||j==-1){
		return ;
	}
	//if direction[i][j]== "diagonal", we have found the common element in the two strings
	if(direction[i][j]== "diagonal" ) 
	{ 
	  printSubseq(s1, i-1,j-1);
	  cout<<s1[i];
	}
	else if(direction[i][j]== "up"){
		printSubseq(s1, i-1,j);
	}
	else if(direction[i][j]== "left"){
		printSubseq(s1, i,j-1);
	}
}

int main(){
	string s1, s2;
	cout<<"Enter string s1 and s2: ";
	cin>>s1>>s2;
	int m = s1.length()+1, n = s2.length()+1;
	
	//for storing the longest length of subsequence at each step
	int mat[m][n];
	
	/*Compute mat[i,j] as-
        mat[i,j] ={
	 	        0, if i=0, or j=0
	 			mat[i-1,j-1]+1, if i,j>0 & ai=bj
	 			max(mat[i-1, j],mat([i, j-1]) if i,j>0 & ai!=bj)
				}
	*/ 
    //the first row and first column will have have value 0
	for(int i=0; i<m; i++){
	 mat[i][0] = 0;
	}
	for(int i=0; i<n; i++){
	 mat[0][i] = 0;
	}

	/*direction matrix will indicate the direction to go(left,up, or diagonal) to find out 
	the common subsequence*/ 
	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
		 if(s1[i-1]==s2[j-1]){
		 	mat[i][j] = 1 + mat[i-1][j-1];
		 	direction[i-1][j-1] = "diagonal"; 	
		 }
		 else{
		 	if(mat[i-1][j]>=mat[i][j-1]){
		 		mat[i][j] =mat[i-1][j];
		 		direction[i-1][j-1] = "up";
			 }
			else{
				mat[i][j] =mat[i][j-1];
		 		direction[i-1][j-1] = "left";
			}
		 }
		}
	}
    
	cout<<"Length of longest subsequence is: "<<mat[m-1][n-1]<<endl;
     
	cout<<"The Common Subsequence is: "<<endl;
	// print the subsequence
	printSubseq(s1,s1.length()-1, s2.length()-1);
	return 0;
	
}
