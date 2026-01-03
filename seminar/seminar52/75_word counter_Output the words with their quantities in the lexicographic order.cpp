#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::map<std::string, int> freq;
    for (int i = 0; i < N; ++i) {
        std::string word;
        std::cin >> word;
        freq[word]++;
    }

    for (const auto& p : freq) {
        std::cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
