#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{10, 20, 30, 40};

    std::cout << "v.data()      = " << (void*)v.data() << "\n";
    std::cout << "&v[0]         = " << (void*)&v[0] << "\n";
    std::cout << "&v[1]         = " << (void*)&v[1] << "\n";
    std::cout << "&v[2]         = " << (void*)&v[2] << "\n";
}