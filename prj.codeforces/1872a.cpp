#include <iostream>
#include <algorithm>

 
int main()
{
	int t, a, b, c;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> a >> b >> c;
		std::cout << (std::max(a, b) - (a + b) / 2 + c - 1) / c << std::endl;
	}
 
	return 0;
}
