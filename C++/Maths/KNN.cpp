#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#include<conio.h>
#include<math.h>

int square(int n){
  return n*n;
}

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
  int maths[] = {56, 78, 23, 19, 20, 45, 90};
  int Eng[] = {67, 34, 23, 22, 14, 68, 99};
  int Science[] = {12, 31, 44, 56, 67, 78,10};
  char Result[12][10] = {"PASS", "PASS","FAIL","FAIL","FAIL","PASS","PASS"};

  cout << "\n Initial Set:";
  cout << "\nMaths\tEng\tScinece\tResults";
  for (int i = 0; i < 7; i++) {
    cout << "\n" << maths[i] << "\t" << Eng[i] << "\t" << Science[i] << "\t" <<Result[i];
  }

  int m,e,s,k;
  cout<<"\nMention the query(maths Eng Science):";
  cin>>m>>e>>s;
  cout<<"\nMention the threshhold:";
  cin>>k;

  int dis[7];
  int tab[7];
  for(int j=0; j<7;j++)
  {
    dis[j] = sqrt(square(m-maths[j]) + square(e - Eng[j]) + square(s - Science[j]));
    tab[j] = dis[j];
  }

  asc_sort(tab,7);

  int nof=0, nop=0;
  cout << "\nMaths\tEng\tScinece\tResults";
  for(int l = 0; l < k; l++) {
    for(int n = 0; n <7; n++)
    {
      if(tab[l] == dis[n])
      {
        cout << "\n" << maths[n] << "\t" << Eng[n] << "\t" << Science[n] << "\t" <<Result[n];
        if (strcmp(Result[n], "FAIL") == 0) {
          nof++;
        }
        if (strcmp(Result[n], "PASS") == 0) {
          nop++;
        }
      }
    }
  }

  if (nof > nop) {
    cout << "\n New Tuple is classified as FAIL";
  }
  else{
    cout<<"\n New Tuple is classified as PASS";
  }

  return 0;
}






 
// void main() {
//   int i, j, l;
//   int tsc = 12;
//   char gen[12] = {
//     'F',
//     'M',
//     'F',
//     'F',
//     'F',
//     'M',
//     'F',
//     'M',
//     'M',
//     'F',
//     'M',
//     'F'
//   };
//   float h[12] = {
//     1.6f,
//     2.0f,
//     1.9f,
//     1.88f,
//     1.7f,
//     1.85f,
//     1.6f,
//     1.7f,
//     2.2f,
//     1.8f,
//     1.95f,
//     1.9f
//   };
  // char op[12][10] = {
  //   "short",
  //   "tall",
  //   "medium",
  //   "medium",
  //   "short",
  //   "medium",
  //   "short",
  //   "short",
  //   "tall",
  //   "medium",
  //   "medium",
  //   "medium"
  // };
 
//   cout << "\n Initial Set:";
//   cout << "\nGender\tHeight\tOutput";
//   for (i = 0; i < 12; i++) {
//     cout << "\n" << gen[i] << "\t" << h[i] << "\t" << op[i];
//   }
 
//   float nh;
//   char ng;
//   cout << "\n Enter tuple to be processed (Height,Gender) :";
//   cin >> nh >> ng;
 
//   int t;
//   cout << "\n Enter threshold:";
//   cin >> t;
 
//   float d[12][2], k;
 
//   //calculating distance to each value in training set
//   for (i = 0; i < 12; i++) {
//     d[i][0] = i;
//     k = h[i] - nh;
//     if (k < 0) {
//       d[i][1] = -k;
//     } else {
//       d[i][1] = k;
//     }
//   }
 
//   //Sorting
//   for (i = 0; i < 11; i++) {
//     for (j = 0; j < 11; j++) {
//       if (d[j][1] > d[j + 1][1]) {
//         k = d[j][1];
//         d[j][1] = d[j + 1][1];
//         d[j + 1][1] = k;
 
//         l = d[j][0];
//         d[j][0] = d[j + 1][0];
//         d[j + 1][0] = l;
//       }
//     }
//   }
 
//   int nos = 0; //no of shorts
//   int nom = 0; //no of mediums
//   int not = 0; //no of talls
 
//   cout << "\nGender\tHeight\tOutput\n";
//   for (i = 0; i < t; i++) {
//     l = d[i][0];
//     cout << gen[l] << "\t" << h[l] << "\t" << op[l] << "\n";
//     if (strcmp(op[l], "short") == 0) {
//       nos++;
//     }
//     if (strcmp(op[l], "medium") == 0) {
//       nom++;
//     }
//     if (strcmp(op[l], "tall") == 0) {
//       not++;
//     }
//   }
 
//   cout << "\n No of shorts:" << nos;
//   cout << "\n No of medium:" << nom;
//   cout << "\n No of tall:" << not;
 
//   if (nos > nom && nos > not) {
//     cout << "\n New Tuple is classified as Short";
//   }
 
//   if (nom > nos && nom > not) {
//     cout << "\n New Tuple is classified as Medium";
//   }
 
//   if (not > nom && not > nos) {
//     cout << "\n New Tuple is classified as Tall";
//   }
 
//   getch();
// }