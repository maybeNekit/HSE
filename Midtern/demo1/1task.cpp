#include <iostream>
#include <vector>
#include <cstdlib>

void replace_negatives_with_squares(std::vector<std::vector<int>>& m) {
    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m[i].size(); ++j) {
            if (m[i][j] < 0)
                m[i][j] = m[i][j] * m[i][j];
        }
    }
}

std::vector<std::vector<int>> gerate_matrix(int n, int m) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            matrix[i][j] = std::rand() % 101 - 50;
        }
    }
    return matrix;
}

void print(const std::vector<std::vector<int>>& m) {
    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m[i].size(); ++j) {
            std::cout << m[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

std::pair<long long, std::vector<int>> sum_evens_and_collect_odds(const std::vector<std::vector<int>> &m) {
    int sum_evens = 0;
    std::vector<int> odds;
    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m[i].size(); ++j) {
            if (m[i][j] % 2 == 0)
                sum_evens += m[i][j];
            else {
                odds.push_back(m[i][j]);
            }
        }
    }
    return {sum_evens, odds};
}

void print_vector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
}

template <class ForwardIt , class UnaryOp >
void transform_range(ForwardIt first, ForwardIt last, UnaryOp op) {
    for (auto it = first; it != last; ++it) {
        *it = op(*it);
    }
}
template<class InputIt, class OutputIt, class Pred>
OutputIt copy_if_range(InputIt first, InputIt last, OutputIt out, Pred p) {
    for (auto it = first; it != last; ++it) {
        if (p(*it)) {
            *out = *it;
            ++out;
        }
    }
    return out;
}


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix = gerate_matrix(n, m);
    std::cout << "Original matrix\n";
    print(matrix);
    replace_negatives_with_squares(matrix);
    std::cout << "Task 2. Replace negative\n";
    print(matrix);
    std::pair<long long, std::vector<int>> pair_sum_odd = sum_evens_and_collect_odds(matrix);
    std::cout << pair_sum_odd.first << '\n';
    std::cout << "Task 3. Sum of even\n";
    print_vector(pair_sum_odd.second);

    for (size_t i = 0; i < matrix.size(); ++i) {
        transform_range(matrix[i].begin(), matrix[i].end(), [](int x) {
            return x == 0 ? -1 : x;
        });
    }
    std::cout << "Task 4. Transform with -1\n";
    print(matrix);
    std::vector<int> odds;
    auto is_odd = [](int x) { return x % 2 != 0; };
    for (size_t i = 0; i < matrix.size(); ++i) {
        copy_if_range(matrix[i].begin(), matrix[i].end(), std::back_inserter(odds), is_odd);
    }
    std::cout << "Task 5. Copy odd\n";
    print_vector(odds);
    return 0;
}
