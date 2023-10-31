#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
	long long int n, m, a, previous(1), result(0);
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		std::cin >> a;
		result += (n + a - previous) % n;
		previous = a;
	}
	std::cout << result;
	return 0;
}
