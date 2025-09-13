#include <iostream>

int main() {
    int a;
    std::cin >> a;
    if (a>99) {
        std::cout << (a/10%10);
    } else {
        std::cout << (a/10);
    }
    return 0;
}