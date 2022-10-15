#include <iostream>
#include <string>
#include <string_view>
#include <regex>

using namespace std::literals::string_literals;

std::string compose(const std::string& name, const std::string& domain) {
    return name + '@' + domain;
}

std::string cat(std::string_view sv1, std::string_view sv2) {
    std::string res;
    res.resize(sv1.length() + sv2.length());

    char* p = &res[0];
    for (char c : sv1) {
        *p++ = c;
    }

    std::copy(sv2.begin(), sv2.end(), p);
    return res;
}

int main(int argc, char** argv) {

    std::string addr = compose("dmr", "bell-labs.com");
    std::cout << addr << "\n";

    auto s = "Cat"s;     // Of type std::string
    auto p = "Cat";      // Of type const char*


    std::string king = "Harold";
    std::string result = cat({&king[0], 2}, {&king[3],2});   // Haol

    std::cout << result << "\n";


    std::regex pattern{R"(W\w{2}l)"};

    int lineNum = 0;


    std::string input = "Hello World";

    std::smatch matches;

    if (std::regex_search(input, matches, pattern)) {
        std::cout << "Contains pattern: \n\t" << matches[0] << "\n";
    }

    return 0;
}