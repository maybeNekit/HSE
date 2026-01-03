#include <iostream>

void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    print(a, n);
    return 0;
}