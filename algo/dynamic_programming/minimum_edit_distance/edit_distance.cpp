#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int edit_distance(string s1, string s2);

int main()
{
	string s1 = "geek";
	string s2 = "eek";
	
	cout << edit_distance(s1,s2) << endl;
	
	return 0;
}

int edit_distance(string s1, string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	
	int dp[1+l1][1+l2];
	
	fill(dp[0], dp[0]+(1+l1)*(1+l2), 0);
	
	for(int i=0; i<=l1; i++)
	{
		dp[i][0] = i;
	}
	for(int j=0; j<=l2; j++)
	{
		dp[0][j] = j;
	}
	
	for(int i=1; i<=l1; i++)
	{
		for(int j=1; j<=l2; j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
			}
		}
	}
	
	return dp[l1][l2];
}