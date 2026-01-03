#include "animals.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Zoo {
    std::vector<std::shared_ptr<Animal>> animals;
public:
    void add(std::shared_ptr<Animal> a) {
        animals.push_back(a);
    }
    const std::vector<std::shared_ptr<Animal>>& get() const {
        return animals;
    }
};

Zoo CreateZoo() {
    Zoo z;
    std::string s;
    while (std::cin >> s) {
        if (s == "Tiger") z.add(std::make_shared<Tiger>());
        else if (s == "Wolf") z.add(std::make_shared<Wolf>());
        else if (s == "Fox") z.add(std::make_shared<Fox>());
        else throw std::runtime_error("error");
    }
    return z;
}

void Process(const Zoo& z) {
    for (auto& a : z.get()) {
        std::cout << a->voice() << "\n";
    }
}