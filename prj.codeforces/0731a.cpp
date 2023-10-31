#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
	std::string name;
	char current = 'a';
	int rotation(0);
	std::cin >> name;
	for (int i = 0; i < name.length(); ++i) {
		rotation += std::min(std::abs(current - name[i]), 26 - std::abs(name[i] - current));
		current = name[i];
	}
	std::cout << rotation;
	return 0;
}
