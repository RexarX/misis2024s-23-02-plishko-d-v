#include <iostream>

int joy(const int& f, const int& t, const int& k) {
	if (t > k) {
		return f - t + k;
	}
	return f;
}

int main()
{
	int n, k, f, t, mx(0), cur;
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> f >> t;
		cur = joy(f, t, k);
		if (i == 0) {
			mx = cur;
		}
		else {
			mx = std::max(cur, mx);
		}
	}
	std::cout << mx;
	return 0;
}
