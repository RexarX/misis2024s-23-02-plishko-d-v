#include <iostream>

int main()
{
	int t, n, k, cnt, mx;
	char element;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n >> k;
		cnt = 0;
		mx = -1;
		for (int j = 0; j < n; ++j) {
			std::cin >> element;
			if (element == 'B' && j > mx) {
				mx = j + k - 1;
				++cnt;
			}
		}
		std::cout << cnt << '\n';
	}
	return 0;
}
