#include <iostream>
#include <vector>

std::function<bool(int)> &pre(std::vector<std::vector<int>> &mat) {
    return mat[];
}

size_t count_if(const std::vector<std::vector<int>>& M, std::function<bool(int)>& pred) {
    int k = 0;
    for (const auto & i : M) {
        for (const int j : i) {
            if (pred(j)) {
                k+=1;
            }
        }
    }
    return k;
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
    std::cout <<count_if(mat, pre(mat));;
    return 0;
}