#include <iostream>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    swap(&a, &b);
    std::cout << a << " " << b << '\n';
    return 0;
}