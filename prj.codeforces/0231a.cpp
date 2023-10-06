#include <iostream>


int main() {
	int n, a, b, c, cnt(0);
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a >> b >> c;
		if (a + b + c > 1) {
			cnt++;
		}
	}

	std::cout << cnt;
	return 0;
}
