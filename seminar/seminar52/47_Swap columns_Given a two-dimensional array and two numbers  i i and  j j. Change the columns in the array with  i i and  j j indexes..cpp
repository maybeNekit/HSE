#include <iostream>
#include <vector>

int main() {
    int m, n;
    std::cin >> m >> n;

    std::vector<std::vector<int>> arr(m, std::vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> arr[i][j];
        }
    }

    int i, j;
    std::cin >> i >> j;

    for (int k = 0; k < m; ++k) {
        std::swap(arr[k][i], arr[k][j]);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
