#include <iostream>
#include <vector>

void print(const std::vector<std::vector<int>> &mat) {
    for (const auto & i : mat) {
        for (int j : i) {
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
    print(mat);
    print(mat2);
    return 0;
}