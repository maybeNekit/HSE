#include <iostream>
#include <vector>
#include <cstdlib>
auto gen(int n, int m) {
    std::vector<std::vector<int>> mat(n, std::vector<int>(m));
    for (int i = 0; i<mat.size();++i) {
        for (int j = 0; j<mat[i].size();++j) {
            mat[i][j] = std::rand()%101-50;
        }
    }
    return mat;
}

void print(const std::vector<std::vector<int>> &mat) {
    for (int i = 0; i<mat.size();++i) {
        for (int j = 0; j<mat[i].size();++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void replace_negatives_with_squares ( std :: vector < std :: vector <int >> & mat ) {
    for (int i = 0; i<mat.size();++i) {
        for (int j = 0; j<mat[i].size();++j) {
            if (mat[i][j] < 0) {
                mat[i][j] = mat[i][j]*mat[i][j];
            }
        }
    }
}

std :: pair < long long , std :: vector <int > >
 sum_evens_and_collect_odds ( const std :: vector < std :: vector <int >> & mat ) {
    int s = 0;
    std::vector<int> odd;
    for (int i = 0; i<mat.size();++i) {
        for (int j = 0; j<mat[i].size();++j) {
            if (mat[i][j]%2 ==0) {
                s+= mat[i][j];
            }else {
                odd.push_back(mat[i][j]);
            }
        }
    }
    return {s,odd};
}

template < class ForwardIt , class UnaryOp >
void transform_range ( ForwardIt first , ForwardIt last , UnaryOp op ) {
    while (first != last) {
        *first = op(*first);
        ++first;
    }
}

template<class InputIt, class OutputIt, class Pred>
OutputIt copy_if_range(InputIt first, InputIt last, OutputIt out, Pred p) {
    while (first != last) {
        if (p(*first)) {
            *out = *first;
            ++out;
        }
        ++first;
    }
    return out;
}

int main() {
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> vec(n, std::vector<int>(m));
    vec = gen(n,m);
    print(vec);
    std::cout << '\n';
    replace_negatives_with_squares(vec);
    print(vec);
    std::cout << '\n';
    auto p = sum_evens_and_collect_odds(vec);
    std::cout << p.first << '\n';
    for (int i=0; i<p.second.size();i++) {
        std::cout<< p.second[i] << " ";
    }
    std::cout << '\n';
    for (int i=0; i < vec.size();++i) {
        transform_range(vec[i].begin(), vec[i].end(), [](int x) {
            if (x == 0) {
                return -1;
            }
            return x;
        });
    }
    print(vec);
    std::cout << '\n';
    std::vector<int> odd;
    for (int i=0; i < vec.size();++i) {
        copy_if_range(vec[i].begin(), vec[i].end(), std::back_inserter(odd),[](int x) {
            return x%2!=0;
        });
    }
    for (int i=0;i<odd.size();++i) {
        std::cout << odd[i] << " ";
    }
    return 0;
}