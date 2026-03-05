#include <iostream>
#include <list>

int main() {
    std::list<int> L{1,2,3,4,5,6};

    for (auto it = L.begin(); it != L.end(); ) {
        if (*it % 2 == 0) {
            it = L.erase(it); // returns next iterator
        } else {
            ++it;
        }
    }

    for (int x : L) std::cout << x << " ";
    std::cout << "\n";
}