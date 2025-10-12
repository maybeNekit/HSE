#include <iostream>
#include <concepts>
#include <functional>

template <typename T, typename Compare = std::less<T>>
requires(std::integral<T> || std::floating_point<T>)
void bubbleSort(T* a, int n, Compare comp = Compare()) {
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - 1 - j; i++) {
            if (comp(a[i + 1], a[i])) {
                std::swap(a[i], a[i + 1]);
            }
        }
    }
}

int main() {
    int a[] = {10, 2, 7, 4, 5};
    bubbleSort(a, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << a[i] << '\n';
    }
    return 0;
}
