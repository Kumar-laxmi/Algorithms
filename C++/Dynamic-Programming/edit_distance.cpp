#include<bits/stdc++.h>
using namespace std;
int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {   
    if(i < 0) {     //if i becomes less than zero and j is still greater or eaqual to zero then the number of operations needed will be equal to j+1;
        return j + 1;
    }
    if(j < 0) {     //similarly if j becomes less than zero and i is still greater or eaqual to zero then the number of operations needed will be equal to i+1;
        return i + 1;
    }
    if(dp[i][j] != -1) {    //checking it this state is precomputed or not
        return dp[i][j];
    }
    if(word1[i] == word2[j]) {      //if both the word has same character, no need to do any operation so move ahead
        return solve(i-1, j-1, word1, word2, dp);
    }  
    int insert = 1 + solve(i, j-1, word1, word2, dp);       //insert in the charcater word1 and move j pointer back by one step
    int deletee = 1 + solve(i-1, j, word1, word2, dp);      //delete the charcater from word1 and move i pointer back by one step
    int replace = 1 + solve(i-1, j-1, word1, word2, dp);    //replace the charcater in word1 and move both i and j pointer back by one step
    return dp[i][j] = min(insert, min(deletee, replace));   //storing the answer of current state in dp array
}

int main()
{
    string word1, word2;    //taking input of two words
    cin>>word1;
    cin>>word2;
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));  //declaring a 2D dp array
    int ans = solve(n-1, m-1, word1, word2, dp);    //calling the function
    cout<<ans<<endl;    //printing the answer
    return 0;
}