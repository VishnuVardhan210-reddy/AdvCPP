#include <iostream>
#include <string>
#include <vector>

struct Person {
    std::string name;
    int age;

    Person(std::string n, int a) : name(std::move(n)), age(a) {
        std::cout << "Person constructed\n";
    }
    Person(const Person&) { std::cout << "Person copied\n"; }
    Person(Person&&) noexcept { std::cout << "Person moved\n"; }
};

int main() {
    std::vector<Person> v;
    v.reserve(2);

    std::cout << "--- push_back ---\n";
    Person p("Alice", 30);
    v.push_back(p); // copy (or move if std::move)

    std::cout << "--- emplace_back ---\n";
    v.emplace_back("Bob", 25); // constructs in place
}