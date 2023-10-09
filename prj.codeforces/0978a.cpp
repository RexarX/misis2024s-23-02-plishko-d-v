#include <iostream>
#include <vector>
#include <algorithm>


void duplicates(std::vector<int>& mas, const int& element) {
	auto it = std::find(mas.begin(), mas.end(), element);
	if (it != mas.end())
	{
		mas.erase(mas.begin() + (it - mas.begin()));
	}
}

int main()
{
	int n, element;
	std::cin >> n;
	std::vector<int> mas;
	for (int i = 0; i < n; i++) {
		std::cin >> element;
		duplicates(mas, element);
		mas.push_back(element);
	}

	std::cout << mas.size() << '\n';
	for (int i = 0; i < mas.size(); i++) {
		std::cout << mas[i] << ' ';
	}

	return 0;
}
