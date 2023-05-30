/*Name :  Nilay Biswas
Github username : nilay2207
Repositary name : Algorithms*/
/* Problem Statement: Nilay has been given a sum in the form of string. He is beginner at maths, and is only beginning to count, so he can calculate a sum only if the summands follow in non-decreasing order. For example, he can't calculate sum 1+3+2+1 but he can calculate sums 1+1+2 and 3+3. 
Time Complexity:- O(n) where n = str.length() 
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int> v;
  string str; 
  cin >> str;// taking the sum as input in the form of string.
  for(int i = 0; i < str.length(); i++)    // iterating over the string of all elements
  {
    char ch = str[i];
    if(ch == '3' || ch == '2' || ch == '1')
    {
      int result = ch - '0';   // type conversion --> from char to int
      v.push_back(result);    // pushing the int values to a vector 'v'
    }
  }
  sort(v.begin(), v.end()); // sorting the vector
  for(int i = 0; i < v.size(); i++)
  {
    cout << v[i]; // printing back the sorted vector
    if (i != v.size() - 1) {
      cout << "+";
    }
  }
  return 0;
}
