
#include <stdio.h>
#include <string.h>
#define MAX 100

void lcsAlgo(char S1[],char S2[]) 
{
  int i, j, m, n, LCS_table[20][20];
  char b[20][20];
  
  m = strlen(S1);
  n = strlen(S2);

  for (i = 0; i <= m; i++)
    LCS_table[i][0] = 0;
  for (i = 0; i <= n; i++)
    LCS_table[0][i] = 0;

  
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
  printf("Length of the lcs is %d",strlen(lcsAlgo)-1);
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