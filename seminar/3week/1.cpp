#include <iostream>
#include <concepts>
#include <algorithm>

template<class T>
requires (std::integral<T> || std::floating_point<T>)

T FindMax(T*a, int n) {
    return *std::max_element(a, a + n);
}


int main() {
    int a[] = {1,2,3,4,5};
    std::cout << FindMax<>(a, 5);
}