#include <iostream>

template <typename T> 
class Box 
{
private:
    T value;
public: 
    Box (T v) : value (v) {        
    }
    T getValue() const {
        return value;
    }
};

int main() 
{
    Box<int> bi (10);
    Box<double> bd (10.11);

}

