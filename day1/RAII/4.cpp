#include<memory>
#include <iostream>

struct Engine {
    Engine() {
        std::cout << "Engine started\n";
    }
    ~Engine() {
        std::cout << "Engine stopped\n";
    }
    void run() {
        std::cout<< "Running..\n";
    }
};

int main() {
//    Engine *p = new Engine;
    auto e = std::make_unique<Engine>(); // acquire
    std::unique_ptr<Engine> p2 = std::move(e);
/*    p->run();
    delete p;*/
}