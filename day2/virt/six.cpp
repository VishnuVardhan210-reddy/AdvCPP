#include<iostream> 
#include<string> 

class Animal {
public: 
    virtual void speak() const {
        std::cout << "Animal : (generic sound)\n";
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "boww boww\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "meow\n";
    }
};

int main() {
    Dog objd;
    Cat objc;
    Animal* ptra; 
    ptra = &objd;
    ptra->speak(); 
    ptra = &objc;
    ptra->speak();

    //Animal* qtra = new Dog(); 
}