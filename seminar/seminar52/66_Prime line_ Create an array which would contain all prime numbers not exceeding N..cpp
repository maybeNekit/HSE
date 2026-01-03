#include <iostream>
#include <vector>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    for (int prime : primes) {
        std::cout << prime << ' ';
    }
    std::cout << '\n';

    return 0;
}
