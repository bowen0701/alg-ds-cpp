#include <iostream>
#include <vector>

bool PalindromeRecur(std::string& s) {
	// Palindrome: the string is read the same forwards & backwards.
	if (s.length() <= 1) {
		return true;
	}
	std::string s_sub = s.substr(1, s.length() - 2);
	return s[0] == s[s.length() - 1] && PalindromeRecur(s_sub);
}

int main() {
	// Output: true.
	std::string s1 = "radar";
	std::cout << std::boolalpha << PalindromeRecur(s1) << std::endl;

	// Output: false.
	std::string s2 = "bowen";
	std::cout << std::boolalpha << PalindromeRecur(s2) << std::endl;

	// Output: true.
	std::string s3 = "madam";
	std::cout << std::boolalpha << PalindromeRecur(s3) << std::endl;

	return 0;
}