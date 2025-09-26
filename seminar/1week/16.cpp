#include <iostream>

int main() {
    int a;
    std::cin >> a;
    std::cout << a + 1 + (a % 2);
    return 0;
}