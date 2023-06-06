#include <stdio.h>
#include <string.h>
#define MAX 100

void lcsAlgo(char S1[],char S2[]) 
{
  int i, j, m, n;
  int LCS_table[20][20];  
  
  m = strlen(S1); //length of string 1
  n = strlen(S2); //Length of string 2

  //This base case
  for (i = 0; i <= m; i++)
    LCS_table[i][0] = 0;
  for (i = 0; i <= n; i++)
    LCS_table[0][i] = 0;

  //MAIN LCS LOGIC 
  /*Here firstly we are checking that at current state if the indexes of the both string are equal than we will add 1 to it and decrease our both index pointers
  after that if our current indexes did not match we will not add anything but instead of that we are checking for the alternate indexes value*/

  for (i = 1; i <= m; i++)
  {
    for (j = 1; j <= n; j++) 
    {
      if (S1[i - 1] == S2[j - 1])  
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1; //this is the case when both are equal
      else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j]; //this is for alternate index check
      else 
        LCS_table[i][j] = LCS_table[i][j - 1]; //this is for alternate index check
    }
  }

  int index = LCS_table[m][n];
  printf("Length of longest common subsequence is   %d\n",index-1);
  char lcsAlgo[MAX + 1];
  lcsAlgo[index] = '\0';
  
  /*As we know length of longest common subsequence is stored in LCS_table[m][n] so we fetch that length from LCS_table[m][n] and start iterating from the last indexes
  and here we will check 3 things if both indexes values are equal then we will add that to our lcsAlgo and if they are not equal that means the value must be come from 
  maximum of previous column or row so whaterver is the maximum value according to that we change our i,j pointers*/

  i = m, j = n;
  while (i > 0 && j > 0) 
  {
    if (S1[i - 1] == S2[j - 1]) 
    {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }
  printf("S1 : %s \nS2 : %s \n", S1, S2);
  printf("LCS: %s", lcsAlgo);
}

int main() 
{
    char s1[MAX],s2[MAX];
    printf("Enter string 1  ");
    fgets(s1,MAX, stdin);
    printf("Enter string 2  ");
    fgets(s2,MAX,stdin);
    
    lcsAlgo(s1,s2);
    printf("\n");
}