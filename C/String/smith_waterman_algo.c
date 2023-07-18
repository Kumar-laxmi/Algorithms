#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b, int c, int d) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    if (d > max) {
        max = d;
    }
    return max;
}

void reverse_string(char* str) {
    int length = strlen(str);
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void smith_waterman(const char* seq1, const char* seq2, int match_score, int mismatch_score, int gap_penalty) {
    int rows = strlen(seq1) + 1;
    int cols = strlen(seq2) + 1;

    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
  
    for (int i = 0; i < rows; i++) {
        matrix[i][0] = 0;
    }
    for (int j = 0; j < cols; j++) {
        matrix[0][j] = 0;
    }

    int max_score = 0;
    int max_i = 0;
    int max_j = 0;
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            int match = (seq1[i - 1] == seq2[j - 1]) ? matrix[i - 1][j - 1] + match_score : matrix[i - 1][j - 1] + mismatch_score;
            int delete = matrix[i - 1][j] + gap_penalty;
            int insert = matrix[i][j - 1] + gap_penalty;
            int score = max(match, delete, insert, 0);

            if (score > max_score) {
                max_score = score;
                max_i = i;
                max_j = j;
            }

            matrix[i][j] = score;
        }
    }

    char aligned_seq1[rows + cols];
    char aligned_seq2[rows + cols];
    int aligned_i = 0;
    int aligned_j = 0;

    int i = max_i;
    int j = max_j;
    while (matrix[i][j] != 0) {
        if (seq1[i - 1] == seq2[j - 1]) {
            aligned_seq1[aligned_i++] = seq1[i - 1];
            aligned_seq2[aligned_j++] = seq2[j - 1];
            i--;
            j--;
        }
        else if (matrix[i][j] == matrix[i - 1][j - 1] + mismatch_score) {
            aligned_seq1[aligned_i++] = seq1[i - 1];
            aligned_seq2[aligned_j++] = seq2[j - 1];
            i--;
            j--;
        }
        else if (matrix[i][j] == matrix[i - 1][j] + gap_penalty) {
            aligned_seq1[aligned_i++] = seq1[i - 1];
            aligned_seq2[aligned_j++] = '-';
            i--;
        }
        else {
            aligned_seq1[aligned_i++] = '-';
            aligned_seq2[aligned_j++] = seq2[j - 1];
            j--;
        }
    }

    aligned_seq1[aligned_i] = '\0';
    aligned_seq2[aligned_j] = '\0';
    reverse_string(aligned_seq1);
    reverse_string(aligned_seq2);

    printf("Alignment 1: %s\n", aligned_seq1);
    printf("Alignment 2: %s\n", aligned_seq2);
    printf("Score: %d\n", max_score);
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    const char* sequence1 = "ACGTCG";
    const char* sequence2 = "AGTCAG";
    int match_score = 2;
    int mismatch_score = -1;
    int gap_penalty = -1;

    smith_waterman(sequence1, sequence2, match_score, mismatch_score, gap_penalty);

    return 0;
}
