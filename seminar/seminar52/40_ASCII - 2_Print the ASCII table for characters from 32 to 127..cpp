#include <iostream>

int main() {
    int i1=0,i2=2,baf2=32,i3=0;
    int baf=65;
    while (i1<10) {
        std::cout << "\t"<< i1 ;
        i1++;
    }
    while (baf<=70) {
        std::cout << "\t" <<char(baf);
        baf++;
    }
    while (i2 <=7) {
        std::cout <<std::endl;
        std::cout << i2;
        while (i3 <16) {
            std::cout << "\t" <<char(baf2);
            baf2++;
            i3++;
        }
        i2++;
        i3 = 0;
    }
    return 0;
}