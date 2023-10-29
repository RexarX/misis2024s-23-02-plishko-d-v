#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void alg(std::vector<std::string>& v, const int& n) noexcept {
  std::pair<int, int> pos1, pos2;
  pos1 = std::make_pair(-1, -1);
  pos2 = std::make_pair(-1, -1);
  for (int i = 0; i < n; ++i) {
    if (std::count(v[i].begin(), v[i].end(), '*') == 2) {
      if (i == n - 1) {
        v[0] = v[i];
        return;
      }
      else {
        v[n - 1] = v[i];
        return;
      }
    }
    int pos = v[i].find('*');
    if (pos != std::string::npos) {
      if (pos1.first == -1 && pos1.second == -1) {
        pos1.first = i;
        pos1.second = pos;
      }
      else {
        pos2.first = i;
        pos2.second = pos;
        break;
      }
    }
  }
  if (pos1.second == pos2.second) {
    if (pos1.second == (n - 1) / 2 && n > 2) {
      v[pos1.first][0] = '*';
      v[pos2.first][0] = '*';
    }
    else {
      v[pos1.first][std::abs(n - 1 - pos2.second)] = '*';
      v[pos2.first][std::abs(n - 1 - pos1.second)] = '*';
    }
  }
  else {
    v[pos1.first][pos2.second] = '*';
    v[pos2.first][pos1.second] = '*';
  }
}

int main()
{
  int t, n;
  std::string row;
  std::vector<std::string> v;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::cin >> n;
    for (int j = 0; j < n; ++j) {
      std::cin >> row;
      v.push_back(row);
    }
    alg(v, n);
    for (int j = 0; j < n; ++j) {
      std::cout << v[j] << '\n';
    }
    v.clear();
  }
  return 0;
}
