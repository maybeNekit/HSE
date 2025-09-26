#include <iostream>

int main() {
    int a,b,c,d;
    std::cin >> a >> b >> c >> d;
    if ((a==c)||(b==d) || (abs(c-a) == abs(b-d))) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}