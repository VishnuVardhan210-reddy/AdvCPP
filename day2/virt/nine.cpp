#include<iostream> 
#include<string> 
#include<memory>
#include<vector>

class Animal {
public: 
    Animal() = delete;
    Animal(int, int);
};


int main() {
    Animal obja;
    Animal objb(10, 20);

}