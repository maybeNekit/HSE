#include <iostream>
#include <vector>
#include <iterator>

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
template<class InputIt, class OutputItTrue, class OutputItFalse, class Pred>
std::pair<OutputItTrue, OutputItFalse>
partition_copy_range(InputIt first, InputIt last,
    OutputItTrue out_true, OutputItFalse out_false, Pred p) {
    while (first != last) {
        if (p(*first)) {
            *out_true = *first;
            ++out_true;
        } else {
            *out_false = *first;
            ++out_false;
        }
        ++first;
    }
    return {out_true, out_false};
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix = generate_matrix(n, m);
    std::vector<int> nonnegatives;
    std::vector<int> negatives;
    for (int i = 0; i < matrix.size(); ++i) {
        partition_copy_range(matrix[i].begin(), matrix[i].end(),
            std::back_inserter(nonnegatives),
            std::back_inserter(negatives),
            [](int x) { return x >= 0; });
    }
    for (int i = 0; i < nonnegatives.size(); ++i) {
        std::cout << nonnegatives[i] << " ";
    }
    std::cout << '\n';
    for (int i = 0; i < negatives.size(); ++i) {
        std::cout << negatives[i] << " ";
    }
    std::cout << '\n';
    return 0;
}