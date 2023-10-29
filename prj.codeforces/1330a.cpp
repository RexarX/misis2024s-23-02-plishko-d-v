#include <iostream>
#include <vector>
 
int main()
{
	int x, n, t, element;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n >> x;
		std::vector<bool> check(201);
		for (int j = 0; j < n; ++j) {
			std::cin >> element;
			check[--element] = true;
		}
		int k(0), cnt(0);
		while (cnt < x || check[k]) {
			cnt += !check[k];
			++k;
		}
		std::cout << k << '\n';
	}
	return 0;
}
