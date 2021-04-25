#include <iostream>
#include <cmath>

bool isPrime(long n);

int main(int argc, char* argv[])
{
	std::cout << isPrime(1) << std::endl;
	
	return 0;
}

bool isPrime(long n)
{
	for(long i=2; i<sqrt(n); i++)
	{
		if(!(n%i))
			return false;
	}
	return true;
}