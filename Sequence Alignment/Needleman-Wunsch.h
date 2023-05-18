#pragma once
// This program uses Needleman-Wunsch algorithm to align two sequences of nucleotides 
#include <vector>
#include <string>

/*	Get two strings

	Construct grid
		Across: (0, 0, Sequence) x Down: (0, 0, Sequence )

	Choose scoring system
		Match = +1
		Mismatch or Insertion/deletion = -1

	Fill in table
		grid[1][1] = 0

	Trace arrows back to origin
*/

/* Biology applications
	Identifying unknown sequences, identifying conserved sequence patterns and motifs, constructing phylogenic trees, predicting proteins' secondary and tertiary structures, predicting gene locations and new members of gene families
*/

// Scoring system 
const int MATCH_SCORE = 1;
const int MISMATCH_SCORE = -1;
//int gap_score = -2;

std::string seq_alignment(std::string seq1, std::string seq2) {
	int rows = seq1.length() + 1;
	int cols = seq2.length() + 1;

	// Initialize score matrix 
	std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

	// Fill in first row and first column of score matrix 
	for (int i = 0; i < rows; i++) {
		matrix[i][0] = i * -1;
		matrix[0][i] = i * -1;
	}

	// Fill in rest of matrix, track path 
	for (int i = 1; i < rows; i++) {
		for (int j = 1; j < cols; j++) {
			// Check for a match 
			int match_mismatch_score = seq1[i - 1] == seq2[j - 1] ? MATCH_SCORE : MISMATCH_SCORE;

			// Check diagonal and add to path
			int diagonal_score = matrix[i - 1][j - 1] + match_mismatch_score;

			// Check up 
			int up_score = matrix[i - 1][j] + match_mismatch_score;

			// Check left 
			int left_score = matrix[i][j - 1] + match_mismatch_score;

			// Update matrix
			matrix[i][j] = std::max(diagonal_score, std::max(up_score, left_score));
		}
	}

	// Track back 
	int i = rows - 1;
	int j = cols - 1;
	std::string aligned_seq1 = "", aligned_seq2 = "";

	while (i > 0 || j > 0) {
		// Check for a match 
		int match_mismatch_score = seq1[i - 1] == seq2[j - 1] ? MATCH_SCORE : MISMATCH_SCORE;

		if (i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + match_mismatch_score) {
			// Move diagonally
			aligned_seq1 = seq1[i - 1] + aligned_seq1;
			aligned_seq2 = seq2[j - 1] + aligned_seq2;
			i--;
			j--;
		}
		else if (i > 0 && matrix[i][j] == matrix[i - 1][j] + match_mismatch_score) {
			// Move up
			aligned_seq1 = seq1[i - 1] + aligned_seq1;
			aligned_seq2 = "-" + aligned_seq2;
			i--;
		}
		else {
			// Move left
			aligned_seq1 = "-" + aligned_seq1;
			aligned_seq2 = seq2[j - 1] + aligned_seq2;
			j--;
		}
	}

	return aligned_seq1, aligned_seq2;
}
