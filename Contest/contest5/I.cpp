#include <iostream>

void f(int* b, int* c) {
    for (int* i = b; i < c; ++i) {
        int* min = i;
        for (int* j = i + 1; j < c; ++j) {
            if (*j < *min) {
                min = j;
            }
        }
        int t = *i;
        *i = *min;
        *min = t;
    }
}

int main() {
    int n;
    std::cin >> n;
    int a[1000];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    f(a, a + n);
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
    return 0;
}