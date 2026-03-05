#include<iostream>
#include<string>
#include<string_view>
int main()
{
	std::string r = "hello"; 
	const std::string s = "hello"; 
	const char* p = "hello";
	p[0] = 'H';

	std::cout << "hello assigned to r " << (void*) r.data() << "\n";
	std::cout << "hello assigned to s " << (void*) s.data() << "\n";

	return 0;
}
