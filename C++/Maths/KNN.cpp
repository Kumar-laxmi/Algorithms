#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#include<conio.h>
#include<math.h>

//function of square 
int square(int n){
  return n*n;
}

//function to sort an array in ascending
void asc_sort(int a[10], int n)
{
 int i, j, temp;
 for(i=0;i< n-1;i++)
 {
  for(j=i+1;j< n;j++)
  {
   if(a[i]>a[j])
   {
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
   }
  }
 }
}

int main()
{
  int maths[] = {56, 78, 23, 19, 20, 45, 90}; //marks of maths
  int Eng[] = {67, 34, 23, 22, 14, 68, 99}; //marks of English
  int Science[] = {12, 31, 44, 56, 67, 78,10}; //marks of sceince
  char Result[12][10] = {"PASS", "PASS","FAIL","FAIL","FAIL","PASS","PASS"}; //the remarks according to the marks of the subjects


  //display the set of marks and remarks of all the subjects
  cout << "\n Initial Set:";
  cout << "\nMaths\tEng\tScinece\tResults";
  for (int i = 0; i < 7; i++) {
    cout << "\n" << maths[i] << "\t" << Eng[i] << "\t" << Science[i] << "\t" <<Result[i];
  }

  // queries -- m for Maths, e for english, s for science and threshhold k
  int m,e,s,k; 
  cout<<"\nMention the query(maths Eng Science):";
  cin>>m>>e>>s;
  cout<<"\nMention the threshhold:";
  cin>>k;

  int dis[7]; //array consisting euclidian distances between query and all subject set
  int tab[7]; //to store the copy of the dis array
  for(int j=0; j<7;j++)
  {
    dis[j] = sqrt(square(m-maths[j]) + square(e - Eng[j]) + square(s - Science[j]));
    tab[j] = dis[j]; //copying the elements of dis array i tab array
  }

  asc_sort(tab,7); //calling the function to sort tab array in ascending order

  int nof=0, nop=0; // nof --- number of FAIL(s) , nop --- number of PASS(s)
  cout << "\nMaths\tEng\tScinece\tResults";
  for(int l = 0; l < k; l++) {
    for(int n = 0; n <7; n++)
    {
      if(tab[l] == dis[n]) // compare the two arrays to find the common index number(n)
      {
        cout << "\n" << maths[n] << "\t" << Eng[n] << "\t" << Science[n] << "\t" <<Result[n];
        if (strcmp(Result[n], "FAIL") == 0) {
          nof++; //if the Result(n) consists of FAIL then increase fail count by 1
        }
        if (strcmp(Result[n], "PASS") == 0) {
          nop++; //if the Result(n) consists of PASS then increase pass count by 1
        }
      }
    }
  }

  //compare the numbers of pass and fail to declare the classification of the tuple
  if (nof > nop) { 
    cout << "\n New Tuple is classified as FAIL";
  }
  else{
    cout<<"\n New Tuple is classified as PASS";
  }

  return 0;
}


