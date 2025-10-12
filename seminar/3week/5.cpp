#include <iostream>
#include <concepts>

template <typename T>
requires(std::integral<T> || std::floating_point<T>)
int findElement(T* a, int n, int f) {
    int res = -1;
    for (int i = 0; i < n ; i++) {
        if (a[i] == f) {
            res = i;
        }
    }
    return res;
}

int findElement2(std::string* a, int n, const std::string& f) {
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == f) {
            res = i;
        }
    }
    return res;
}

int main() {
    int a[] = {10,2,7,4,5};
    int f;
    std::cin >> f;
    std::cout << findElement(a, 5, f) << '\n';
    std::string s[] = {"one", "two", "three", "four"};
    std::string fs;
    std::cin >> fs;
    std::cout << findElement2(s, 4, fs);
    return 0;
}