#include <iostream>
#include <vector>

std::vector<std::vector<int>> gen(int n, int m) {
    std::vector<std::vector<int>> v(n, std::vector<int>(m));
    for (int i =0 ; i < n ; i++) {
        for (int j =0 ; j < m ; j++) {
            int a;
            std::cin >> a;
            v[i][j] = a;
        }
    }
    return v;
}

void print(const std::vector<std::vector<int>> &mat) {
    for (int i =0 ; i < mat.size() ; i++) {
        for (int j =0 ; j < mat[i].size() ; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << '\n';
    }
}

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>> &mat) {
    std::vector<std::vector<int>> v(mat[0].size(), std::vector<int>(mat.size()));
    for (int i =0 ; i < mat.size() ; i++) {
        for (int j =0 ; j < mat[i].size() ; j++) {
            v[j][i]=mat[i][j];
        }
    }
    return v;
}


void cubePos(std::vector<std::vector<int>> &mat) {
    for (int i =0 ; i < mat.size() ; i++) {
        for (int j =0 ; j < mat[i].size() ; j++) {
            if (mat[i][j]%2 == 0) {
                mat[i][j] = mat[i][j]*mat[i][j]*mat[i][j];
            }
        }
    }
}

std:: pair<std::vector <int>, long long>
coLumn_maxima_and_negative_product(const std::vector<std::vector<int>> & mat) {
    std::vector<int> max;
    int pr = 1;
    for (int i =0 ; i < mat[0].size() ; i++) {
        int a = -1000;
        for (int j =0 ; j < mat.size() ; j++) {
            if (mat[j][i] > a) {
                a = mat[j][i];
            }
            if (mat[j][i] < 0) {
                pr *= mat[j][i];
            }
        }
        max.push_back(a);
    }
    return {max, pr};
}

template<class ForwardIt, class Pred, class UnaryOp>
void apply_if_range(ForwardIt first, ForwardIt last, Pred p, UnaryOp op) {
    while (first != last) {
        if (p(*first)) {
            *first = op(*first);
        }
        ++first;
    }
}

template<class InputIt, class OutputItTrue, class OutputItFalse, class Pred>
std::pair<OutputItTrue, OutputItFalse>
partition_copy_range(InputIt first, InputIt last,
OutputItTrue out_true, OutputItFalse out_false, Pred p) {
    while (first!=last) {
        if (p(*first)) {
            *out_true = *first;
            ++out_true;
        } else {
            *out_false = *first;
            ++out_false;
        }
        ++first;
    }
    return {out_true,out_false};
}

int main() {
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<int> > vec = gen(n, m);
    print(vec);
    std::cout << '\n';
    std::vector<std::vector<int> > vec2 = transpose(vec);
    print(vec2);
    std::cout << '\n';
    cubePos(vec);
    print(vec);
    std::cout << '\n';
    std::cout << "3";
    std::cout << '\n';
    auto pair = coLumn_maxima_and_negative_product(vec);
    for (int i = 0; i < pair.first.size(); ++i) {
        std::cout << pair.first[i] << " ";
    }
    std::cout << '\n';
    std::cout << pair.second;
    std::cout << '\n';
    for (int i = 0; i <vec.size(); ++i) {
        apply_if_range(vec[i].begin(), vec[i].end(), [](int x) {
            if (x%3==0) {
                return 1;
            } else {
                return 0;
            }
        }, [](int x) {
            return x +5;
        });
    }
    print(vec);
    std::cout << '\n';
    std::vector<int> no;
    std::vector<int> neg;
    for (int i = 0; i <vec.size(); ++i) {
        partition_copy_range(vec[i].begin(),vec[i].end(),std::back_inserter(no),std::back_inserter(neg),[](int x) {
            if (x >=0) {
                return 1;
            } else {
                return 0;
            }
        });
    }
    std::cout << "5";
    std::cout << '\n';
    for (int i =0; i<no.size();++i) {
        std::cout << no[i] << " ";
    }
    std::cout << '\n';
    for (int i =0; i<neg.size();++i) {
        std::cout << neg[i] << " ";
    }
    std::cout << '\n';
    return 0;
}
