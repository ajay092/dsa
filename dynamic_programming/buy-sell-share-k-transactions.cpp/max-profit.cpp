#include <iostream>
#include <vector>

#define INT_MIN -1000000;

using namespace std;

int max_profit(vector<int> &prices, int k);

int main()
{
	vector<int> prices = {5, 11, 3, 50, 60, 90};
	
	int k = 3;
	
	int ans = max_profit(prices, k);
	
	cout<<ans<<endl;
	
	return 0;
}

int max_profit(vector<int> &prices, int k)
{
	int n = prices.size();
	
	int profit[1+k][1+n];
	
	for(int i = 0; i <= k; i++)
	{
		profit[i][0] = 0;
		profit[i][1] = 0;
	}
	for(int i = 0; i <= n; i++)
	{
		profit[0][i] = 0;
	}
	
	for(int i = 1; i<= k; i++)	// i represents transactions
	{
		int max_m = INT_MIN;
		for(int j = 2; j<= n; j++)	// j represents days
		{
			max_m = max(max_m, profit[i-1][j-1] - prices[j-2]);
			
			int option1 = profit[i][j-1];
			int option2 = prices[j-1] + max_m;
			
			profit[i][j] = max(option1, option2);
		}
		
	}
	
	return profit[k][n];
	
}