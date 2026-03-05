#include<iostream>
#include<tuple>

int main()
{
    std::tuple<int, int, int, int> p = {10, 20, 30, 56};

    auto [vara, varb, varc, vard] = p;
    auto varx = std::get<0>(p);
 //   std::cout << "varx =" << varx << std::endl;
    
}