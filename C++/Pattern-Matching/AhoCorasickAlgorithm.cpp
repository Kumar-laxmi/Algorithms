// Given an input text and an array of k words, arr[], find all occurrences of all words in the input text. Let n be the length of text and m be the total number of characters in all words, i.e. m = length(arr[0]) + length(arr[1]) + … + length(arr[k-1]). Here k is total numbers of input words.

// Example:  

// Input: text = "ahishers"    
//        arr[] = {"he", "she", "hers", "his"}

// Output:
//    Word his appears from 1 to 3
//    Word he appears from 4 to 5
//    Word she appears from 3 to 5
//    Word hers appears from 4 to 7
// If we use a linear time searching algorithm like KMP, then we need to one by one search all words in text[]. This gives us total time complexity as O(n + length(word[0]) + O(n + length(word[1]) + O(n + length(word[2]) + … O(n + length(word[k-1]). This time complexity can be written as O(n*k + m). 

// Aho-Corasick Algorithm finds all words in O(n + m + z) time where z is total number of occurrences of words in text. The Aho–Corasick string matching algorithm formed the basis of the original Unix command fgrep
using namespace std;
#include <bits/stdc++.h>
const int MAXS = 500;
const int MAXC = 26;
int out[MAXS];
int f[MAXS];
int g[MAXS][MAXC];
int buildMatchingMachine(string arr[], int k)
{
	memset(out, 0, sizeof out);
	memset(g, -1, sizeof g);
	int states = 1;
	for (int i = 0; i < k; ++i)
	{
		const string &word = arr[i];
		int currentState = 0;

		for (int j = 0; j < word.size(); ++j)
		{
			int ch = word[j] - 'a';

			if (g[currentState][ch] == -1)
				g[currentState][ch] = states++;
			currentState = g[currentState][ch];
		}
		out[currentState] |= (1 << i);
	}

	
	for (int ch = 0; ch < MAXC; ++ch)
		if (g[0][ch] == -1)
			g[0][ch] = 0;

	memset(f, -1, sizeof f);
	queue<int> q;	
	for (int ch = 0; ch < MAXC; ++ch)
	{
		if (g[0][ch] != 0)
		{
			f[g[0][ch]] = 0;
			q.push(g[0][ch]);
		}
	}

	while (q.size())
	{
		int state = q.front();
		q.pop();	
		for (int ch = 0; ch <= MAXC; ++ch)
		{
			if (g[state][ch] != -1)
			{
				int failure = f[state];				
				while (g[failure][ch] == -1)
					failure = f[failure];
				failure = g[failure][ch];
				f[g[state][ch]] = failure;			
				out[g[state][ch]] |= out[failure];				
				q.push(g[state][ch]);
			}
		}
	}
	return states;
}

int findNextState(int currentState, char nextInput)
{
	int answer = currentState;
	int ch = nextInput - 'a';	  
	while (g[answer][ch] == -1)
		answer = f[answer];
	return g[answer][ch];
}


void searchWords(string arr[], int k, string text)
{
	buildMatchingMachine(arr, k);
	int currentState = 0;
	for (int i = 0; i < text.size(); ++i)
	{
		currentState = findNextState(currentState, text[i]);
		if (out[currentState] == 0)
			continue;

		for (int j = 0; j < k; ++j)
		{
			if (out[currentState] & (1 << j))
			{
				cout << "Word " << arr[j] << " appears from "< i - arr[j].size() + 1 << " to " << i << endl;
			}
		}
	}
}


int main()
{
	string arr[] = {"he", "she", "hers", "his"};
	string text = "ahishers";
	int k = sizeof(arr)/sizeof(arr[0]);
	searchWords(arr, k, text);
	return 0;
}
