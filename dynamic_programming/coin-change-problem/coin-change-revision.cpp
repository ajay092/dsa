#include <iostream>
#include <vector>

using namespace std;

int ways(vector<int> &coins, int s);

int main()
{
	vector<int> coins = {1, 2, 3};
	
	int sum = 10;
	
	int ans = ways(coins, sum);
	
	cout<<ans<<endl;
	
	return 0;
}

int ways(vector<int> &coins, int s)
{
	int n = coins.size();
	
	int table[1+n][1+s];
	
	for(int item = 0; item <= n; item++)
	{
		for(int sum = 0; sum <= s; sum++)
		{
			if(sum==0)
				table[item][sum] = 1;
			else
				table[item][sum] = 0;
		}
	}
	
	for(int item = 1; item <= n; item++)
	{
		for(int sum = 0; sum <= s; sum++)
		{
			if(sum < coins[item-1])
				table[item][sum] = table[item-1][sum];
			else
				table[item][sum] = table[item-1][sum] + table[item][sum-coins[item-1]];
		cout<<table[item][sum]<<" ";
		}
		cout<<endl;
	}
	
	return table[n][s];
}