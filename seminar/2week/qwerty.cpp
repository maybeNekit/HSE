#include <iostream>

int main() {
    int* p;
    for(int i=0;i<3;i++){
        int x=i;
        p=&x;
    }
    std::cout<<*p;
    return 0;
}