#include<memory>
#include <iostream>
#include<chrono>
#include<thread>
using namespace std::chrono_literals;
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
    auto e = std::make_shared<Engine>(); 
    auto p2 = e; 
    std::cout << e.use_count() << std::endl; 
    e.reset() ; 
    std::this_thread::sleep_for(4s);
    p2 = nullptr;
//    p2 = std::make_shared<Engine>();
}