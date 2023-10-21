#include <iostream>

int main() {
	const int n, a, b, c;
	int cnt(0);
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
