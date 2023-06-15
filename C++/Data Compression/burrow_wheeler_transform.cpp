/*  =============== PROBLEM STATEMENT ============= 

Implement the Burrows-Wheeler Transform (BWT) and its inverse. 
Given an input string s, the program should compute its BWT and then reconstruct the original string using the inverse BWT.

============= SOLUTION ==============
The bwt function takes a string s and returns its Burrows-Wheeler transform bwt. 
1. After adding sentinel character ('$'), function generates the suffix array by using the iota function to fill a vector sa with values from 0 to n - 1, where n is the length of the input string. 
2. The modified_quicksort function is then used to sort the suffixes lexicographically. 
3. Finally, the transform bwt is constructed by concatenating the last characters of each sorted suffix, with a special sentinel character $ appended to the end.


The inverse_bwt function takes the transformed string bwt and returns the original string t. 
1. The function first constructs the first column of the Burrows-Wheeler matrix by sorting the transform bwt. 
2. It then iteratively constructs string by adding the last character of the previous iteration to the beginning of the string. 
3. The index of the next character is determined by counting the number of occurrences of the current character up to and including the current index in the transformed string bwt, and then finding the index of the nth occurrence of the character in the first column of the Burrows-Wheeler matrix.

Sample Input: 
banana

Sample Output: 
BWT of banana$ is annb$aa
Inverse BWT of annb$aa is banana
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// to sort lexographically
void modified_quicksort(vector<int>& sa, string& s, int left, int right){
    // base case: if the left index is greater than or equal to the right index, return
    if (left >= right) return;
    
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = sa[pivotIndex];

    int i = left, j = right;
    while (i <= j){
        // move the left pointer to the right until it points to an element greater than or equal to the pivot
        while ((s.substr(sa[i]) + s.substr(0, sa[i])) < (s.substr(pivotValue) + s.substr(0, pivotValue))){
            i++;
        }
        // move the right pointer to the left until it points to an element less than or equal to the pivot
        while ((s.substr(sa[j]) + s.substr(0, sa[j])) > (s.substr(pivotValue) + s.substr(0, pivotValue))){
            j--;
        }
        // if the left pointer is less than or equal to the right pointer, swap the elements at their positions
        if (i <= j){
            swap(sa[i], sa[j]);
            i++;
            j--;
        }
    }
    modified_quicksort(sa, s, left, j);
    modified_quicksort(sa, s, i, right);
}

string bwt(string s){
    int n = s.size();
   
    // generate initial suffix array and to sort lexicographically
    vector<int> sa(n);
    iota(sa.begin(), sa.end(), 0);
    modified_quicksort(sa, s, 0, sa.size() - 1);
    
    // construct the transformed string bwt
    string bwt;
    for (int i = 0; i < n; i++){
        int j = sa[i];
        if (j == 0){
            bwt += '$';
        }
        else{
            bwt += s[j - 1];
        }       
    }
    return bwt;
}

// finds the index of the nth occurrence of a character ch in the input string
int findNthOccurrenceIndex(string& str, char ch, int n){ 
    // create a vector to store the number of occurrences up to each index 
    vector<int> occurrences(str.size());
    for (int i = 0; i < str.size(); i++){
        int count = 0;
        for (int j = 0; j <= i; j++){
            if (str[j] == ch){
                count++;
            }
        }
        occurrences[i] = count;
    }

    // search for the nth occurrence in occurrences vector
    for (int i = 0; i < occurrences.size(); i++) {
        if (occurrences[i] == n) {
            return i;
        }
    }
    return -1;  // nth occurrence not found
}


string inverse_bwt(string& bwt) {
    string t;
    int index = 0;
    string first_column = bwt;
    sort(first_column.begin(), first_column.end());

    // reconstruct the original string t
    for (int i = 0; i < bwt.size() - 1; i++){
        char ch = bwt[index];
        t = ch + t;
        int count = 0;
        for (int i = 0; i <= index; i++){
            if (bwt[i] == bwt[index]){
                count++;
            }
        }
        index = findNthOccurrenceIndex(first_column, ch, count);
    }
    return t;
}

int main(){
    // get input string from user
    string s;
    cout << "Enter a string: ";
    cin >> s;
    // add sentinel character $
    s += "$";
    // calculates BWT of input string
    string bw = bwt(s);
    cout << "BWT of " << s << " is " << bw << endl;
    // calculates inverse BWT from the transformed string
    string ibw = inverse_bwt(bw);
    cout << "Inverse BWT of " << bw << " is " << ibw << endl;
    return 0;
}
