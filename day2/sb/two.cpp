#include<iostream>
#include<utility>

int main()
{
    std::tuple<int, std::string, double> person = 
    {1010, "jarvis", 33.67};
    int numbers[3] = {5, 10, 20};
    
    auto [id, name, value] = person;

    std::cout << "value =" << value << std::endl;
    
}