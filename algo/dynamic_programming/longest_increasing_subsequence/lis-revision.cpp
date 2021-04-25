#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> &A);
void print_lis(vector<int> &A);

int main()
{
	vector<int> A = {2, 3, 4, 5, 0, 6, 1};
	
	int ans = lis(A);
	
	cout<<ans<<endl;
	
// 	print_lis(A);
	
	return 0;
}

int lis(vector<int> &A)
{
	int n = A.size();
	
	int table[1+n] = {0};
	
	for(int i = 1; i<= n; i++)
	{
		table[i] = 1;
	}
	int max = 1;
	for(int i = 2; i<= n; i++)
	{
		int max_i = 1;
		for(int j = 1; j < i; j++)
		{
			if(A[i-1] > A[j-1] && max_i < 1+table[j])
				max_i = 1 + table[j];
		}
		
		table[i] = max_i;
		
		if(max < table[i])
			max = table[i];
	}
	
	return max;
}

void print_lis(vector<int> &A)
{
	int n = A.size();
	
	vector<vector<int>> lis(1+n);
	
	lis[1].push_back(A[0]);
	
	for(int i = 2; i<= n; i++)
	{
		for(int j = 1; j < i; j++)
		{
			if(A[i-1] > A[j-1] && lis[i].size() < 1+lis[j].size())
				lis[i] = lis[j];
		}
		
		lis[i].push_back(A[i-1]);
	}
	
	vector<int> result = lis[1];
	for(vector<int> row : lis)
	{
		if(row.size() > result.size())
			result = row;
	}
	
	for(auto x : result)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}