#include <iostream>

int main() {
    int n,a,s=0,b=0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        s+=a;
    }
    for (int i = 0; i < n+2; i++) {
        b+=i;
    }
    std::cout<< b-s<<'\n';
    return 0;
}