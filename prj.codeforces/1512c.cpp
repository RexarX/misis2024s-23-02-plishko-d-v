#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& s) noexcept {
	std::string reversed = s;
	std::reverse(reversed.begin(), reversed.end());
	if (s == reversed) {
		return true;
	}
	return false;
}

int main() 
{
	std::ios::sync_with_stdio(false);
	int t, a, b, len;
	std::string s;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> a >> b;
		std::cin >> s;
		len = a + b;
		for (int j = 0; j < len; ++j) {
			if (s[j] == '?') {
				s[j] = s[len - j - 1];
			}
		}
		a -= std::count(s.begin(), s.end(), '0');
		b -= std::count(s.begin(), s.end(), '1');
		for (int j = 0; j <= len / 2; ++j) {
			if (s[j] == '?' && j != len - j - 1) {
				if (a > 1) {
					s[j] = s[len - j - 1] = '0';
					a -= 2;
				}
				else if (b > 1) {
					s[j] = s[len - j - 1] = '1';
					b -= 2;
				}
			}
			else if (s[j] == '?') {
				if (a) {
					s[j] = '0';
					--a;
				}
				else {
					s[j] = '1';
					--b;
				}
			}
		}
		if (isPalindrome(s) && a == 0 && b == 0) {
			std::cout << s << '\n';
		}
		else {
			std::cout << "-1" << '\n';
		}
	}
	return 0;
}
