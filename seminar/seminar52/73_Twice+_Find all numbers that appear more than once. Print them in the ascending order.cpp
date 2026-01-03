#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> numbers(N);
    std::map<int, int> freq;

    for (int i = 0; i < N; ++i) {
        std::cin >> numbers[i];
        freq[numbers[i]]++;
    }

    std::vector<int> result;
    for (const auto& p : freq) {
        if (p.second > 1) {
            result.push_back(p.first);
        }
    }

    std::sort(result.begin(), result.end());

    for (int num : result) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    return 0;
}
