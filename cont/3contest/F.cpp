#include <iostream>
#include <string>
int main() {
    int a=0,k = 0;
    std::string s, res;
    std::cin >> s;
    std::cout << s[0];
    k+=1;
    for (int i = 1; i < s.size(); i++) {
        switch (s[i]) {
            case 'b': case 'f': case 'p': case 'v':
                ((a!=1)&&(k<4)&&(std::cout <<1)&&++k);
                a =1;
                break;
            case 'c': case 'g': case 'j': case 'k': case 'q': case 's': case 'x': case 'z':
                ((a!=2)&&(k<4)&&(std::cout <<2)&&++k);
                a =2;
                break;
            case 'd': case 't':
                ((a!=3)&&(k<4)&&(std::cout <<3)&&++k);
                a =3;
                break;
            case 'l':
                ((a!=4)&&(k<4)&&(std::cout <<4)&&++k);
                a =4;
                break;
            case 'm': case 'n':
                ((a!=5)&&(k<4)&&(std::cout <<5)&&++k);
                a =5;
                break;
            case 'r':
                ((a!=6)&&(k<4)&&(std::cout <<6)&&++k);
                a =6;
                break;
            case 'a': case 'e': case 'h': case 'i': case 'o': case 'u': case 'w': case 'y':
                break;
        }
    }
    while (k<4) {
        ++k;
        std::cout << 0;
    }
    return 0;
}