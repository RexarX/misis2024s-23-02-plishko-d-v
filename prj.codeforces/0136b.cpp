#include <iostream>
#include <cmath>

int tor(int& a, int& c) noexcept {
	int result(0), i(0);
	while (a || c) {
		result += (c % 3 - a % 3 + 3) % 3 * std::pow(3, i);
		a /= 3;
		c /= 3;
		i++;
	}
	return result;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int a, c;
	std::cin >> a >> c;
	std::cout << tor(a, c);
	return 0;
}
