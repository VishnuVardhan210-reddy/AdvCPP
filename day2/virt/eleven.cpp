#include<iostream> 

class Animal {
public: 
    virtual void speak() {
        std::cout << "animal sound\n";
    }
};
class Dog : public Animal {
public:
    void speak() final {
        std::cout << "woof\n";
    }
};

class Bulldog : public Dog {
    void speak() {
        std::cout << "woof\n";
    }    

};
int main() {
    Dog objd;

}