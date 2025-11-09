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
void cube_positives(std::vector<std::vector<int>>& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] > 0) {
                mat[i][j] = mat[i][j] * mat[i][j] * mat[i][j];
            }
        }
    }
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix = generate_matrix(n, m);
    cube_positives(matrix);
    print_matrix(matrix);
    return 0;
}