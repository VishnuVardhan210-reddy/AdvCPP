#include <iostream> 
#include <string> 
#include<string_view>
#include<vector> 
#include<utility> 
#include<type_traits> 

int& f(int& x) { std::cout << "f(int&) --> lvalue\n"; 
} 
int&& f(int&& x) { std::cout << "f(int&&) -> rvalue (prvalue/xvalue)\n";} 

int main() {
	int a = 10; 
	f(a); 
	f(42);
	f(a + 1);
	f(std::move(a)); 
	std::string s1 = std::string("hi"); 
	s1 += " there"; 
	}



