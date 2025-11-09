#include <iostream>
#include <vector>
std::vector<std::vector<int>> add_matrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    std::vector<std::vector<int>> v(A.size(), std::vector<std::vector<int> >::value_type(A[0].size()));
    for (int i =0; i < int(A.size()); ++i) {
        for (int j =0; j < int(A[i].size()); ++j) {
            v[i][j] = A[i][j] + B[i][j];
        }
    }
    return v;
}
std::vector<std::vector<int>> sub_matrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    std::vector<std::vector<int>> v(A.size(), std::vector<std::vector<int> >::value_type(A[0].size()));
    for (int i =0; i < int(A.size()); ++i) {
        for (int j =0; j < int(A[i].size()); ++j) {
            v[i][j] = A[i][j] - B[i][j];
        }
    }
    return v;
}

void print(const std::vector<std::vector<int>> &mat) {
    for (const auto & i : mat) {
        for (const int j : i) {
            std::cout << j << " ";
        }
        std::cout << '\n';
    }
}

int main() {
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> mat(n, std::vector<int>(m));
    std::vector<std::vector<int>> mat2(n, std::vector<int>(m));
    for (auto & i : mat) {
        for (int & j : i) {
            int a;
            std::cin >> a;
            j = a;
        }
    }
    for (auto & i : mat2) {
        for (int & j : i) {
            int a;
            std::cin >> a;
            j = a;
        }
    }
    const std::vector<std::vector<int>> v1=add_matrices(mat, mat2);
    const std::vector<std::vector<int>> v2 = sub_matrices(mat, mat2);
    print(v1);
    print(v2);

    return 0;
}