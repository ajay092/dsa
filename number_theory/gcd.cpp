#include <iostream>
#include <cmath>

int gcd(int a, int b);


int main(int argc, char* argv[])
{
	std::cout << gcd(10, 20) << std::endl;
	
	return 0;
}

int gcd(int a, int b)
{	
	if(a < b)
		std::swap(a, b);
	
	int r = b;
	
	while(r > 0)
	{
		r = a%b;
		a = b;
		b = r;
	}
		
	return a;
}