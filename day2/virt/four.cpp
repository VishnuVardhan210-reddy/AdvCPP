#include<iostream> 
#include<string> 

class Animal {
public: 
    void speak() const {
        std::cout << "Animal : (generic sound)\n";
    }
};

class Dog : public Animal {
public:
    void speak() const {
        std::cout << "boww boww\n";
    }
};

int main() {
    Animal obja;
    Dog objd;
    Animal* ptra; 
    ptra = &objd;
    ptra->speak(); 
    obja.speak();
    objd.speak();

}