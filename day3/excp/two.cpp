#include<iostream>
#include<stdexcept> 
#include<fstream>


int main() {
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        std::cout << "started execution" << std::endl;
        file.open("data.txt") ;      
        std::cout<<"file opened successfully\n";
    } catch (const std::ios_base::failure& e) {
        std::cout << "caught the excpetion" <<std::endl;
        std::cout <<e.what() << "\n";
    }
}