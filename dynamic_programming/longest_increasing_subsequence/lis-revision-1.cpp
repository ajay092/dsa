#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> &A);
// void print_lis(vector<int> &A);

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
	
	int T[1+n];
	
	for(int i=0; i<=n; i++)
	{
		T[i] = 1;
	}
	
	int max = 1;
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<i; j++)
		{
			if(A[i-1] > A[j-1] && (1+T[j]) > T[i])
				T[i] = 1+T[j];
		}
		if(max < T[i])
			max = T[i];
	}
	
	return max;
}