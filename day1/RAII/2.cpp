#include<iostream>
#include<fstream>
std::vector<int> makeArrayA (std::size_t n) {
    std::vector<int> v(n);  //allocates
    // --- do work ----
    return v;   
}

int * makeArrayB (std::size_t n) {
    int *p = new int[n];
    // --- do work ---
    return p;
}

int main() {
    auto v = makeArrayA(5);
    return 0; 
}