#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mss(vector<int> &A);

int main()
{
	vector<int> A = {5, 5, 10, 100, 10, 5};
	
	int ans = mss(A);
	
	cout<< ans << endl;
	
	return 0;
}

int mss(vector<int> &A)
{
	int n = A.size();
	
	int sum[1+n];
	
	sum[1] = A[0];
	sum[2] = A[1];
	
	int max_sum = A[0];
	for(int i = 3; i<=n; i++)
	{
		sum[i] = max(sum[i-1], A[i-1] + sum[i-2]);
		
		if(max_sum < sum[i])
			max_sum = sum[i];
	}
	
	return max_sum;
}