#include <iostream>
#include <string>
int main() {
    std::string a;
    int i,s,suma=0;
    std::cin >> a;
    s = a.length();
    for (i=0;i<s;i++) {
        suma += a[i]-'0';
    }
    std:: cout << suma;
    return 0;

}