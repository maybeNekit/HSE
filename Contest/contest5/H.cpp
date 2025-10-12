#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    bool fl = false;
    int n = s.length();
    for (int i = n - 1; i >= 0; i--) {
        int a = s[i] - '0';
        if (a != 9) {
            for (int j = 0; j < i; j++) {
                std::cout << s[j];
            }
            std::cout << a + 1;
            for (int j = i + 1; j < n; j++) {
                std::cout << "0";
            }
            fl = true;
            break;
        }
    }
    if (!fl) {
        std::cout << "1";
        for (int i = 0; i < n; i++) {
            std::cout << "0";
        }
    }
    return 0;
}