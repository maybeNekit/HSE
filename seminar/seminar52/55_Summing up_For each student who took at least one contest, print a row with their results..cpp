#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;

    std::map<std::string, std::vector<int>> results;

    for (int i = 0; i < N; ++i) {
        int K;
        std::cin >> K;

        std::map<std::string, int> contest_results;

        for (int j = 0; j < K; ++j) {
            std::string login;
            int score;
            std::cin >> login >> score;
            contest_results[login] = score;
        }

        for (auto &student : contest_results) {
            results[student.first].resize(N, 0);  // Ensure there's enough space for N contests
            results[student.first][i] = student.second;
        }
    }

    for (auto &entry : results) {
        std::cout << entry.first;
        for (int score : entry.second) {
            std::cout << '\t' << score;
        }
        std::cout << '\n';
    }

    return 0;
}
