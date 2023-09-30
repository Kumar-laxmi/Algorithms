//Time Complexity - O(n)
//Space Complexity - O(1)

//ABCBA - TRUE
//ABCBBC - FALSE

#include<iostream>
using namespace std;
bool isPalindrome(string s){
    int n = s.length();
    if(n==0) return false;
    int st = 0;
    int end = n;
    while(st<end){
        if(s[st]!=s[end]){
            return true;
        }
        else{
            st++;
            end--;
        }
    }
    return false;
}
int main(){
    string s;
    cin>>s;
    isPalindrome(s);
    return 0;
}