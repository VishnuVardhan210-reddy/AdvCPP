#include<iostream>
#include<stdexcept> 

int main() {
    try {
        throw std::out_of_range("index");
    } catch (const std::logic_error& e) {
        std::cout <<"caught logic error: " << e.what() << "\n";
    } catch (const std::out_of_range& e) {
        std::cout <<"caught out of range error: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout <<"caught exception: " << e.what() << "\n";
    } catch(...) {
        
    }
}