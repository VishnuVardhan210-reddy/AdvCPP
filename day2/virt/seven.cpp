#include<iostream> 
#include<string> 
#include<memory>
#include<vector>

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
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());
    animals.push_back(std::make_unique<Animal>());

    std::cout << "Polymorphic class:\n";
    for (const auto& i: animals){
        i->speak();

    }

}