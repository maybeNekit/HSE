#include <iostream>
#include <concepts>

template <typename T>
requires(std::integral<T> || std::floating_point<T>)
int filterArray(T* a, int n, T* res, bool (*predicate)(T)) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (predicate(a[i])) {
            res[k++] = a[i];
        }
    }
    return k;
}

bool f(int x) {
    return x > 5;
}

int main() {
    int a[] = {10, 2, 7, 4, 5};
    int r[5];
    int res = filterArray(a, 5, r, f);
    for (int i = 0; i < res; i++) {
        std::cout << r[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}