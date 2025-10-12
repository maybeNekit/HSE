#include <iostream>
#include <concepts>

template <typename T>
requires(std::integral<T> || std::floating_point<T>)
void swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 6, b = 7;
    swap(&a, &b);
    std::cout << a << " " << b << std::endl;

    double x = 3.14, y = 2.71;
    swap(&x, &y);
    std::cout << x << " " << y << std::endl;

    return 0;
}