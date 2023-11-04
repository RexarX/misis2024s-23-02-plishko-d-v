#include <iostream>
#include <string>

std::string alg(const std::string& word) noexcept {
	const int len = word.length();
	if (len > 10) {
		return word[0] + std::to_string(len - 2) + word[len - 1];
	}
	return word;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	std::string word;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> word;
		std::cout << alg(word) << '\n';
	}
	return 0;
}
