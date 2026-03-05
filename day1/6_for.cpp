#include<iostream> 
#include<vector> 
#include<ranges> 

int main() {
    std::vector<int> v{10, 20, 30, 40, 50};

    for (size_t i=0; i<v.size(); i=i+2){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    for(int value : v){
        std::cout <<value << " ";
    }
    std::cout << std::endl;
    for (int value : v | std::views::stride(2)) {
        std::cout << value << " ";
    }
    
}

