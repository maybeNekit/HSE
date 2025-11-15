#include <vector>
#include <list>
#include <deque>
#include <chrono>
#include <random>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <type_traits>


enum class ContainerType { Vector, Deque, List };
enum class Operation {
    PushBack, PushFront, RandomInsert,
    RandomErase, IterateSum, RandomAccess
};
enum class TimeUnit { Milliseconds, Seconds };

union TimeValue {
    double ms;
    double sec;
};

struct TimeResult {
    ContainerType ct;
    Operation op;
    TimeUnit unit;
    TimeValue val;
};


std::string operation_to_string(Operation op) {
    switch (op) {
        case Operation::PushBack:     return "PushBack";
        case Operation::PushFront:    return "PushFront";
        case Operation::RandomInsert: return "RandomInsert";
        case Operation::RandomErase:  return "RandomErase";
        case Operation::IterateSum:   return "IterateSum";
        case Operation::RandomAccess: return "RandomAccess";
    }
}


std::string name(ContainerType type) {
    switch (type) {
        case ContainerType::Vector: return "vector: ";
        case ContainerType::List:   return "list: ";
        case ContainerType::Deque:  return "deque: ";
    }
}


std::vector<int> generate_payload(int N) {
    std::vector<int> payload(N);
    std::mt19937 gen(12345);
    std::uniform_int_distribution<int> dist(0, 1000000);
    for (int &x : payload) {
        x = dist(gen);
    }
    return payload;
}

