#include <iostream>
#include <map>
#include <unordered_map>

int main() {
    std::map<int, std::string> ordered;
    std::unordered_map<int, std::string> hashed;

    ordered[10] = "ten";
    ordered[5]  = "five";
    ordered[7]  = "seven";

    hashed[10] = "ten";
    hashed[5]  = "five";
    hashed[7]  = "seven";

    std::cout << "map order: ";
    for (auto& [k,v] : ordered) std::cout << k << " ";
    std::cout << "\n";

    std::cout << "unordered_map order: ";
    for (auto& [k,v] : hashed) std::cout << k << " ";
    std::cout << "\n";
}