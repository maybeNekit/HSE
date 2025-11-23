#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point{
    int x;
    int y;
};

bool compare(const Point& a, const Point& b) {
    double dist1 = std::sqrt(a.x * a.x + a.y * a.y);
    double dist2 = std::sqrt(b.x * b.x + b.y * b.y);
    return dist1<dist2;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<Point> p(n);

    for (int i =0; i < n; ++i) {
        std::cin >> p[i].x >> p[i].y;
    }
    std::sort(p.begin(), p.end(), compare);
    for (const auto& po : p) {
        std::cout << po.x << " " << po.y << '\n';
    }
    return 0;
}