#include<iostream>
#include<string>
int main()
{
	char *p = "hello";
	const char* q = "hello";
	std::string r = "hello"; 
	//p[0] = 'H';

	std::cout << p << "\n";
	std::cout << q << "\n";
	return 0;
}
