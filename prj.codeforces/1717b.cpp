#include <iostream>

int main()
{
	int t, n, k, r, c;
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k >> r >> c;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((i + j) % k == (r + c) % k) {
					std::cout << 'X';
				}
				else {
					std::cout << '.';
				}
			}
    std::cout << '\n';
		}
	}
	return 0;
}
