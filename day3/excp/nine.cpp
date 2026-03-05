#include <iostream>
#include <stdexcept>
#include <exception>

void read_config() {
    throw std::runtime_error("config file not found");
}

void init_app() {
    try {
        read_config();
    } catch (...) {
        std::throw_with_nested(std::runtime_error("init_app failed"));
    }
}

void print_nested(const std::exception& e, int level = 0) {
    std::cout << std::string(level * 2, ' ') << "- " << e.what() << "\n";
    try {
        std::rethrow_if_nested(e);
    } catch (const std::exception& inner) {
        print_nested(inner, level + 1);
    } catch (...) {
        // non-std exception nested
    }
}

int main() {
    try {
        init_app();
    } catch (const std::exception& e) {
        print_nested(e);
    }
}