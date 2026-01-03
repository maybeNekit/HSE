#include <iostream>

int main() {
    int n,m,t=1,j;
    std::cin >> n >> m;
    std::cout << "\t" ;
    for (int i=0;i<n;i++) {
        std::cout << i+1 << "\t";
    }
    std::cout << std::endl;
    for (int i=1;i<=n;i++) {
        std :: cout << i << "\t" ;
        for (j=1;j<=n;j++) {
            std::cout << (i*j)%m<< "\t";
        }
        std::cout << std :: endl;
    }


}