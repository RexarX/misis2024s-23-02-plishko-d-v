#include <iostream>
#include <array>


int main()
{
	std::array<std::array<int, 5>, 5> mas;
	int row, col;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> mas[i][j];
			if (mas[i][j] == 1) {
				row = i;
				col = j;
			}
		}
	}

	std::cout << std::abs(row - 2) + std::abs(col - 2);
	return 0;
}
