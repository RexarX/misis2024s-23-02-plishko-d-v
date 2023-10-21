#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void alg(std::vector<std::string>& v, const int& n) {
  struct Position {
    int x;
    int y;
  };
  Position pos1, pos2;
  pos1.x = NULL;
  pos1.y = NULL;
  pos2.x = NULL;
  pos2.y = NULL;
  for (int i = 0; i < n; i++) {
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
      if (pos1.x == NULL && pos1.y == NULL) {
        pos1.x = i;
        pos1.y = pos;
      }
      else {
        pos2.x = i;
        pos2.y = pos;
        break;
      }
    }
  }
  if (pos1.y == pos2.y) {
    if (pos1.y == (n - 1) / 2 && n > 2) {
      v[pos1.x][0] = '*';
      v[pos2.x][0] = '*';
    }
    else {
      v[pos1.x][std::abs(n - 1 - pos2.y)] = '*';
      v[pos2.x][std::abs(n - 1 - pos1.y)] = '*';
    }
  }
  else {
    v[pos1.x][pos2.y] = '*';
    v[pos2.x][pos1.y] = '*';
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
