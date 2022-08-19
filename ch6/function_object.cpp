#include <iostream>
#include <vector>

template<typename T>
class Less_than {
    const T val;

    public:
        Less_than(const T& v) : val{v} {}

        bool operator()(const T& x) const {
            return x < val;
        }
};

template<typename C, typename P>
int count(const C& c, const P& p) {
    int cnt = 0;

    for (const auto& x : c) {
        if (p(x)) {
            cnt++;
        }
    }

    return cnt;
}


template<typename C, typename Oper>
void for_all(C& c, Oper op) {
    for (auto& x : c) {
        op(x);
    }
}

int main(int argc, char** argv) {

    Less_than<int> t{100};

    std::cout << t(50) << "\n";     // True (1) <- 50 < 100
    std::cout << t(101) << "\n";     // False (0) <- 101 < 100

    std::vector<int> nums {1,2,3,4,5,6,7,8};
    Less_than<int> predicate{4};

    std::cout << count(nums, predicate) << "\n";
    // std::cout << count(nums, [&](int s) {return });

    int cmp = 5;
    int count = 0;

    // for_all<std::vector<int>, decltype(lambda)>(nums, lambda);
    for_all(nums, [&](int a) {
        if (a < cmp) {
            count++;
        }
    });

    std::cout << count << "\n";

    return 0;
}