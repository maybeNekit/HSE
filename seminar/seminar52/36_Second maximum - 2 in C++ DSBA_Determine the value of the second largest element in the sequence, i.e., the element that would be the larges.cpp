#include <iostream>

int main() {
    int largest = -1, secondLargest = -1, num;

    while (std::cin >> num && num != 0) {
        if (num > largest) {
            secondLargest = largest;
            largest = num;
        } else if (num > secondLargest) {
            secondLargest = num;
        }
    }

    std::cout << secondLargest << std::endl;
    return 0;
}
