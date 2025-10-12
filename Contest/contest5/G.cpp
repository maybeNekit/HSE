#include <iostream>

void swap(int arr[][100], int x, int y, int i, int j) {
    for (int r = 0; r < x; ++r) {
        int t = arr[r][i];
        arr[r][i] = arr[r][j];
        arr[r][j] = t;
    }
}

int main() {
    int x, y;
    std::cin >> x >> y;
    int arr[100][100];
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            std::cin >> arr[i][j];
    int i, j;
    std::cin >> i >> j;
    swap(arr, x, y, i, j);
    for (int r = 0; r < x; ++r) {
        for (int c = 0; c < y; ++c)
            std::cout << arr[r][c] << (c == y - 1 ? '\n' : ' ');
    }
    return 0;
}