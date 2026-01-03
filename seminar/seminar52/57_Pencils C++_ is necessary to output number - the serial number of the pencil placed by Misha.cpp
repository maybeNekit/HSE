#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> pencils(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> pencils[i];
    }

    int new_pencil;
    std::cin >> new_pencil;

    int position = n + 1;
    for (int i = 0; i < n; ++i) {
        if (pencils[i] < new_pencil) {
            position = i + 1;
            break;
        } else if (pencils[i] == new_pencil) {
            position = i + 2;
        }
    }

    std::cout << position << '\n';

    return 0;
}
