#include<iostream> 
#include<string> 
#include<memory>
#include<vector>

class Animal {
public: 
    Animal() = default;
    Animal(const Animal(&)) = delete; 
};


int main() {
    Animal obja;
    Animal objb = obja;

}