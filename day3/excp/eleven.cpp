#include <iostream>

struct Cleaner {
    ~Cleaner() noexcept {
        try {
            // might throw
            throw 1;
        } catch (...) {
            std::cout << "Destructor swallowed exception\n";
        }
    }
};

int main() {
    Cleaner c;
}