#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void alg(std::vector<std::string>& v, const int& n) {
  for (int i = 0; i < n; i++) {
    if (std::count(v[i].begin(), v[i].end(), '*') == 2) {
      v[n - 1] = v[i];
      break;
    }
    int pos = v[i].find('*');
    if (pos != std::string::npos) {
      // v[i] = 
    }
  }
}

int main()
{
  int t, n;
  std::string row;
  std::vector<std::string> v;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    for (int j = 0; j < n; j++) {
      std::cin >> row;
      v.push_back(row);
    }
    alg(v, n);
    for (int j = 0; j < n; j++) {
      std::cout << v[j] << '\n';
    }
    v.clear();
  }
  return 0;
}