template<class Seq>
double measure_push_back(int N, int repeats = 10) {
    auto payload = generate_payload(N);
    double total = 0.0;
    Seq c;
    for (int i = 0; i < repeats; ++i) {
        c.clear();
        auto start = std::chrono::high_resolution_clock::now();
        for (int x : payload) c.push_back(x);
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}

template<class Seq>
double measure_push_front(int N, int repeats = 10) {
    auto payload = generate_payload(N);
    double total = 0.0;
    Seq c;
    for (int i = 0; i < repeats; ++i) {
        c.clear();
        auto start = std::chrono::high_resolution_clock::now();
        for (int x : payload) {
            if constexpr (std::is_same_v<Seq, std::vector<int>>) {
                c.insert(c.begin(), x);
            } else {
                c.push_front(x);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}

template<class Seq>
double measure_random_insert(int N, int repeats = 10) {
    auto payload = generate_payload(N);
    double total = 0.0;
    std::mt19937 gen(12345);
    Seq c;
    for (int i = 0; i < repeats; ++i) {
        c.clear();
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < N; ++j) {
            std::uniform_int_distribution<int> distpos(0, c.size());
            int pos_idx = distpos(gen);
            auto it = c.begin();
            if constexpr (std::is_same_v<Seq, std::list<int>>) {
                std::advance(it, pos_idx);
            } else {
                it += pos_idx;
            }
            c.insert(it, payload[j]);
        }
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}


template<class Seq>
double measure_random_erase(int N, int repeats = 10) {
    auto payload = generate_payload(N);
    double total = 0.0;
    std::mt19937 gen(12345);
    Seq c;
    for (int i = 0; i < repeats; ++i) {
        c.clear();
        for (int x : payload) c.push_back(x);
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < N; ++j) {
            std::uniform_int_distribution<int> distpos(0, c.size() - 1);
            int pos_idx = distpos(gen);
            auto it = c.begin();
            if constexpr (std::is_same_v<Seq, std::list<int>>) {
                std::advance(it, pos_idx);
            } else {
                it += pos_idx;
            }
            c.erase(it);
        }
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}

template<class Seq>
double measure_iterate_sum(int N, int repeats = 10) {
    auto payload = generate_payload(N);
    double total = 0.0;
    Seq c;
    for (int x : payload) c.push_back(x);
    for (int i = 0; i < repeats; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        volatile long long sum = 0;
        for (int x : c) sum += x;
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}

template<class Seq>
double measure_random_access(int N, int repeats = 10) {
    auto payload = generate_payload(N);
    double total = 0.0;
    std::mt19937 gen(12345);
    Seq c;
    for (int x : payload) c.push_back(x);
    std::vector<int> positions(N);
    std::uniform_int_distribution<int> distpos(0, c.size() - 1);
    for (int j = 0; j < N; ++j) positions[j] = distpos(gen);
    for (int i = 0; i < repeats; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        volatile int val = 0;
        for (int j = 0; j < N; ++j) {
            int pos = positions[j];
            if constexpr (std::is_same_v<Seq, std::list<int>>) {
                auto it = c.begin();
                std::advance(it, pos);
                val = *it;
            } else {
                val = c[pos];
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}


int main() {
    const int num_N = 4;
    const std::vector<int> N_values = {8192, 32768, 262144, 500000};
    const int repeats = 10;

    std::ofstream result_file("result.txt");

    result_file << std::fixed << std::setprecision(6);

    std::cout << std::fixed << std::setprecision(6);

    std::vector<std::pair<int, TimeResult>> vec_push_back(num_N);
    std::vector<std::pair<int, TimeResult>> list_push_back(num_N);
    std::vector<std::pair<int, TimeResult>> deque_push_back(num_N);

    for (int i = 0; i < num_N; ++i) {
        int N = N_values[i];

        vec_push_back[i].first = N;
        vec_push_back[i].second.ct = ContainerType::Vector;
        vec_push_back[i].second.op = Operation::PushBack;
        vec_push_back[i].second.val.ms = measure_push_back<std::vector<int>>(N, repeats);

        list_push_back[i].first = N;
        list_push_back[i].second.ct = ContainerType::List;
        list_push_back[i].second.op = Operation::PushBack;
        list_push_back[i].second.val.ms = measure_push_back<std::list<int>>(N, repeats);


        deque_push_back[i].first = N;
        deque_push_back[i].second.ct = ContainerType::Deque;
        deque_push_back[i].second.op = Operation::PushBack;
        deque_push_back[i].second.val.ms = measure_push_back<std::deque<int>>(N, repeats);
    }

    std::cout << operation_to_string(Operation::PushBack) << '\n';
    result_file << "Operation: PushBack \n";
    for (int i = 0; i < num_N; ++i) {
        std::string s = "N = " + std::to_string(vec_push_back[i].first) + " elements \n"
            + name(vec_push_back[i].second.ct) + std::to_string(vec_push_back[i].second.val.ms) + " ms, "
            + name(list_push_back[i].second.ct) + std::to_string(list_push_back[i].second.val.ms) + " ms, "
            + name(deque_push_back[i].second.ct) + std::to_string(deque_push_back[i].second.val.ms) + " ms\n\n";
        std::cout << s;
        result_file << s;
    }


    std::vector<std::pair<int, TimeResult>> vec_push_front(num_N);
    std::vector<std::pair<int, TimeResult>> list_push_front(num_N);
    std::vector<std::pair<int, TimeResult>> deque_push_front(num_N);

    for (int i = 0; i < num_N; ++i) {
        int N = N_values[i];

        vec_push_front[i].first = N;
        vec_push_front[i].second.ct = ContainerType::Vector;
        vec_push_front[i].second.op = Operation::PushFront;
        vec_push_front[i].second.val.ms = measure_push_front<std::vector<int>>(N, repeats);

        list_push_front[i].first = N;
        list_push_front[i].second.ct = ContainerType::List;
        list_push_front[i].second.op = Operation::PushFront;
        list_push_front[i].second.val.ms = measure_push_front<std::list<int>>(N, repeats);

        deque_push_front[i].first = N;
        deque_push_front[i].second.ct = ContainerType::Deque;
        deque_push_front[i].second.op = Operation::PushFront;
        deque_push_front[i].second.val.ms = measure_push_front<std::deque<int>>(N, repeats);
    }

    std::cout << operation_to_string(Operation::PushFront) << '\n';
    result_file << "Operation: PushFront \n";
    for (int i = 0; i < num_N; ++i) {
        std::string s = "N = " + std::to_string(vec_push_front[i].first) + " elements \n"
            + name(vec_push_front[i].second.ct) + std::to_string(vec_push_front[i].second.val.ms) + " ms, "
            + name(list_push_front[i].second.ct) + std::to_string(list_push_front[i].second.val.ms) + " ms, "
            + name(deque_push_front[i].second.ct) + std::to_string(deque_push_front[i].second.val.ms) + " ms\n\n";
        std::cout << s;
        result_file << s;
    }


    std::vector<std::pair<int, TimeResult>> vec_random_insert(num_N);
    std::vector<std::pair<int, TimeResult>> list_random_insert(num_N);
    std::vector<std::pair<int, TimeResult>> deque_random_insert(num_N);

    for (int i = 0; i < num_N; ++i) {
        int N = N_values[i];

        vec_random_insert[i].first = N;
        vec_random_insert[i].second.ct = ContainerType::Vector;
        vec_random_insert[i].second.op = Operation::RandomInsert;
        vec_random_insert[i].second.val.ms = measure_random_insert<std::vector<int>>(N, repeats);

        list_random_insert[i].first = N;
        list_random_insert[i].second.ct = ContainerType::List;
        list_random_insert[i].second.op = Operation::RandomInsert;
        list_random_insert[i].second.val.ms = measure_random_insert<std::list<int>>(N, repeats);

        deque_random_insert[i].first = N;
        deque_random_insert[i].second.ct = ContainerType::Deque;
        deque_random_insert[i].second.op = Operation::RandomInsert;
        deque_random_insert[i].second.val.ms = measure_random_insert<std::deque<int>>(N, repeats);
    }


    std::cout << operation_to_string(Operation::RandomInsert) << '\n';
    result_file << "Operation: RandomInsert \n";
    for (int i = 0; i < num_N; ++i) {
        std::string s = "N = " + std::to_string(vec_random_insert[i].first) + " elements \n"
            + name(vec_random_insert[i].second.ct) + std::to_string(vec_random_insert[i].second.val.ms) + " ms, "
            + name(list_random_insert[i].second.ct) + std::to_string(list_random_insert[i].second.val.ms) + " ms, "
            + name(deque_random_insert[i].second.ct) + std::to_string(deque_random_insert[i].second.val.ms) + " ms\n\n";
        std::cout << s;
        result_file << s;
    }


    std::vector<std::pair<int, TimeResult>> vec_random_erase(num_N);
    std::vector<std::pair<int, TimeResult>> list_random_erase(num_N);
    std::vector<std::pair<int, TimeResult>> deque_random_erase(num_N);

    for (int i = 0; i < num_N; ++i) {
        int N = N_values[i];

        vec_random_erase[i].first = N;
        vec_random_erase[i].second.ct = ContainerType::Vector;
        vec_random_erase[i].second.op = Operation::RandomErase;
        vec_random_erase[i].second.val.ms = measure_random_erase<std::vector<int>>(N, repeats);

        list_random_erase[i].first = N;
        list_random_erase[i].second.ct = ContainerType::List;
        list_random_erase[i].second.op = Operation::RandomErase;
        list_random_erase[i].second.val.ms = measure_random_erase<std::list<int>>(N, repeats);

        deque_random_erase[i].first = N;
        deque_random_erase[i].second.ct = ContainerType::Deque;
        deque_random_erase[i].second.op = Operation::RandomErase;
        deque_random_erase[i].second.val.ms = measure_random_erase<std::deque<int>>(N, repeats);
    }

    std::cout << operation_to_string(Operation::RandomErase) << '\n';
    result_file << "Operation: RandomErase \n";
    for (int i = 0; i < num_N; ++i) {
        std::string s = "N = " + std::to_string(vec_random_erase[i].first) + " elements \n"
            + name(vec_random_erase[i].second.ct) + std::to_string(vec_random_erase[i].second.val.ms) + " ms, "
            + name(list_random_erase[i].second.ct) + std::to_string(list_random_erase[i].second.val.ms) + " ms, "
            + name(deque_random_erase[i].second.ct) + std::to_string(deque_random_erase[i].second.val.ms) + " ms\n\n";
        std::cout << s;
        result_file << s;
    }


    std::vector<std::pair<int, TimeResult>> vec_iterate_sum(num_N);
    std::vector<std::pair<int, TimeResult>> list_iterate_sum(num_N);
    std::vector<std::pair<int, TimeResult>> deque_iterate_sum(num_N);

    for (int i = 0; i < num_N; ++i) {
        int N = N_values[i];

        vec_iterate_sum[i].first = N;
        vec_iterate_sum[i].second.ct = ContainerType::Vector;
        vec_iterate_sum[i].second.op = Operation::IterateSum;
        vec_iterate_sum[i].second.val.ms = measure_iterate_sum<std::vector<int>>(N, repeats);

        list_iterate_sum[i].first = N;
        list_iterate_sum[i].second.ct = ContainerType::List;
        list_iterate_sum[i].second.op = Operation::IterateSum;
        list_iterate_sum[i].second.val.ms = measure_iterate_sum<std::list<int>>(N, repeats);

        deque_iterate_sum[i].first = N;
        deque_iterate_sum[i].second.ct = ContainerType::Deque;
        deque_iterate_sum[i].second.op = Operation::IterateSum;
        deque_iterate_sum[i].second.val.ms = measure_iterate_sum<std::deque<int>>(N, repeats);
    }


    std::cout << operation_to_string(Operation::IterateSum) << '\n';
    result_file << "Operation: IterateSum \n";
    for (int i = 0; i < num_N; ++i) {
        std::string s = "N = " + std::to_string(vec_iterate_sum[i].first) + " elements \n"
            + name(vec_iterate_sum[i].second.ct) + std::to_string(vec_iterate_sum[i].second.val.ms) + " ms, "
            + name(list_iterate_sum[i].second.ct) + std::to_string(list_iterate_sum[i].second.val.ms) + " ms, "
            + name(deque_iterate_sum[i].second.ct) + std::to_string(deque_iterate_sum[i].second.val.ms) + " ms\n\n";
        std::cout << s;
        result_file << s;
    }


    std::vector<std::pair<int, TimeResult>> vec_random_access(num_N);
    std::vector<std::pair<int, TimeResult>> list_random_access(num_N);
    std::vector<std::pair<int, TimeResult>> deque_random_access(num_N);

    for (int i = 0; i < num_N; ++i) {
        int N = N_values[i];

        vec_random_access[i].first = N;
        vec_random_access[i].second.ct = ContainerType::Vector;
        vec_random_access[i].second.op = Operation::RandomAccess;
        vec_random_access[i].second.val.ms = measure_random_access<std::vector<int>>(N, repeats);

        list_random_access[i].first = N;
        list_random_access[i].second.ct = ContainerType::List;
        list_random_access[i].second.op = Operation::RandomAccess;
        list_random_access[i].second.val.ms = measure_random_access<std::list<int>>(N, repeats);

        deque_random_access[i].first = N;
        deque_random_access[i].second.ct = ContainerType::Deque;
        deque_random_access[i].second.op = Operation::RandomAccess;
        deque_random_access[i].second.val.ms = measure_random_access<std::deque<int>>(N, repeats);
    }

    std::cout << operation_to_string(Operation::RandomAccess) << '\n';
    result_file << "Operation: RandomAccess \n";
    for (int i = 0; i < num_N; ++i) {
        std::string s = "N = " + std::to_string(vec_random_access[i].first) + " elements \n"
            + name(vec_random_access[i].second.ct) + std::to_string(vec_random_access[i].second.val.ms) + " ms, "
            + name(list_random_access[i].second.ct) + std::to_string(list_random_access[i].second.val.ms) + " ms, "
            + name(deque_random_access[i].second.ct) + std::to_string(deque_random_access[i].second.val.ms) + " ms\n\n";
        std::cout << s;
        result_file << s;
    }

    result_file.close();

    return 0;
}