#include<iostream>
#include<fstream>
#include<stdexcept>

void b() {
    std::ofstream f("out.txt");

    if (!f) throw std::runtime_error("failed to open");
     f << "together success\n";

    if (true) return;
    //f.close() 
}