#include "c.h"
int main(){
    int n;
    std::cin>>n;
    C*c=new C[n];
    delete[]c;
}