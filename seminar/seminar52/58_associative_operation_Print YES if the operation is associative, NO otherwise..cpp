#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> op(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> op[i][j];
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            for (int z = 0; z < n; ++z) {
                if (op[op[x][y]][z] != op[x][op[y][z]]) {
                    std::cout << "NO" << '\n';
                    return 0;
                }
            }
        }
    }

    std::cout << "YES" << '\n';
    return 0;
}
