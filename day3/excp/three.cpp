#include<iostream>
#include<stdexcept> 
#include<fstream>
#include<unistd.h>

int main() {
    try {
        int i = 0; 
        while(true) {
            sleep(1);
           
            ++i;
            std::cout << "allocation for " << i << " times \n";

            new int [10000000000]; //allocating huge are of memory 
        }
    } catch (const std::bad_alloc& e) {
        std::cout <<e.what() << "\n";
    }
}