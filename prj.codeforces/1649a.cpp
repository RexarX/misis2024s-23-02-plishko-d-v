#include <iostream>
#include <array>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	int t, n, right, left;
	std::array<bool, 100> mas{};
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n;
		right = n;
		left = 1;
		for (int j = 1; j <= n; ++j) {
			std::cin >> mas[j];
		}
		while (mas[left]) {
			++left;
		}
		while (mas[right]) {
			--right;
		}
		std::cout << std::max(right - left + 2, 0) << '\n';
	}
	return 0;
}
