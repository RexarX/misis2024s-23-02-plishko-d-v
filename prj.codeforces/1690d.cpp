#include <iostream>
#include <string>
#include <algorithm>

int alg(std::string& symbols, const int& n, const int& k) {
    int result, cnt(0);
    for (int i = 0; i < k; i++) {
        if (symbols[i] == 'W') {
            cnt++;
        }
    }
    result = cnt;
    for (int i = k; i < n; i++) {
        if (symbols[i] == 'W') {
            cnt++;
        }
        if (symbols[i - k] == 'W') {
            cnt--;
        }
        result = std::min(result, cnt);
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t, k, n;
    std::string symbols;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n >> k;
        std::cin >> symbols;
        std::cout << alg(symbols, n, k) << '\n';
    }
    return 0;
}