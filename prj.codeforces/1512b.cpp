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

    if (std::count(v[i].begin(), v[i].end(), '*') == 1) {
      reverse(v[i].begin(), v[i].end());
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
    for (int j = 0; i < n; j++) {
      std::cin >> row;
      v.push_back(row);
    }

    for (int j = 0; i < n; j++) {
      std::cout << v[i] << '\n';
    }
    
    v.clear();
  }

  return 0;
}