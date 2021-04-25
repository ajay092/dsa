#include <iostream>
#include <algorithm>

using namespace std;

int rod_cut(int l, int len[], int price[]);

int main()
{
	int len_rod = 8;
	int l[len_rod]={1, 2, 3, 4, 5, 6, 7, 8};
    int price[len_rod]={1, 5, 8, 9, 10, 17, 17, 20};
	
	int result = rod_cut(len_rod, l, price);
	
	cout<<result<<endl;
	
	return 0;
}

int rod_cut(int l, int len[], int price[])
{
	int T[1+l] = {0};		//T[i] represents max value obtained for length i
	
	T[0] = 0;
	for(int i = 1; i<=l; i++)
	{
		T[i] = price[i-1];
	}
	
	for(int length = 2; length<=l; length++)
	{
		int max_val = 0, val = 0;
		
		for(int i = 0; i<=length/2; i++)
		{
			val = T[i] + T[length-i];
			if(val > max_val)
				max_val = val;
		}
		T[length] = max_val;
	}
	return T[l];
}

