#include <iostream>
#include <string>
#include <vector>


std::string alg(std::string word) {
	int len = word.length();
	if (len > 10) {
		return word[0] + std::to_string(len - 2) + word[len - 1];
	}

	return word;
}

int main()
{
	int n;
	std::string word;
	std::vector<std::string> words;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> word;
		words.push_back(alg(word));
		std::cout << words[i] << std::endl;
	}

	return 0;
}
