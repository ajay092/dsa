#include <bits/stdc++.h>

using namespace std;

int lps(string str);
void print_lps(string str, int T[][6]);

int main(){
	string str = "agbdba";
	
	int result = lps(str);
	
	cout<<result<<endl;
	
	return 0;
}

int lps(string str)
{
	int n = str.length();
	
	int T[1+n][1+n]; 
	
	for(int i = 0; i<=n; i++)
	{
		for(int j = 0; j<=n; j++)
		{
			if(i==j)
				T[i][j] = 1;
			else
				T[i][j] = 0;
		}
	}
	
	for(int length = 1; length <= n; length++)
	{
		for(int start = 1; start <= n+1-length; start++)
		{
			int end = start+length-1;
			if(str[start-1]==str[end-1])
				T[start][end] = T[start+1][end-1] + 2;
			else
				T[start][end] = max(T[start][end-1], T[start-1][end]);
		}
	}
	
	return T[1][n];
}