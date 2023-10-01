#include <iostream>
#include <string>
 
 
bool contains(const std::string& str, char& targetChar) {
	return str.find(targetChar) != std::string::npos;
}
 
int alg(std::string& s, const std::string& symbols, int len, int cnt) {
	int i(0);
	while (i != s.length() - 1) {
		if (contains(symbols, s[i + 1])) {
			s.erase(i, 1);
		}
		else {
			i++;
		}
	}
 
	if (s.length() == len) {
		return cnt;
	}
	else {
		cnt++;
		return alg(s, symbols, s.length(), cnt);
	}
}
 
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t, n, k;
	std::string s, symbols;
	char symbol;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		symbols.clear();
		std::cin >> n;
		std::cin >> s;
		std::cin >> k;
		for (int j = 0; j < k; j++) {
			std::cin >> symbol;
			symbols += symbol;
		}
 
		std::cout << alg(s, symbols, n, 0) << '\n';
	}
 
	return 0;
}
