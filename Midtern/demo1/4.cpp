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
template<class ForwardIt, class Pred, class UnaryOp>
void apply_if_range(ForwardIt first, ForwardIt last, Pred p, UnaryOp op) {
    while (first != last) {
        if (p(*first)) {
            *first = op(*first);
        }
        ++first;
    }
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix = generate_matrix(n, m);
    for (int i = 0; i < matrix.size(); ++i) {
        apply_if_range(matrix[i].begin(), matrix[i].end(),
            [](int x) { return x % 3 == 0; },
            [](int x) { return x + 5; });
    }
    print_matrix(matrix);
    return 0;
}