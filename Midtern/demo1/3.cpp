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
std::pair<std::vector<int>, long long>
column_maxima_and_negative_product(const std::vector<std::vector<int>>& mat) {
    std::vector<int> max;
    long long product = 1;
    for (int i = 0; i < mat[0].size(); i++) {
        int col_max = mat[0][i];
        for (int j = 0; j < mat.size(); j++) {
            if (mat[j][i] > col_max) {
                col_max = mat[j][i];
            }
        }
        max.push_back(col_max);
    }
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] < 0) {
                product *= mat[i][j];
            }
        }
    }
    return {max, product};
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix = generate_matrix(n, m);
    auto result = column_maxima_and_negative_product(matrix);
    for (int i = 0; i < result.first.size(); i++) {
        std::cout << result.first[i] << " ";
    }
    std::cout << '\n' << result.second << '\n';
    return 0;
}