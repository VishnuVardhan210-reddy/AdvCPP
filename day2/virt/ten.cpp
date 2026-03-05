#include<iostream> 
#include<string> 
#include<memory>
#include<vector>

class Animal {
public: 
    Animal() = delete;
};
class Dog : public Animal {
public:
    Dog() {

    }
};

int main() {
    Dog objd;

}