#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(vector<int> wt, vector<int> val, int W);

int main()
{
	vector<int> wt = {2, 3, 4, 5, 1};
	vector<int> val = {1, 2, 5, 6, 10};
	
	int W = 8;
	
	int ans = knapsack(wt, val, W);
	
	cout<<ans<<endl;
	
	return 0;
}

int knapsack(vector<int> wt, vector<int> val, int W)
{
	int n = wt.size();
	
	int table[1+n][1+W];
	
	for(int index = 0; index <=n; index++)
	{
		for(int capacity = 0; capacity <= W; capacity++)
		{
			table[index][capacity] = 0;
		}
	}
	
	for(int index = 1; index <=n; index++)
	{
		for(int capacity = 0; capacity <= W; capacity++)
		{
			if(capacity >= wt[index-1])		// important to note that the conditio is >= and nt just greater. In subset sum problem its only >
				table[index][capacity] = max(table[index-1][capacity], val[index-1] + table[index-1][capacity-wt[index-1]]);
			else
				table[index][capacity] = table[index-1][capacity];
			cout<<table[index][capacity]<<" ";
		}
		cout<<endl;
	}
// 	cout<<n<<W<<table[n][W]<<endl;
	
	return table[n][W];
}