#include <chrono>
#include <iostream>
#include <vector>
#include <deque>
#include <list>

template<typename Func>
double measureTime(Func func) {
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    func();
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> result = end - start;
    return result.count();
}

template<typename Contanier>
double testInsertBeginnig(int count) {
    return measureTime([count]() {
        Contanier c;
        for (int i = 0; i < count; ++i) {
            c.insert(c.begin(), i);
        }
    });

}

template<typename Contanier>
double testInsertend(int count) {
    return measureTime([count]() {
        Contanier c;
        for (int i = 0; i < count; ++i) {
            c.insert(c.end(), i);
        }
    });

}

template<typename Contanier>
double test10(int count) {
    return measureTime([count]() {
        Contanier c;
        for (int i = 0; i < count; i+=10) {

        }
    });

}

template<typename Contanier>
double del(int count) {
    return measureTime([count]() {
        Contanier c;
        for (int i = 0; i < 100; ++i) {
            c.erase(c.begin());
        }
    });

}

int main() {
    double resultVec = testInsertBeginnig<std::vector<int>>(1000);
    double resultDeq = testInsertBeginnig<std::deque<int>>(1000);
    double resultList = testInsertBeginnig<std::list<int>>(1000);
    std::cout << resultVec << "\n";
    std::cout << resultDeq << "\n";
    std::cout << resultList << "\n";
    std::cout << '\n';
    double resultVec2 = testInsertend<std::vector<int>>(100000);
    double resultDeq2= testInsertend<std::deque<int>>(100000);
    double resultList2 = testInsertend<std::list<int>>(100000);
    std::cout << resultVec2 << "\n";
    std::cout << resultDeq2 << "\n";
    std::cout << resultList2 << "\n";
    std::cout << '\n';
    double resultVec3 = test10<std::vector<int>>(101000);
    double resultDeq3= test10<std::deque<int>>(101000);
    double resultList3 = test10<std::list<int>>(101000);
    std::cout << resultVec3 << "\n";
    std::cout << resultDeq3 << "\n";
    std::cout << resultList3 << "\n";
    std::cout << '\n';
    double resultVec4 = del<std::vector<int>>(101000);
    double resultDeq4= del<std::deque<int>>(101000);
    double resultList4 = del<std::list<int>>(101000);
    std::cout << resultVec4 << "\n";
    std::cout << resultDeq4 << "\n";
    std::cout << resultList4 << "\n";
    return 0;
}