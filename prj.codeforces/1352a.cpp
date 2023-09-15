#include <iostream>
#include <string>
#include <vector>


bool isRound(int number) {
	std::string str = std::to_string(number);
	if (1 <= number && number <= 9 || str.substr(1) == std::string(str.length(), '0')) {
		return true;
	}
	else {
		return false;
	}
}

std::vector<int> decompose(int num) {
	std::vector<int> result;
	int calc;
	int len = std::to_string(num).length();
	for (int i = 1; i < std::pow(10, len); i *= 10) {
		calc = num / (10 * i / 10) % 10;
		if (calc != 0) {
			result.push_back(calc * i);
		}
	}

	return result;
}

int main()
{
	int t, input;
	std::vector<int> array, current;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> input;
		array.push_back(input);
	}

	for (int i = 0; i < array.size(); i++) {
		if (isRound(array[i])) {
			std::cout << 1 << std::endl;
			std::cout << array[i] << std::endl;
		}
		else {
			current = decompose(array[i]);
			std::cout << current.size() << std::endl;
			for (int j = 0; j < current.size(); j++) {
				std::cout << current[j] << ' ';
			}

			std::cout << std::endl;
		}
	}

	return 0;
}
