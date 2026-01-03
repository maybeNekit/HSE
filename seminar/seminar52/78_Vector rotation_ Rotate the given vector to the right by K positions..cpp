#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i];
    }

    K = K % N;

    std::rotate(vec.rbegin(), vec.rbegin() + K, vec.rend());

    for (int i = 0; i < N; i++) {
        std::cout << vec[i];
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}