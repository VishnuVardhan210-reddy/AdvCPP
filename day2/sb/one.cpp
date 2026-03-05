#include<iostream>
#include<utility>

int main()
{
    std::pair<int, int> p = {10, 20};
/*    int varx = p.first;
    int vary = p.second;*/

    auto [varx, vary] = p;
    std::cout << "varx =" << varx << std::endl;
    
}