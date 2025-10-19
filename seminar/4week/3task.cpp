#include <iostream>
#include <list>
#include <string>

void addLine(std::list<std::string>&list, const std::string& line ) {
    list.push_back(line);
}

void insertLine(std::list<std::string>&list, int pos, const std::string& line) {
    if (pos < 1 || pos > list.size() + 1) {
        std::cout << "Invalid position!" << std::endl;
    }

    auto it = list.begin();
    std::advance(it, pos - 1);
    list.insert(it, line);
}

void print(std::list<std::string>&list) {
    for (const std::string &el : list) {
        std::cout << el << '\n';
    }
}

void del(std::list<std::string>&list, int pos) {
    if (pos < 1 || pos > list.size()) {
        std::cout << "Error: Invalid position!" << std::endl;
        return;
    }

    auto it = list.begin();
    std::advance(it, pos - 1);
    list.erase(it);
}

void replaceLine(std::list<std::string>& list, int position, const std::string& line) {
    if (position < 1 || position > list.size()) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    auto it = list.begin();
    std::advance(it, position - 1);
    *it = line;
}


int main() {
    std::list<std::string>list;
    addLine(list, "1,2,3,4");
    insertLine(list,2,  "7,7,7,7");
    print(list);
    std::cout << '\n';
    del(list,2);
    print(list);
    std::cout << '\n';
    replaceLine(list,2,  "0,0,0,0");
    print(list);
    return 0;
}