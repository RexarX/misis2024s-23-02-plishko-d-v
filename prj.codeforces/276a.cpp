#include <iostream>

int joy(int f, int t, int k) {
	if (t > k) {
		return f - t + k;
	}
	else {
		return f;
	}
}

int main()
{
	int n, k, f, t, max(0), cur;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> f >> t;
		cur = joy(f, t, k);
		if (i == 0) {
			max = cur;
		}
		else {
			if (cur > max) {
				max = cur;
			}
		}
	}

	std::cout << max;
	return 0;
}