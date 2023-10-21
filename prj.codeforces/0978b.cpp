#include <iostream>
#include <string>


int main()
{
	int n, cnt(0);
	std::string word;
	std::cin >> n;
	std::cin >> word;
	for (int i = 0; i < n - 2; i++) {
		if (word.substr(i, 3) == "xxx") {
			cnt++;
		}
	}
	std::cout << cnt;
	return 0;
}
