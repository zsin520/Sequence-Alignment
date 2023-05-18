#include <iostream>
#include "longest_substring_withK_unique_elements.h"
#include "Needleman-Wunsch.h"
#include "maxOf_substringK.h"

int main() {
	// Testing get_substring_k
	std::cout << "Testing get_substring_k" << std::endl;
	std::string seq1, seq2;

	seq1 = "GATTACA";
	seq2 = "GCATGCG";

	int k = 2;

	std::string kmer = get_substring_k(seq1, k);

	std::cout << "The longest substring with " << k << " unique elements from the string:\n" << seq1 << "\n" << kmer << std::endl;

	// Testing maxOf_substring
	std::cout << "\nTesting maxOf_substring" << std::endl;
	std::unordered_map<std::string, char> max_map = maxOf_substring(seq1, 3);
	std::cout << "\n";
	for (auto i : max_map) {
		std::cout << i.first << ": " << i.second << std::endl;
	}

	return 0;
}