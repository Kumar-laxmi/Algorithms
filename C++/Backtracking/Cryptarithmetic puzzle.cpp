/* PROBLEM STATEMENT
Given a mathematical equation made up of words, where each letter represents 
a unique digit from 0-9, find the value of each letter such that the equation is true.
*/

#include <iostream>
#include <string>
using namespace std;

const int N = 26;

bool isComplete(string words[], int len, int letterAssignment[N]) {
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < words[i].length(); j++) {
            if(letterAssignment[words[i][j] - 'A'] == -1) {
                return false;
            }
        }
    }
    return true;
}

bool isValid(string words[], int len, int letterAssignment[N]) {
    int carry = 0;
    int sum = 0;
    int index;
    // Check for the last word
    for(int i = words[len-1].length() - 1; i >= 0; i--) {
        index = words[len-1][i] - 'A';
        sum = letterAssignment[index] + carry;
        if(i == 0 && sum >= 10) {
            return false;
        }
        carry = sum / 10;
        letterAssignment[index] = sum % 10;
    }
    // Check for the remaining words
    for(int i = len - 2; i >= 0; i--) {
        carry = 0;
        for(int j = words[i].length() - 1; j >= 0; j--) {
            index = words[i][j] - 'A';
            sum = letterAssignment[index] + carry;
            if(j == 0 && sum >= 10) {
                return false;
            }
            carry = sum / 10;
            letterAssignment[index] = sum % 10;
        }
    }
    return true;
}

void printSolution(int letterAssignment[N]) {
    for(int i = 0; i < N; i++) {
        if(letterAssignment[i] != -1) {
            cout << (char)(i + 'A') << " = " << letterAssignment[i] << endl;
        }
    }
}

bool solveCryptarithmetic(string words[], int len, int letterAssignment[N]) {
    if(isComplete(words, len, letterAssignment)) {
        if(isValid(words, len, letterAssignment)) {
            printSolution(letterAssignment);
            return true;
        }
        return false;
    }

    for(int i = 0; i < len; i++) {
        for(int j = 0; j < words[i].length(); j++) {
            if(letterAssignment[words[i][j] - 'A'] == -1) {
                for(int k = (i == 0 && j == 0) ? 1 : 0; k <= 9; k++) {
                    letterAssignment[words[i][j] - 'A'] = k;
                    if(solveCryptarithmetic(words, len, letterAssignment)) {
                        return true;
                    }
                    letterAssignment[words[i][j] - 'A'] = -1;
                }
                return false;
            }
        }
    }
    return false;
}

int main() {
    string words[] = {"SEND", "MORE", "MONEY"};
    int len = sizeof(words)/sizeof(words[0]);
    int letterAssignment[N];
    for(int i = 0; i < N; i++) {
        letterAssignment[i] = -1;
    }
    if(!solveCryptarithmetic(words, len, letterAssignment)) {
        cout << "No solution found." << endl;
    }
    return 0;
}

