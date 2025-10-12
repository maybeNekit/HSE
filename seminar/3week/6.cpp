#include <iostream>
#include <concepts>

template <typename T>
requires(std::integral<T> || std::floating_point<T>)
int add(T* a, int n) {
    int res = 0;
    for (int i = 0; i < n ; i++) {
        res+= a[i];

    }
    return res;
}

int main() {
    int a[] = {10,2,7,4,5};
    std::cout << add(a, 5);
    return 0;
}