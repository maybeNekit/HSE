#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n > 0 && (n & (n - 1)) == 0) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
