#include <iostream>
#include <concepts>

template <typename T>
requires(std::integral<T> || std::floating_point<T>)
double calculateAverage(T* a, int n) {
    double res = 0;
    for (int i = 0; i < n ; i++) {
        res += static_cast<double>(a[i]);
    }
    return (res / n);
}

int main() {
    int a[] = {10,2,7,4,5};
    std::cout << calculateAverage(a, 5);
    return 0;
}