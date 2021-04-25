#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProd(int len);

int main()
{	
	cout << maxProd(10) << endl;
	
	return 0;
}

int maxProd(int len)
{
	vector<int> dp(len+1,0);
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	
	
	for(int i=3; i<=len; i++)
	{
		int max_prod = i;
		for(int j=1; j<=i/2; j++)
		{
			max_prod = max(max_prod, dp[j]*dp[i-j]);
		}
		dp[i] = max_prod;
		cout << i << " " << dp[i] << endl; 
	}

	return dp[len];
}