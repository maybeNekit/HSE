#include <iostream>
#include <cmath>

int get_len(int n) {
    if (n == 0) return 1;
    n = std::abs(n);
    int l = 0;
    while (n > 0) {
        n /= 10;
        l++;
    }
    return l;
}

int cmp1(int a, int b) {
    return a > b;
}

int cmp2(int a, int b) {
    return a < b;
}

int cmp3(int a, int b) {
    return get_len(a) > get_len(b);
}

int cmp4(int a, int b) {
    return (std::abs(a) % 2) > (std::abs(b) % 2);
}

void stable_sort(int* arr, int n, int (*comparator)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (comparator(arr[j], arr[j + 1])) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int t;
    std::cin >> t;

    int (*fp)(int, int) = nullptr;
    if (t == 1) fp = cmp1;
    else if (t == 2) fp = cmp2;
    else if (t == 3) fp = cmp3;
    else fp = cmp4;

    stable_sort(a, n, fp);

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << '\n';

    return 0;
}