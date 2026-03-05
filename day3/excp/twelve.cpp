#include <stdexcept>
#include <string>
#include <iostream>

class ParseError : public std::runtime_error {
public:
    explicit ParseError(const std::string& msg)
        : std::runtime_error("ParseError: " + msg) {}
};

int main() {
    try {
        throw ParseError("expected integer at line 3");
    } catch (const ParseError& e) {
        std::cout << e.what() << "\n";
    }
}