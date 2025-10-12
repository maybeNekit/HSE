#include <iostream>
#include <functional>

int main() {
    std::plus<int> plusObj;
    std::minus<int> minusObj;
    std::multiplies<int> multObj;
    std::negate<int> negObj;

    int a = 10, b = 5;
    std::cout << "plus: " << plusObj(a, b) << std::endl;
    std::cout << "minus: " << minusObj(a, b) << std::endl;
    std::cout << "multiplies: " << multObj(a, b) << std::endl;
    std::cout << "negate: " << negObj(a) << std::endl;
    std::cout << "plus: " << std::plus<int>()(2, 3) << std::endl;

    return 0;
}