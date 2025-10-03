#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i += 2) {
        for (int j = i - 1; j < n - i; ++j) {
            arr[i][j] = 1;
        }
        for (int j = i + 1; j < n - i; ++j) {
            arr[j][n - i - 1] = 1;
        }
        for (int j = i; j < n - i - 1; ++j) {
            arr[n - i - 1][j] = 1;
        }
        for (int j = i + 2; j < n - i; ++j) {
            arr[j][i] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << arr[i][j];
        }
        std::cout << '\n';
    }
}