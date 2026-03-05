#include<memory>
#include <iostream>

struct Motor; // forward declaration
struct Engine {
    std::shared_ptr<Motor> mOne;
    ~Engine() {
        std::cout << "Engine stopped\n";
    }
};
struct Motor {
    std::weak_ptr<Engine> eOne;
    ~Motor() {
        std::cout << "Motor stopped";
    }
};
int main() {
    auto etwo = std::make_shared<Engine>(); 
    auto mtwo = std::make_shared<Motor>(); 
    etwo->mOne = mtwo;
    mtwo->eOne = etwo;  //weak_reference
}