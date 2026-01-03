#include <iostream>
#include <vector>

class Dist {
private:
    int meters;
public:
    Dist(int m):meters(m){};

    int getMeters() {
        return meters;
    }

    void setMeters(int a) {
        meters=a;
    }

    void print() {
        std::cout <<"Distance: " << meters << " m";
    }
};

class Seq {
private:
    std::vector<int> values;
public:
    void add(int m) {
        values.emplace_back(m);
    }

    int size() {
        return values.size();
    }

    int at(int index) {
        return values[index];
    }

    void print() {
        for (const auto& v:values) {
            std::cout << "Distance: " << v << " m" << '\n';
        }
    }
};

int main() {
    Seq s;
    int n;
    std::cin >> n;
    for (int i =0; i<n; i++) {
        int a;
        std::cin >>a;
        s.add(a);
    }
    int k;
    std::cin >> k;
    std::cout << s.at(k) <<'\n' << s.size() << '\n';
    s.print();



    return 0;
}