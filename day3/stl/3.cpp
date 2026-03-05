#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    v.reserve(2);             // force small capacity to show reallocation
    v.push_back(1);
    v.push_back(2);

    int* p = &v[0];           // pointer to element 0
    std::cout << "Before: p=" << (void*)p << " *p=" << *p << "\n";

    v.push_back(3);           // likely triggers reallocation

    std::cout << "After:  v.data()=" << (void*)v.data() << "\n";
    // p may now be dangling (DO NOT dereference it).
}