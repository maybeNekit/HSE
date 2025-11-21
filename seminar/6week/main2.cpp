#include <iostream>
#include <cmath>
#include <vector>
class Counter {
public:
    struct LogEntry {
        std::string action;
        int oldValue;
        int newValue;
    };
    int value;
    std::vector<LogEntry> log;
    Counter(int value = 0) {
        this -> value = value;
    };


    Counter& inc(int delta = 1) {
        this -> value += delta;
        return *this;
    };
    Counter& dec(int delta = 1) {
        this -> value += delta;
        return *this;
    };
    Counter& set(int delta = 1) {
        this -> value += delta;
        return *this;
    };
int main() {

    return 0;
}