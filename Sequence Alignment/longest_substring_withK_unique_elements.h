#pragma once
#include <string>
#include <unordered_map>
/* Given an integer k and a strings s, find the length of the longest substring that contains at most k distinct characters
	- Biological applications include locating repeating sequences of nucleotides that consist of k number of unique nucleotides such as TATA box
*/

std::string get_substring_k(std::string s, int k) {
	std::string max_substring = "";
	int max_length = 0;
	std::unordered_map<char, int> freq;

	int i = 0;
	for (int j = 0; j < s.size(); j++) {
		freq[s[j]]++;

		// adjust window if number of distinct characters exceeds k
		while (freq.size() > k) {
			freq[s[i]]--;
			if (freq[s[i]] == 0) {
				freq.erase(s[i]);
			}
			i++;
		}

		// update max substring if necessary 
		if (j - i + 1 > max_length) {
			max_substring = s.substr(i, j - i + 1);
			max_length = j - i + 1;
		}
	}

	return max_substring;
}