#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string name;
	char current = 'a';
	int rotation(0);
	std::cin >> name;
	for (int i = 0; i < name.length(); i++) {
		rotation += std::min(std::abs(current - name.at(i)), 26 - std::abs(name.at(i) - current));
		current = name.at(i);
	}
	std::cout << rotation;
	return 0;
}
