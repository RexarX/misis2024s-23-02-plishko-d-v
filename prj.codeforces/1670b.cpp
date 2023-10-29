#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
int alg(const std::string& s, const std::vector<char>& symbols, const int& n) noexcept {
	int res(0), last(0);
	for (int i = 0; i < n; ++i) {
		if (std::find(symbols.begin(), symbols.end(), s[i]) != symbols.end()) {
			res = std::max(res, i - last);
			last = i;
		}
	}
	return res;
}
 
int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t, n, k;
	std::string s;
	std::vector<char> symbols;
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
		std::cout << alg(s, symbols, n) << '\n';
	}
	return 0;
}
