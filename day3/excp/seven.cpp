#include<iostream>
#include<stdexcept> 

int main() {
    try {
        throw std::out_of_range("index");
    } catch (const std::invalid_argument& e) {
        std::cout <<"caught invalid argument " << e.what() << "\n";
    } catch (const std::out_of_range& e) {
        std::cout <<"caught out of range error: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout <<"caught exception: " << e.what() << "\n";
    } catch(...) {
        
    }
}