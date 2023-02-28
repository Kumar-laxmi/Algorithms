/*
 ------------------------------------------------ Prerequisite -----------------------------------------------------------

    --> The length of the key should be equal to the length of the text message going to be sent.

 ---------------------------------------------- Problem Statement --------------------------------------------------------

    Given a string which needed to be encrypted based on vernam cipher and decrypt it.

    INPUT  :- Steve Rogers

    OUTPUT :- UTTOM EQGTKA  --> Encrypted text
              Steve Rogers  --> Decrypted text

 ------------------------------------------------ Vernam Cipher ----------------------------------------------------------

    The Vernam cipher is a substitution cipher where each plain text character is encrypted using its own key.
    This key — or key stream — is randomly generated or is taken from a one-time pad, e.g. a page of a book.
    The key must be equal in length to the plain text message. The fact that each character of the message is encrypted
    using a different key prevents any useful information being revealed through a frequency analysis of the cipher text.

 ------------------------------------------------- Algorithm -------------------------------------------------------------

    1) Obtain the 8-bit ASCII code for each letter of the plain text

    2) Obtain the 8-bit ASCII code for each letter of the key

    3) Carry out the XOR operation, applying it to each corresponding pair of bits

    4) Obtain the binary code for each character of the cipher text

    5) Obtain the 8-bit ASCII code for each letter of the key

    6) Carry out the XOR operation, applying it to each corresponding pair of bits it will decrypt the message.

 ------------------------------------------------ Complexities -----------------------------------------------------------

    Time Complexity  :- BigO(n)  --> where n is the length of the string
    Space Complexity :- BigO(26) --> Since we need an additional string to store all the alphabets, it's length is 26.

 */
#include<stdio.h>
#include<string.h>
// Declaring global variables
// Character array named arr to store the text message given by the suer. 
char arr[26][26];
// Character array named messgae, encrypted messgae, decrypted message to store the messages at certain states.
char message[22],key[22],encryptedMessage[22],decryptedMessage[22];
// Declaring the functions that is going to be called
int findRow(char);
int findColumn(char);
int findDecRow(char,int);
int main() 
{
	// Declaring the iterating varibles
	int i=0,j,k,r,c;
	// The variable that is uing to encrypt the characters in the text by subracting this k's value.
	k=96;
	for (i=0;i<26;i++) 
	{
		k++;
		for (j=0;j<26;j++) 
		{
			arr[i][j]=k++;
			if(k==123)
			{
				k=97;	
			} 
		}
	}
	// Reading the text message from the user.
	printf("Enter text message = ");
	fgets(message);
	// Reading the key from the user.
	printf("Enter the key = ");
	fgets(key);
	// The encryption starts here
	for (i=0; key[i]!='\0'; i++) 
	{
		// Calling the methods to return the correct index of the row and column for encryption
		c=findRow(key[i]);
		r=findColumn(message[i]);
		encryptedMessage[i]=arr[r][c];
	}
	// To notify that the array reaches it's end we are giving this,
	encryptedMessage[i]='\0';
	// Printing the encrypted message to the user.
	printf("Encrypted message is = ");
	for (i=0;encryptedMessage[i]!='\0';i++)
	{
		printf("%c",encryptedMessage[i]);	
	} 
	// The decryption starts here,
	for (i=0;key[i]!='\0';i++) 
	{
		// Calling the methods to return the correct index of the row and column for decryption of the text
		c=findColumn(key[i]);
		r=findDecRow(encryptedMessage[i],c);
		decryptedMessage[i]=arr[r][0];
	}
	// To notify that the array reaches it's end we are giving this,
	decryptedMessage[i]='\0';
	// Printing the decrypted message to the user.
	printf("\nDecrypted message is = ");
	for (i=0;decryptedMessage[i]!='\0';i++)
	{
		printf("%c",decryptedMessage[i]);	
	} 
	getch();
	return(0);
}
int findRow(char c) 
{
	//Declaring a iterating variable, to iterate through the array,
	int i;
	for (i=0;i<26;i++)
	{
		//When the index of text matches with the row we are returning it's arr index.
		if(arr[0][i]==c)
		{
			return(i);	
		} 
	}
}
int findColumn(char c) 
{
	//Declaring a iterating variable, to iterate through the array,
	int i;
	for (i=0;i<26;i++) 
	{
		//When the index of text matches with the column we are returning it's arr index.
		if(arr[i][0]==c)
		{
			return(i);
		} 
	}
}
int findDecRow(char c,int j)
{
	//Declaring a iterating variable, to iterate through the array,
	int i;
	for (i=0;i<26;i++)
	{
		//When the index of text matches with the row we are returning it's arr index.
		if(arr[i][j]==c)
		{
			return(i);	
		} 
	}
}
