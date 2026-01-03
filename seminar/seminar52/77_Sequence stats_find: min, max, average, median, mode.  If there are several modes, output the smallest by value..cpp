#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> numbers[i];
    }

    int min_val = *std::min_element(numbers.begin(), numbers.end());
    int max_val = *std::max_element(numbers.begin(), numbers.end());

    double sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += numbers[i];
    }

    double avg = sum / N;

    std::sort(numbers.begin(), numbers.end());
    double median;
    if (N % 2 == 1) {
        median = numbers[N / 2];
    } else {
        median = (numbers[N / 2 - 1] + numbers[N / 2]) / 2.0;
    }

    std::map<int, int> freq;
    for (int i = 0; i < N; ++i) {
        freq[numbers[i]]++;
    }

    int mode = numbers[0];
    int max_freq = freq[mode];
    for (auto& p : freq) {
        if (p.second > max_freq || (p.second == max_freq && p.first < mode)) {
            mode = p.first;
            max_freq = p.second;
        }
    }

    std::cout << min_val << '\n' << max_val << '\n' << avg << '\n' << median << '\n' << mode << '\n';

    return 0;
}
