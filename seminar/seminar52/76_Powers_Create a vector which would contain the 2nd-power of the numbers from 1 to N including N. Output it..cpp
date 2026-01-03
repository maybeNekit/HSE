#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> squares;
    for (int i = 1; i <= N; ++i) {
        squares.push_back(i * i);
    }

    for (int i = 0; i < N; ++i) {
        std::cout << squares[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
