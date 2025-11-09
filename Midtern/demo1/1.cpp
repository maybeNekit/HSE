#include <iostream>
#include <vector>
std::vector<std::vector<int>> generate_matrix(int n, int m) {
    std::vector<std::vector<int>> v(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            std::cin >> a;
            v[i][j] = a;
        }
    }
    return v;
}
void print_matrix(const std::vector<std::vector<int>>& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << '\n';
    }
}
std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& mat) {
    std::vector<std::vector<int>> v(mat[0].size(), std::vector<int>(mat.size()));
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            v[j][i] = mat[i][j];
        }
    }
    return v;
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix = generate_matrix(n, m);
    print_matrix(matrix);
    std::vector<std::vector<int>> transposed = transpose(matrix);
    print_matrix(transposed);
    return 0;
}
