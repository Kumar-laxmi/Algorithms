def smith_waterman(seq1, seq2, match_score=2, mismatch_score=-1, gap_penalty=-1):
    rows = len(seq1) + 1
    cols = len(seq2) + 1
    matrix = [[0] * cols for _ in range(rows)]

    for i in range(1, rows):
        matrix[i][0] = i * gap_penalty
    for j in range(1, cols):
        matrix[0][j] = j * gap_penalty

    for i in range(1, rows):
        for j in range(1, cols):
            if seq1[i - 1] == seq2[j - 1]:
                match = matrix[i - 1][j - 1] + match_score
            else:
                match = matrix[i - 1][j - 1] + mismatch_score
            delete = matrix[i - 1][j] + gap_penalty
            insert = matrix[i][j - 1] + gap_penalty
            matrix[i][j] = max(match, delete, insert, 0)

    max_score = 0
    max_i = 0
    max_j = 0
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] > max_score:
                max_score = matrix[i][j]
                max_i = i
                max_j = j

    aligned_seq1 = ""
    aligned_seq2 = ""
    i = max_i
    j = max_j
    while matrix[i][j] != 0:
        if seq1[i - 1] == seq2[j - 1]:
            aligned_seq1 = seq1[i - 1] + aligned_seq1
            aligned_seq2 = seq2[j - 1] + aligned_seq2
            i -= 1
            j -= 1
        elif matrix[i][j] == matrix[i - 1][j - 1] + mismatch_score:
            aligned_seq1 = seq1[i - 1] + aligned_seq1
            aligned_seq2 = seq2[j - 1] + aligned_seq2
            i -= 1
            j -= 1
        elif matrix[i][j] == matrix[i - 1][j] + gap_penalty:
            aligned_seq1 = seq1[i - 1] + aligned_seq1
            aligned_seq2 = f"-{aligned_seq2}"
            i -= 1
        else:
            aligned_seq1 = f"-{aligned_seq1}"
            aligned_seq2 = seq2[j - 1] + aligned_seq2
            j -= 1

    return aligned_seq1, aligned_seq2, max_score

sequence1 = "ACGTCG"
sequence2 = "AGTCAG"
alignment1, alignment2, score = smith_waterman(sequence1, sequence2)
print("Alignment 1:", alignment1)
print("Alignment 2:", alignment2)
print("Score:", score)
