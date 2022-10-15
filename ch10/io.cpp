#include <iostream>
#include <istream>
#include <vector>
#include <string>

std::vector<int> read_ints(std::istream& is, const std::string terminator) {
    std::vector<int> res;
    for (int i; is >> i;) {
        res.push_back(i);
    }

    if (is.eof()) {return res;}
    if (is.fail()) {
        is.clear();
        is.unget();
        std::string s;
        if (std::cin >> s && s == terminator) {
            return res;
        }

        std::cin.setstate(std::ios_base::failbit);
    }

    return res;
}

int main() {

    read_ints(std::cin, "?");


    return 0;
}