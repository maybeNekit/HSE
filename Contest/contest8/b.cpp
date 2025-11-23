#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
    std::string firstName;
    std::string lastName;
    int day;
    int month;
    int year;
};

bool compareDate(const Student& a, const Student& b) {
    if (a.year != b.year) {
        return a.year < b.year;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }
    if (a.day != b.day) {
        return a.day < b.day;
    }
    if (a.lastName != b.lastName) {
        return a.lastName < b.lastName;
    }
    return a.firstName < b.firstName;
}

bool compareName(const Student& a, const Student& b) {
    if (a.lastName != b.lastName) {
        return a.lastName < b.lastName;
    }
    if (a.firstName != b.firstName) {
        return a.firstName < b.firstName;
    }
    if (a.year != b.year) {
        return a.year < b.year;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }
    return a.day < b.day;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> students[i].firstName >> students[i].lastName >> students[i].day >> students[i].month >> students[i].year;
    }
    std::string type;
    std::cin >> type;
    if (type == "date") {
        std::sort(students.begin(), students.end(), compareDate);
    } else {
        std::sort(students.begin(), students.end(), compareName);
    }
    for (const auto& s : students) {
        std::cout << s.firstName << " " << s.lastName << " " << s.day << "." << s.month << "." << s.year << "\n";
    }
    return 0;
}