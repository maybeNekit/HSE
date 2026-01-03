#include <iostream>
#include <string>

int main() {
    std::string kaar;
    std::getline(std::cin,kaar);
    int n=1;
    if (kaar.empty()) {
        n=0;
    } else {
        for (char c:kaar) {
            if (c==' ') {
                n++;
            }
        }
    }
    std::cout<<n<<std::endl;

}