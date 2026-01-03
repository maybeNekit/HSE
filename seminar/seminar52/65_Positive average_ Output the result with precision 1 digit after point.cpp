#include <iostream>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;

    int sum = 0, count = 0;
    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        if (num > 0) {
            sum += num;
            count++;
        }
    }

    if (count > 0) {
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(sum) / count << '\n';
    } else {
        std::cout << "0.0\n";
    }

    return 0;
}
