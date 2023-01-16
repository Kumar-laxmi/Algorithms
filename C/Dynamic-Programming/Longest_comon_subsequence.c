#include <stdio.h>
#include <string.h>
#define MAX 100

void lcsAlgo(char S1[],char S2[]) 
{
  int i, j, m, n;
  int LCS_table[20][20]; //2d dp array
 
  m = strlen(S1); //finding length of string 1
  n = strlen(S2); //finding length of string 2
  
  //filling 0's in the matrix (0th row and 0th column)
  for (i = 0; i <= m; i++)
    LCS_table[i][0] = 0;
  for (i = 0; i <= n; i++)
    LCS_table[0][i] = 0;

  //Filling the values in the matrix in the bottom up way
  for (i = 1; i <= m; i++)
  {
    for (j = 1; j <= n; j++) 
    {
      if (S1[i - 1] == S2[j - 1]) 
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j];
      else 
        LCS_table[i][j] = LCS_table[i][j - 1];
    }
  }

  int index = LCS_table[m][n];
  char lcsAlgo[MAX + 1];
  lcsAlgo[index] = '\0';

  i = m, j = n;
  //finding that lcs and storing that in lcsAlgo[] char array
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
  //Printing the final output
  printf("S1 : %s \nS2 : %s \n", S1, S2);
  printf("LCS: %s", lcsAlgo); //printing lcs character array
  printf("Length of the lcs is %d",strlen(lcsAlgo)-1); //printing lcs length
}

int main() 
{
    char s1[MAX],s2[MAX];
    printf("Enter string 1  "); //input string 1
    fgets(s1,MAX, stdin);
    printf("Enter string 2  "); //input string 2
    fgets(s2,MAX,stdin);    
    
    lcsAlgo(s1,s2); //calling the function lcsAlgo where whole process of finding the lcs is done
    printf("\n");
}
