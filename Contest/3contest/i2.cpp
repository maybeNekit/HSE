#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

int main() {
    int n, nu;
    long long k = 0;
    std::string s;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nu;
        std::bitset<20> b(nu);
        std::string bi = b.to_string();
        if (bi.length() > 15) {
            bi = bi.substr(bi.length() - 15);
        }
        k += std::stoll(bi);
        //std::cout << k << ' ';
        s = std::to_string(k);
        std::replace(s.begin(), s.end(), '3', '0');
        k = std::stoll(s);
        //std::cout << k << '\n';
    }
    std::string a = std::to_string(k);
    if (a.find('2') != std::string::npos) {
        std::string b = std::to_string(k / 2);
        std::cout << std::stoll(b, nullptr, 2) << ' ' << '2';
    } else {
        std::cout << std::stoll(a, nullptr, 2) << ' ' << '1';
    }
    return 0;
}