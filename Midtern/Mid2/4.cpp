#include <iostream>
#include <vector>

class Score {
public:
    virtual ~Score() = default;

    virtual int getScore() const =0;
    virtual void print() const = 0;
};

class First : public Score {
private:
    int score;
public:
    First(int s):score(s){};
    int getScore() const override {
        return score;
    }

    void print() const override {
        std::cout <<getScore() << ' ';
    }
};

class Second : public Score {
private:
    Score* a;
public:
    Second(Score* w): a(w){};
    int getScore() const override {
        return a-> getScore()+2;
    }

    void print() const override {
        std::cout <<getScore() << ' ';
    }
};

class Tri : public Score {
private:
    Score* a;
    int m;
public:
    Tri(Score* w,int m): a(w), m(m){};
    int getScore() const override {
        return a-> getScore()*m;
    }

    void print() const override {
        std::cout <<getScore() << ' ';
    }
};



int main() {
    int val;
    std::cin >>val;
    First f(val);
    Second s(&f);
    Tri t(&s, 3);
    std::vector<Score*> v = {&f, &s, &t};

    int sum=0;
    for (auto i : v) {
        i->print();
        sum += i->getScore();
    }
    std::cout <<'\n'<< sum;
    return 0;
}