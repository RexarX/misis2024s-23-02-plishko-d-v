#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
	int w;
	std::cin >> w;
	if (w > 3 && w % 2 == 0) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	return 0;
}
