#include <iostream>
#include <deque>
#include <string>
template<typename T>
void addEl(std::deque<T>& buffer, int capacity, T value){
    if (buffer.size()==capacity) {
        buffer.pop_front();
    }
    buffer.push_back(value);
}


template<typename T>
void printBuffer(const std::deque<T>& buffer) {
    for (int i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    std::deque<int>buffer;
    int capacity = 5;
    for (int i = 1; i <= 7; ++i) {
        addEl(buffer, capacity, i);
        std::cout << "After adding " << i << ": ";
        printBuffer(buffer);
    }
    std::deque<std::string>b;
    int cap = 5;
    addEl(b, cap, std::string("q"));
    addEl(b, cap, std::string("qq"));
    addEl(b, cap, std::string("qqq"));
    addEl(b, cap, std::string("qqqq"));
    addEl(b, cap, std::string("qqqqq"));
    printBuffer(b);
    return 0;
}