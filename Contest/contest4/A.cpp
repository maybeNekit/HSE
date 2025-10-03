#include <iostream>

int main() {
    int x;
    int *px = &x;
    std::cin >> x;
    std::cout << *px;
    return 0;
}