#include <iostream>

int main()
{
	int t, n, m, sx, sy, d;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n >> m >> sx >> sy >> d;
		if (((sx + d >= n) && (sx - d <= 1)) || ((sy + d >= m) && (sy - d <= 1)) || 
		((sx - d <= 1) && (sy - d <= 1)) || ((sx + d >= n) && (sy + d >= m))) {
				std::cout << "-1" << '\n';
		}
		else {
				std::cout << (n - 1) + (m - 1) << '\n';
		}
	}
	return 0;
}
