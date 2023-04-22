//// Define scoring scheme
//int match_score = 1;
//int mismatch_score = -1;
//int gap_score = -2;
//
//// Define input sequences
//string sequence1 = "ACGTAGC";
//string sequence2 = "ACTAGCTA";
//
//// Define length of sequences
//int n = sequence1.length();
//int m = sequence2.length();
//
//// Initialize score matrix
//int score[n + 1][m + 1];
//for (int i = 0; i <= n; i++) {
//    for (int j = 0; j <= m; j++) {
//        score[i][j] = 0;
//    }
//}
//
//// Fill in first row and first column of score matrix
//for (int i = 0; i <= n; i++) {
//    score[i][0] = i * gap_score;
//}
//for (int j = 0; j <= m; j++) {
//    score[0][j] = j * gap_score;
//}
//
//// Fill in rest of score matrix using dynamic programming
//for (int i = 1; i <= n; i++) {
//    for (int j = 1; j <= m; j++) {
//        int match_mismatch_score = sequence1[i - 1] == sequence2[j - 1] ? match_score : mismatch_score;
//        int diagonal_score = score[i - 1][j - 1] + match_mismatch_score;
//        int up_score = score[i - 1][j] + gap_score;
//        int left_score = score[i][j - 1] + gap_score;
//        score[i][j] = max(diagonal_score, max(up_score, left_score));
//    }
//}
//
//// Trace back the optimal alignment
//string aligned_seq1 = "";
//string aligned_seq2 = "";
//int i = n;
//int j = m;
//while (i > 0 || j > 0) {
//    if (i > 0 && score[i][j] == score[i - 1][j] + gap_score) {
//        aligned_seq1 = sequence1[i - 1] + aligned_seq1;
//        aligned_seq2 = "-" + aligned_seq2;
//        i--;
//    }
//    else if (j > 0 && score[i][j] == score[i][j - 1] + gap_score) {
//        aligned_seq1 = "-" + aligned_seq1;
//        aligned_seq2 = sequence2[j - 1] + aligned_seq2;
//        j--;
//    }
//    else {
//        aligned_seq1 = sequence1[i - 1] + aligned_seq1;
//        aligned_seq2 = sequence2[j - 1] + aligned_seq2;
//        i--;
//        j--;
//    }
//}
//
//// Output the optimal alignment and score
//cout << "Optimal alignment score: " << score[n][m] << endl;
//cout << "Optimal alignment:" << endl;
//cout << aligned_seq1 << endl;
//cout << aligned_seq2 << endl;


// Initialize variables
//int i = n;  // Index for sequence 1
//int j = m;  // Index for sequence 2
//string aligned_seq1 = "";
//string aligned_seq2 = "";
//
//// Start at bottom right corner of score matrix
//while (i > 0 || j > 0) {
//    if (i > 0 && j > 0 && score_matrix[i][j] == score_matrix[i - 1][j - 1] + match_mismatch_score(seq1[i - 1], seq2[j - 1])) {
//        // Move diagonally
//        aligned_seq1 = seq1[i - 1] + aligned_seq1;
//        aligned_seq2 = seq2[j - 1] + aligned_seq2;
//        i--;
//        j--;
//    }
//    else if (i > 0 && score_matrix[i][j] == score_matrix[i - 1][j] + gap_penalty) {
//        // Move up
//        aligned_seq1 = seq1[i - 1] + aligned_seq1;
//        aligned_seq2 = "-" + aligned_seq2;
//        i--;
//    }
//    else {
//        // Move left
//        aligned_seq1 = "-" + aligned_seq1;
//        aligned_seq2 = seq2[j - 1] + aligned_seq2;
//        j--;
//    }
//}
//
//// Print aligned sequences
//cout << "Aligned sequence 1: " << aligned_seq1 << endl;
//cout << "Aligned sequence 2: " << aligned_seq2 << endl;
