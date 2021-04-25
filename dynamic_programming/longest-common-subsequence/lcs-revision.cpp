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
	int l_s1 = s1.length();
	int l_s2 = s2.length();
	
	int table[1+l_s1][1+l_s2];
	
	for(int i = 0; i<= l_s1; i++)
	{
		for(int j = 0; j<= l_s2; j++)
		{
			table[i][j] = 0;
		}
	}
	
	for(int i = 1; i<= l_s1; i++)
	{
		for(int j = 1; j<= l_s2; j++)
		{
			if(s1[i] == s2[j])
				table[i][j] = 1 + table[i-1][j-1];
			else
			{
				table[i][j] = max(table[i][j-1], table[i-1][j]);
			}
			
			cout<<table[i][j]<<" "; 
		}
		cout<<endl;
	}
	
	return table[l_s1][l_s2];
}