#include <iostream>
#include <vector>

using namespace std;

int ways(vector<int> &val_coin, int sum);

int main()
{
	vector<int> val_coin = {1, 2, 3};
	
	int sum = 10;
	
	int ans = ways(val_coin, sum);
	
	cout<<ans<<endl;
	
	return 0;
}

int ways(vector<int> &val_coin, int sum)
{
	int n = val_coin.size();
	
	int ways[1+n][1+sum];
	
	for(int coin = 0; coin <= n; coin++)
	{
		ways[coin][0] = 1;
	}
	
	for(int s = 1; s<=sum; s++)
	{
		ways[0][s] = 0; 
	}
	
	for(int s = 1; s<=sum; s++)
	{
		for(int coin = 1; coin <= n; coin++)
		{
			if(val_coin[coin-1] > s)
			{
				ways[coin][s] = ways[coin-1][s]; 
			}
			else
			{					//same coin is repeated 		 // current coin not used at all
				ways[coin][s] = ways[coin][s-val_coin[coin-1]] + ways[coin-1][s];
			}
		}
	}

	return ways[n][sum];
}