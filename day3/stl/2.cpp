#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    std::cout << "size=" << v.size() << " cap=" << v.capacity() << "\n";

    for (int i = 1; i <= 10; ++i) {
        v.push_back(i);
        std::cout << "after push " << i
                  << ": size=" << v.size()
                  << " cap=" << v.capacity() << "\n";
    }
}