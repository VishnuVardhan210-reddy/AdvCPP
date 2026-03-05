#include <iostream>
#include <stdexcept>

void g() noexcept {
    throw std::runtime_error("cannot escape");
}

int main() {
    g(); // program terminates
}