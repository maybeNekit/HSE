#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int a = 0, b = 1;
    int* p1 = &a;
    int* p2 = &b;

    for (int i = 0; i < n; ++i) {
        std::cout << *p1 << " ";
        int n = *p1 + *p2;
        *p1 = *p2;
        *p2 = n;
    }
    return 0;
}