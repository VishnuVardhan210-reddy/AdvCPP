#include<iostream>
namespace Toshiba 
{
    namespace bcs 
    {
        void run()
        {
            std::cout << "Running\n";
        }
    }
}

namespace Toshiba::bcs 
{
    void run()
    {
        std::cout << "Running\n";
    }
}

