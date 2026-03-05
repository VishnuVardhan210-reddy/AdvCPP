#include<iostream> 

class Animal {
public: 
    virtual void speak() {
        std::cout << "animal sound\n";
    }
};
class Dog final : public Animal {
public:
    void speak()  {
        std::cout << "woof\n";
    }
};

class Bulldog : public Dog {
    void speak() {
        std::cout << "bulldog says woof\n";
    }    

};
int main() {
    Dog objd;

}