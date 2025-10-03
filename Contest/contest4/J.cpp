#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    int w;
    std::cin >> w;

    int arr[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = 0;
        }
    }
    for (int k = 0; k < w; ++k) {
        int x,y;
        std::cin >> x >> y;
        --x;
        --y;
        arr[x][y] = -1;
        if (y - 1 >= 0 && arr[x][y - 1] != -1) arr[x][y - 1]++;
        if (y + 1 < m && arr[x][y + 1] != -1) arr[x][y + 1]++;
        if (x + 1 < n && arr[x + 1][y] != -1) arr[x + 1][y]++;
        if (x - 1 >= 0 && arr[x - 1][y] != -1) arr[x - 1][y]++;
        if (x - 1 >= 0 && y - 1 >= 0 && arr[x - 1][y - 1] != -1) arr[x - 1][y - 1]++;
        if (x - 1 >= 0 && y + 1 < m && arr[x - 1][y + 1] != -1) arr[x - 1][y + 1]++;
        if (x + 1 < n && y + 1 < m && arr[x + 1][y + 1] != -1) arr[x + 1][y + 1]++;
        if (x + 1 < n && y - 1 >= 0 && arr[x + 1][y - 1] != -1) arr[x + 1][y - 1]++;


    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == -1) {
                std::cout << "*" << " ";
            } else {
                std::cout << arr[i][j]<<" ";
            }
        }
        std::cout << '\n';
    }
    return 0;
}