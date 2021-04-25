#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int W);

int main()
{
	vector<int> wt = {2, 3, 4, 5, 1};
	vector<int> val = {1, 2, 5, 6, 10};
	
	int W = 8;
	
	int ans = knapsack(wt, val, W);
	
	cout<<ans<<endl;
	
	return 0;
}

int knapsack(vector<int> &wt, vector<int> &val, int W)
{
	int n = wt.size();
	
	int value[1+n][1+W];
	
	for(int item = 0; item <= n; item++)
	{
		for(int capacity = 0; capacity<=W; capacity++)
		{
			value[item][capacity] = 0;
		}
	}
	
	for(int capacity = 1; capacity<=W; capacity++)
	{
		for(int item = 1; item <=n; item++)
		{
			if(wt[item-1] > capacity)
			{
				value[item][capacity] = value[item-1][capacity];
			}
			else
			{
				value[item][capacity] = max(value[item-1][capacity], val[item-1] + value[item-1][capacity-wt[item-1]]);
			}
		}
	}
	return value[n][W];
}