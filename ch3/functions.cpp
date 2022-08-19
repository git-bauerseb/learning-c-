#include <iostream>
#include <fstream>
#include <string>
#include <map>

struct A {
    int field;
};

struct Entry {
    std::string name;
    int value;
};

int& someFunc(struct A& a) {
    return a.field;
}

Entry read_entry(std::istream& is) {
    std::string s;
    int i;
    is >> s >> i;
    return {s,i};       // Structured binding
}

void iterate(const std::map<std::string,int>& m) {
    for(const auto [key,value] : m) {
        std::cout << "{" << key << "," << value << "}\n";
    }
}

int main() {

    /*
    A a{100};
    int& val = someFunc(a);
    val = 200;
    std::cout << a.field << "\n";
    */

    /*
    Entry e = read_entry(std::cin);
    std::cout << e.name << "\n" << e.value << "\n";
    */

    std::map<std::string, int> m;
    m.insert(std::pair<std::string, int>{"Hello", 1});

    iterate(m);

    return 0;
}