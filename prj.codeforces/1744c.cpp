#include <iostream>
#include <string>
#include <algorithm>

int alg(std::string& s, const int& n, const int& c) noexcept {
  int result(0);
  return result;
}

int main() {
  int t, n, c;
  std::string s;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> n >> c;
    std::cin >> s;
    std::cout << alg(s, n, c) << '\n';
  }
  return 0;
}