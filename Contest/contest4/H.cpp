#include <iostream>

int main() {
    int n, m, k = 0;
    std::cin >> n >> m;
    int arr[n][m];

    for (int s = 0; s <= n + m - 2; ++s) {
        int a = s - (m - 1);
        if (a < 0) {
            a = 0;
        }
        int b = s;
        if (b > n - 1) {
            b = n - 1;
        }
        for (int i = a; i <= b; ++i) {
            int j = s - i;
            arr[i][j] = k++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j]<<" ";
        }
        std::cout << '\n';
    }
    return 0;

}