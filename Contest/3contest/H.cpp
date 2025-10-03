#include <iostream>
#include <string>
#include <algorithm>
int main() {
    int n,k=0;
    std::string s,a;
    std::cin >> n;
    for(int i=0;i<n;i++) {
        std::cin >> a;
        s+=a;
        s+=' ';
    }
    for(int i=0;i<n;i++){
        if (std::count(s.begin(),s.end(),s[i])>n/2) {
            (s[i]!=' ')&&std::cout << s[i]&&++k;
            if (k==1) {
                break;
            }
        }
    }
    return 0;
}