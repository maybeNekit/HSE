#include <iostream>
#include <string>
int ASCII(std::string a) {
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] <= 127 && a[i] > 32) {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}

int len(std::string a) {
    if (a.length() <= 14 && a.length() >= 8) {
        return 1;
    }
    return 0;
}

int f(std::string a) {
    int b=0,c=0,d=0,e =0;
    for (int i = 0; i < a.length(); ++i) {
        if ((b==0)&(a[i] <= 90 && a[i] >= 65)) {
            b+=1;
        }
        if ((c==0)&(a[i] <= 122 && a[i] >= 97)) {
            c+=1;
        }
        if ((d==0)&(a[i] <= 57 && a[i] >= 48)) {
            d+=1;
        }
        if ((e==0)&(32<=a[i] && a[i]<= 47)||(58<=a[i] && a[i]<= 64)||(91<=a[i] && a[i]<= 96)||(123<=a[i] && a[i]<= 127)) {
            e+=1;
        }
    }
    if (b+c+d+e>2) {
        return 1;
    }
    return 0;
}


int main() {
    std::string a;
    std::cin >> a;
    if (ASCII(a)*len(a)*f(a)==1) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}