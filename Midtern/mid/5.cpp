#include <iostream>
#include <vector>
template <typename T>
std::vector<std::vector<T>> transpose(const std::vector<std::vector<T>>& M) {
    std::vector<std::vector<int>> v(M[0].size(), std::vector<std::vector<int> >::value_type(M.size()));
    for (int j =0; j < int(M[0].size()); j++) {
        for (int i =0; i < int(M.size()); i++) {
            v[j][i] = M[i][j];
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
    for (auto & i : mat) {
        for (int & j : i) {
            int a;
            std::cin >> a;
            j = a;
        }
    }
    std::vector<std::vector<int>> mat2=transpose(mat);
    print(mat2);
    return 0;
}