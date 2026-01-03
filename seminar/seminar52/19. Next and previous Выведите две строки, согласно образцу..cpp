#include <iostream>
#include <string>
int main() {
    int n;
    std::cin>>n;
    int a=n+1;
    int b=n-1;
    std::string kaar=std::to_string(a);
    std::string mur=std::to_string(b);
    std::cout<<"The next number for the number "<<n<<" is "<<a<<"."<<"\n";
    std::cout<<"The previous number for the number "<<n<<" is "<<b<<"."<<"\n";
}