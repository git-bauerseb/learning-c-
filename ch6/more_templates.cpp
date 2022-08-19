#include <vector>
#include <iostream>

template<typename Sequence, typename Value>
Value sum(const Sequence& s, Value v) {
    for (auto x : s) {
        v += x;
    }

    return v;
}

int main(int argc, char** argv) {

    std::vector<int> nums1{1,2,3,4,5,6};
    int s = sum(nums1, 1);

    std::cout << s << "\n";

    return 0;
}