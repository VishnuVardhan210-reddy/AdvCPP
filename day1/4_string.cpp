#include<iostream>
#include<string>
#include<string_view>
int main()
{
	char *p = "hello";
	const char* q = "hello";
	std::string r = "hello"; 
	std::string_view s = "hello"; 
	//s[0] = 'H';

	std::cout << "hello assigned to p " << (void*) p << "\n";
	std::cout << "hello assigned to q " << (void*) q << "\n";
	std::cout << "hello assigned to r " << (void*) r.data() << "\n";
	std::cout << "hello assigned to s " << (void*) s.data() << "\n";

	return 0;
}
