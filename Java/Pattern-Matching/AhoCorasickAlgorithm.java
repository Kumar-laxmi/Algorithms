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

import java.util.Arrays;
import java.util.Queue;
import java.util.LinkedList;

class AhoCorasickAlgorithm {
    static int MAXS = 500;
    static int MAXC = 26;

    static int[] out = new int[MAXS];
    static int[] f = new int[MAXS];
    static int[][] g = new int[MAXS][MAXC];

    static int buildMatchingMachine(String arr[], int k, int MAXS, int MAXC) {
        Arrays.fill(out, 0);
        for (int i = 0; i < MAXS; i++)
            Arrays.fill(g[i], -1);

        int states = 1;
        for (int i = 0; i < k; ++i) {
            String word = arr[i];
            int currentState = 0;

            for (int j = 0; j < word.length(); ++j) {
                int ch = word.charAt(j) - 'a';
                if (g[currentState][ch] == -1)
                    g[currentState][ch] = states++;

                currentState = g[currentState][ch];
            }

            out[currentState] |= (1 << i);
        }

        for (int ch = 0; ch < MAXC; ++ch) {
            if (g[0][ch] == -1)
                g[0][ch] = 0;
        }

        Arrays.fill(f, -1);
        Queue<Integer> q = new LinkedList<>();

        for (int ch = 0; ch < MAXC; ++ch) {
            if (g[0][ch] != 0) {
                f[g[0][ch]] = 0;
                q.add(g[0][ch]);
            }
        }

        while (!q.isEmpty()) {
            int state = q.peek();
            q.remove();

            for (int ch = 0; ch < MAXC; ++ch) {
                if (g[state][ch] != -1) {
                    int failure = f[state];
                    while (g[failure][ch] == -1)
                        failure = f[failure];

                    failure = g[failure][ch];
                    f[g[state][ch]] = failure;
                    out[g[state][ch]] |= out[failure];
                    q.add(g[state][ch]);
                }
            }
        }
        return states;
    }

    static int findNextState(int currentState, char nextInput, int MAXC) {
        int answer = currentState;
        int ch = nextInput - 'a';

        if (ch < 0 || ch >= MAXC)
            return answer;

        while (g[answer][ch] == -1)
            answer = f[answer];

        return g[answer][ch];
    }

    static void searchWords(String arr[], int k, String text, int MAXS, int MAXC) {
        buildMatchingMachine(arr, k, MAXS, MAXC);
        int currentState = 0;

        for (int i = 0; i < text.length(); ++i) {
            currentState = findNextState(currentState, text.charAt(i), MAXC);
            if (out[currentState] == 0)
                continue;

            for (int j = 0; j < k; ++j) {
                if ((out[currentState] & (1 << j)) > 0) {
                    System.out.print("Word " + arr[j] +
                            " appears from " +
                            (i - arr[j].length() + 1) +
                            " to " + i + "\n");
                }
            }
        }
    }

    public static void main(String[] args) {
        String arr[] = { "he", "she", "hers", "his" };
        String text = "ahishers";
        int k = arr.length;
        int MAXS = 500;
        int MAXC = 26;
        searchWords(arr, k, text, MAXS, MAXC);
    }
}
