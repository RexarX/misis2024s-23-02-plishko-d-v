#include <iostream>
#include <vector>
 
bool contains(const std::vector<char>& symbols, const char& targetChar) noexcept {
	return std::find(symbols.begin(), symbols.end(), targetChar) != symbols.end();
}

int alg(std::string& s, const std::vector<char>& symbols, const int& len, int cnt) noexcept {
	int i(0);
	while (i != s.length() - 1) {
		if (contains(symbols, s[i + 1])) {
			s.erase(i, 1);
		}
		else {
			++i;
		}
	}
	if (s.length() == len) {
		return cnt;
	}
	return alg(s, symbols, s.length(), ++cnt);
}
 
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t, n, k;
	std::string s;
	std::vector<char> symbols;
	symbols.reserve(26);
	char symbol;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		symbols.clear();
		std::cin >> n;
		std::cin >> s;
		std::cin >> k;
		for (int j = 0; j < k; ++j) {
			std::cin >> symbol;
			symbols.push_back(symbol);
		}
		std::cout << alg(s, symbols, n, 0) << '\n';
	}
	return 0;
}
