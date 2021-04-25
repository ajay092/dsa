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
	
	cout<<ans<<endl;
	
	return 0;
}

int lcs(string s1, string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	
	int lcs[1+l1][1+l2];
	
	for(int i = 0; i<= l1; i++)
	{
		lcs[i][0] = 0;
	}
	
	for(int i = 0; i<= l2; i++)
	{
		lcs[0][i] = 0;
	}
	
	for(int i = 1; i<= l1; i++)
	{
		for(int j = 1; j<= l2; j++)
		{
			if(s1[i] == s2[j])
			{
				lcs[i][j] = 1 + lcs[i-1][j-1]; 
			}
			else
			{
				lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
			}
		}
	}
	
	return lcs[l1][l2];
}