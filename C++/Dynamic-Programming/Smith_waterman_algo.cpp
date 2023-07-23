#include <iostream>
#include <vector>

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

void smith_waterman(const std::string& seq1, const std::string& seq2, int match_score, int mismatch_score, int gap_penalty) {
    int rows = seq1.length() + 1;
    int cols = seq2.length() + 1;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));

    // Fill the scoring matrix
    int max_score = 0;
    int max_i = 0;
    int max_j = 0;
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            int match = (seq1[i - 1] == seq2[j - 1]) ? matrix[i - 1][j - 1] + match_score : matrix[i - 1][j - 1] + mismatch_score;
            int delete_score = matrix[i - 1][j] + gap_penalty;
            int insert_score = matrix[i][j - 1] + gap_penalty;
            int score = max(match, delete_score, insert_score, 0);

            if (score > max_score) {
                max_score = score;
                max_i = i;
                max_j = j;
            }

            matrix[i][j] = score;
        }
    }

    // Traceback to find the alignment
    std::string aligned_seq1, aligned_seq2;
    int i = max_i;
    int j = max_j;
    while (matrix[i][j] != 0) {
        if (seq1[i - 1] == seq2[j - 1]) {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            i--;
            j--;
        } else if (matrix[i][j] == matrix[i - 1][j - 1] + mismatch_score) {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            i--;
            j--;
        } else if (matrix[i][j] == matrix[i - 1][j] + gap_penalty) {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = '-' + aligned_seq2;
            i--;
        } else {
            aligned_seq1 = '-' + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            j--;
        }
    }

    std::cout << "Alignment 1: " << aligned_seq1 << std::endl;
    std::cout << "Alignment 2: " << aligned_seq2 << std::endl;
    std::cout << "Score: " << max_score << std::endl;
}

int main() {
    std::string sequence1 = "ACGTCG";
    std::string sequence2 = "AGTCAG";
    int match_score = 2;
    int mismatch_score = -1;
    int gap_penalty = -1;

    smith_waterman(sequence1, sequence2, match_score, mismatch_score, gap_penalty);

    return 0;
}
