public class smith_waterman_algo {
    public static void main(String[] args) {
        String sequence1 = "ACGTCG";
        String sequence2 = "AGTCAG";
        int matchScore = 2;
        int mismatchScore = -1;
        int gapPenalty = -1;

        smithWaterman(sequence1, sequence2, matchScore, mismatchScore, gapPenalty);
    }

    public static void smithWaterman(String seq1, String seq2, int matchScore, int mismatchScore, int gapPenalty) {
        int rows = seq1.length() + 1;
        int cols = seq2.length() + 1;

        int[][] matrix = new int[rows][cols];

        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
        for (int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }

        int maxScore = 0;
        int maxI = 0;
        int maxJ = 0;
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                int match = (seq1.charAt(i - 1) == seq2.charAt(j - 1)) ? matrix[i - 1][j - 1] + matchScore : matrix[i - 1][j - 1] + mismatchScore;
                int delete = matrix[i - 1][j] + gapPenalty;
                int insert = matrix[i][j - 1] + gapPenalty;
                int score = Math.max(match, Math.max(delete, Math.max(insert, 0)));

                if (score > maxScore) {
                    maxScore = score;
                    maxI = i;
                    maxJ = j;
                }

                matrix[i][j] = score;
            }
        }

        StringBuilder alignedSeq1 = new StringBuilder();
        StringBuilder alignedSeq2 = new StringBuilder();
        int i = maxI;
        int j = maxJ;
        while (matrix[i][j] != 0) {
            if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                alignedSeq1.insert(0, seq1.charAt(i - 1));
                alignedSeq2.insert(0, seq2.charAt(j - 1));
                i--;
                j--;
            } else if (matrix[i][j] == matrix[i - 1][j - 1] + mismatchScore) {
                alignedSeq1.insert(0, seq1.charAt(i - 1));
                alignedSeq2.insert(0, seq2.charAt(j - 1));
                i--;
                j--;
            } else if (matrix[i][j] == matrix[i - 1][j] + gapPenalty) {
                alignedSeq1.insert(0, seq1.charAt(i - 1));
                alignedSeq2.insert(0, '-');
                i--;
            } else {
                alignedSeq1.insert(0, '-');
                alignedSeq2.insert(0, seq2.charAt(j - 1));
                j--;
            }
        }

        System.out.println("Alignment 1: " + alignedSeq1.toString());
        System.out.println("Alignment 2: " + alignedSeq2.toString());
        System.out.println("Score: " + maxScore);
    }
}
