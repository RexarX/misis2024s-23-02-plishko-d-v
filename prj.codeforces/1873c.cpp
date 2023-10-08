#include <iostream>
#include <string>
#include <algorithm>


int main()
{
        int t;
        char element;
        std::cin >> t;
        for (int i = 0; i < t; i++) {
                int cnt(0);
                for (int x = 1; x <= 10; x++) {
                        for (int y = 1; y <= 10; y++) {
                                std::cin >> element;
                                if (element == 'X') {
                                        cnt += std::min(std::min(x, 10 - x + 1), std::min(y, 10 - y + 1));
                                }
                        }
                }

                std::cout << cnt << '\n';
        }

        return 0;
}
