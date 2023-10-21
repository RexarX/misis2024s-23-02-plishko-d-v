#include <iostream>

int main()
{
	int year, ones, tens, hds, tds;
	bool flag = true;
	std::cin >> year;
	while (flag) {
		year++;
		ones = year % 10;
		tens = year / 10 % 10;
		hds = year / 100 % 10;
		tds = year / 1000;
		if (ones != tens && ones != hds && ones != tds && tens != hds && tens != tds && hds != tds) {
			flag = false;
		}
	}
	std::cout << year;
	return 0;
}
