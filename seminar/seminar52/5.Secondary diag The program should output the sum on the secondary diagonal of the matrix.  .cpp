#include <iostream>

int** read_matrix(int n) {
    int** m = new int*[n];
    for (int i = 0; i < n; i++) {
        m[i] = new int[n];
        for (int j = 0; j < n; j++) {
            std::cin >> m[i][j];
        }
    }
    return m;
}

int find_sum(int** matrix, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += matrix[i][n - 1 - i];
    }
    return s;
}

int main() {
    int n;
    std::cin >> n;
    int** m = read_matrix(n);
    std::cout << find_sum(m, n);
    return 0;
}