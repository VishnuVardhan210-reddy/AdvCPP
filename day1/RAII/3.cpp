#include<iostream>
#include<mutex> 
#include<stdexcept> 

std::mutex m;

void updateG() {
    std::lock_guard<std::mutex> lock(m);
    // --- does work ---
    throw std::runtime_error("boom");
}

void askingG() {
    
}

int main() {
    try {
        updateG();
    }catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }
    std::cout << "does program continue?\n";

}