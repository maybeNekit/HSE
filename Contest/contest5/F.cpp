#include <iostream>

void tr(int arr[][1000], int n, int m, int res[][1000]) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res[j][i] = arr[i][j];
}
int main() {
    int n, m;
    std::cin >> n >> m;
    int arr[1000][1000];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> arr[i][j];
    int res[1000][1000];
    tr(arr, n, m, res);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << res[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}