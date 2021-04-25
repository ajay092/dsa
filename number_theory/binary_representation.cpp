#include <iostream>

std::string binaryRepresentation(int n);

int main()
{
	std::cout << binaryRepresentation(10) << std::endl;
	
	return 0;
}

std::string binaryRepresentation(int n)
{
	std::string binary;
	
	while(n>0)
	{
		if(n%2)
		{
			binary.insert(0, "1");
		}
		else
		{
			binary.insert(0, "0");
		}
		
		n /= 2;
	}
	
	return binary;
}