#include <iostream>
#include <set>

int main() {
    int N;
    std::cin >> N;

    std::set<int> numbers;

    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        numbers.insert(num);
    }

    for (int num : numbers) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}