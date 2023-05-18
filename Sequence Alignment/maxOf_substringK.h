#pragma once
#include <string>
#include <unordered_map>

/* Given an integer k and a strings s, find max value of each substring of length k (1 <= k <= length of string), function returns an unordered map of substring: max char pairs 
*/

std::unordered_map<std::string, char> maxOf_substring(std::string s, int k) {
	std::unordered_map<std::string, char> max_map;
	if (k < 1 || k > s.size() || s.size() == 0) {
		std::cout << "Error k out of range" << std::endl;
		max_map.clear();
		return max_map;
	}

	std::string substring = "";
	char max_char = s[0];
	int window = 0;

	for (int j = 0; j < s.size();j++) {
		std::cout << "\nChecking: " << j << ": " << s[j] << std::endl;
		if (s[j] > max_char) {
			max_char = s[j];
		}
		if ((j - window + 1) % k == 0) {
			std::cout << j << " - " << window << " + 1 " << " divided by " << k << " remainder = 0" << std::endl;
			substring = s.substr(window, k);
			max_map[substring] = max_char;
			std::cout << substring << ": " << max_char << std::endl;
			window++;
		}
	}
	return max_map;
}