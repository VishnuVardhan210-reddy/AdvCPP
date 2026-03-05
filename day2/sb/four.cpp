#include<iostream>
#include<map>


int main()
{
    std::map<int, std::string> datax;
    datax[1] = "iron man";
    datax[2] = "wonder woman";
    datax[4] = "batman";

    for (const auto& [id, name] : datax)
    {
        std::cout << id << " --> " << name << std::endl;
    }
    return 0;
    
}