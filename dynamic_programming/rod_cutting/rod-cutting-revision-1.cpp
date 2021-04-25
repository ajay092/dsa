#include <iostream>
#include <algorithm>

using namespace std;

int rod_cut(int length, vector<int> &len, vector<int> &price);

int main()
{
	int length = 8;
	vector<int> len = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
	
	int result = rod_cut(length, len, price);
	
	cout<<result<<endl;
	
	return 0;
}

int rod_cut(int length, vector<int> &len, vector<int> &price)
{	
	int val[1+length];
	
	val[0] = 0;
	for(int l = 1; l <= length; l++)
	{
		val[l] = price[l-1];
	}
	
	for(int l = 1; l <= length; l++)
	{
		int max_price = val[l];
		for(int cut = 1; cut <= l/2; cut++)
		{
			if (max_price < (price[cut-1] + val[l-cut]))
				max_price = price[cut-1] + val[l-cut];
		}
		val[l] = max_price;
	}
	
	return val[length];
}