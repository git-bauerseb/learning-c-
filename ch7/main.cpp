#include <iostream>
#include <vector>

template<typename Seq, typename Num>
Num sum(Seq s, Num v) {
    for (const auto& x : s) {
        v += x;
    }

    return v;
}

template<typename... T>
int sum2(T... v) {
    return (0 + ... + v);
}

template<typename Res, typename... Ts>
std::vector<Res> to_vector(Ts&&... ts) {
    std::vector<Res> res;
    (res.push_back(ts) ...);
    return res;
}

int main(int argc, char** argv) {

    std::vector<int> v{1,2,3,4,5,6,7,8,9};
    std::cout << sum2(1,2,3,4,5,6,7,8,9) << "\n";

    return 0;
}