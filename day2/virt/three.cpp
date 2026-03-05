#include<iostream> 
#include<string> 

class Animal {
public: 
    Animal(){
        std::cout << "constructor of Animal" << std::endl;
    }
    void speak() const {
        std::cout << "Animal : (generic sound)\n";
    }
};

class Dog : public Animal {
public:
    Dog () {
        std::cout << "constructor of Dog" << std::endl;
    }
    void speak() const {
        std::cout << "boww boww\n";
    }
};

int main() {
    Animal obja;
    Dog objd;
    Animal* ptra; 
    ptra = new Animal[4]; 

}