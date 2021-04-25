#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int lcs(string s1, string s2);

int main()
{
	string s1 = "XMJYAUZQPQP";
	string s2 = "MZJAWXUPQ";
	
	int ans = lcs(s1, s2);
	
	cout << ans << endl;
	
	return 0;
}

int lcs(string s1, string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	
	int dp[1+l1][1+l2];

// 	memset(dp, 0, sizeof(dp));
	fill(dp[0], dp[0]+(1+l1)*(1+l2), 0);
	
	for(int i=1; i<=l1; i++)
	{
		for(int j=1; j<=l2; j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1]; 
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	print_lcs(s1, s2, dp);
	
	return dp[l1][l2];
}

// incomplete
// void print_lcs(int dp[][], string s1, string s2)
// {
// 	while(i > 0 && j>0)
// 	{
// 		if(dp[i][j])
// 	}
// }