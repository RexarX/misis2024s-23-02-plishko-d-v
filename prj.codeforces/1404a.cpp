#include <iostream>
#include <string>
#include <algorithm>

bool isBalanced(std::string& s, const int& n, const int& k) noexcept {
	for (int i = 0; i < n; ++i) {
		if (s[i % k] == '?') {
			s[i % k] = s[i];
		}

		if (s[i] != s[i % k] && s[i] != '?') {
			return false;
		}
	}
	if (std::count(s.begin(), s.end() - n + k, '0') <= k / 2 && std::count(s.begin(), s.end() - n + k, '1') <= k / 2) {
		return true;
	}
	else {
		return false;
	}
}

int main() 
{
	std::ios::sync_with_stdio(false);
	int t, n, k;
	std::string s;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n >> k;
		std::cin >> s;
		if (isBalanced(s, n, k)) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
	}
	return 0;
}
