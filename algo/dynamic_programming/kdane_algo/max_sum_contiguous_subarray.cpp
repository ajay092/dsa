#include <iostream>
#include <vector>

using namespace std;

int kdane(vector<int> &A);

int main()
{
	vector<int> A = {1, 2, 3, -2, 5};
	
	int ans = kdane(A);
	
	cout << ans << endl;
	
	return 0;
}

int kdane(vector<int> &A)
{
	int n = A.size();
	
	int max_sum = A[0];
	
	int sum[n];
	sum[0] = A[0];
	
	for(int i=1; i<n; i++)
	{
		sum[i] = max(sum[i-1]+A[i], A[i]);
		
		if(max_sum < sum[i])
			max_sum = sum[i];
	}
	
	return max_sum;
}