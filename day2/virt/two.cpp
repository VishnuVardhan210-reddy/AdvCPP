#include<iostream> 
#include<string> 

class Animal {
public: 
    Animal(){
        std::cout << "constructor of Animal" << std::endl;
    }
    int vala = 10;
    int valb = 20;
    void speak() const {
        std::cout << "Animal : (generic sound)\n";
    }
    void dont_speak() {

    }
};

class Dog : public Animal {
public:
    Dog () {
        std::cout << "constructor of Dog" << std::endl;
    }
    void speak(int x) const {
        std::cout << "boww boww\n";
    }
};

int main() {
    Animal obja;
    Dog objd;

    obja.speak();
    objd.speak();
}