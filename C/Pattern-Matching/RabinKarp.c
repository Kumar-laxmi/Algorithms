/**
 * @file
 * @brief A program to calculate factors of a given number
 * @author [Abhinav Kar](https://github.com/Abhinavkar)
* Like the Naive Algorithm, the Rabin-Karp algorithm also slides the patterntern one by one.
 * But unlike the Naive algorithm,
* the Rabin Karp algorithm matches the hash value of the patterntern with the hash value of the current substring of text, 
 * and if the hash values match then only it starts matching individual characters. 
 * So Rabin Karp algorithm needs to calculate hash values for the following strings.
 * Description Refrence Taken from GfG
 */
/* Following program is a C implementation of Rabin Karp
Algorithm given in the CLRS book*/
#include <stdio.h>
#include <string.h>
#define d 256
void search(char pattern[], char inputtext[], int q)
{
	int lengthOfPattern = strlen(pattern);
	int lengthOfInputtxt = strlen(inputtext);
	int i, j;
	int hashForPattern = 0; // hash value for pattern
	int hashForInputtxt = 0; // hash value for input text
	int h = 1;

	for (i = 0; i < lengthOfPattern - 1; i++)
		h = (h * d) % q;

// Calculating  the hash value of pattern first 
	for (i = 0; i < lengthOfPattern; i++) {
	hashForPattern = (d * p + pattern[i]) % q;
		 hashForInputtxt = (d * hashForInputtxt + inputtext[i]) % q;
	}
	for (i = 0; i <= lengthOfInputtxt - lengthOfPattern; i++) {

		// Check the hash values of current window of text
	// and pattern. If the hash values match then only
		// check for characters one by one
		if (hashForPattern ==  hashForInputtxt) {
			for (j = 0; j < lengthOfPattern; j++) {
			if (inputtext[i + j] != pattern[j])
					break;
			}
			if (j == lengthOfPattern)
			printf("Pattern found at index %d \n", i);
		}
		if (i < lengthOfInputtxt - lengthOfPattern) {
			 hashForInputtxt = (d * ( hashForInputtxt - inputtext[i] * h) + inputtext[i + lengthOfPattern]) % q;
			if ( hashForInputtxt < 0)
				hashForInputtxt = (hashForInputtxt + q);
		}
	}
}

/* Driver Code */
int main()
{
	char inputtext[] = "Any Text Can be Taken";
	char pattern[] = "an";

	int q = 101;// q is taken because it results in good hashing 

	// function call
search(pattern, inputtext, q);
	return 0;
}

