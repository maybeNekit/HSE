#include <climits>
#include <iostream>
#include <string>
#include <vector>

struct Word {
    std::string text;
    std::vector<int> vec;
};

long long f(const std::vector<int>& a, const std::vector<int>& b) {
    long long res = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        res += static_cast<long long>(a[i]) * b[i];
    }
    return res;
}

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<Word> words(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> words[i].text;
        words[i].vec.resize(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> words[i].vec[j];
        }
    }
    std::vector<long long> scores(m);
    long long ma = LLONG_MIN;
    for (int i = 1; i < m; ++i) {
        scores[i] = f(words[0].vec, words[i].vec);
        if (scores[i] > ma) {
            ma = scores[i];
        }
    }
    for (int i = 1; i < m; ++i) {
        if (scores[i] == ma) {
            std::cout << words[i].text << "\n";
        }
    }
    return 0;
}