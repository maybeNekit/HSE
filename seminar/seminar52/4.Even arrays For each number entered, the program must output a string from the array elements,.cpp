#include <iostream>

int main() {
    int n;
    while (std::cin >> n && n != -1) {
        for (int i = 0; i <= n; i += 2) {
            std::cout << i << " ";
        }
        std::cout << '\n';
    }
    return 0;
}