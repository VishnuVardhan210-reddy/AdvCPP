#include <iostream>
#include <list>

int main() {
    std::list<int> a{1,2,3,4};
    std::list<int> b{10,20,30};

    auto pos = b.begin();      // insert before 10
    auto first = a.begin();    // 1
    auto last = std::next(a.begin(), 2); // up to (but not including) 3 => moves {1,2}

    b.splice(pos, a, first, last);

    // a now has {3,4}
    // b now has {1,2,10,20,30}
    for (int x : a) std::cout << x << " ";
    std::cout << "\n";
    for (int x : b) std::cout << x << " ";
    std::cout << "\n";
}