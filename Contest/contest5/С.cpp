#include <iostream>
#include <string>
int num(std::string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < 58 && s[i] > 47) {
            continue;
        }else {
            s.erase(i, 1);
            --i;
        }
    }
    return 0;
}
int main() {
    std::string s;
    std::getline(std::cin, s);
    num(s);
    std::cout << s;

    return 0;
}