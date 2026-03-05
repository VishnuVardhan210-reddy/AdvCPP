#include<iostream>
#include<utility>

struct Employee {
    int id;
    std::string name;
    double salary;
};

int main()
{
    Employee emp{111, "Jarvis", 76000};
    auto [id, name, value] = emp;

    std::cout << "value =" << value << std::endl;
    
}