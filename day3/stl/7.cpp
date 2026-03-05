#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> m;
    m[3] = "three";
    m[1] = "one";
    m[2] = "two";

    for (auto& [k,v] : m) {
        std::cout << k << " -> " << v << "\n";
    }
}