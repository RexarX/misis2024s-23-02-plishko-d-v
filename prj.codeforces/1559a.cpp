#include <iostream>
#include <vector>

int alg(const std::vector<int>& mas, const int& n){
  int res = mas[0];
  for (int i = 1; i < n; i++) {
    res &= mas[i];
  }
  return res;
}

int main()
{
  int t, n, element;
  std::vector<int> mas;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    mas.clear();
    std::cin >> n;
    for (int j = 0; j < n; j++) {
      std::cin >> element;
      mas.push_back(element);
    }
    std::cout << alg(mas, n) << '\n';
  }
  return 0;
}
