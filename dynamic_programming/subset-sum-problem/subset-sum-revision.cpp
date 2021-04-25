/* Works perfectly other versions have issues
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int subset_sum(vector<int> A, int s);

int main()
{
	vector<int> A = {2, 3, 5, 6, 8, 10};
	int sum = 10;
	
	sort(A.begin(), A.end());
	
	int ans = subset_sum(A, sum);
	
	cout<<ans<<endl;
	
	return 0;
}

int subset_sum(vector<int> A, int s)
{
	int n = A.size();
	int ways[1+n][1+s] = {0};
	
	for(int index = 0; index <= n; index++)
	{
		for(int sum = 0; sum <= s; sum++)
		{
			if(sum == 0)
				ways[index][sum] = 1;
			else
				ways[index][sum] = 0;
		}
	}
	
	for(int index = 1; index <= n; index++)		// make sure you start with 1, index means the nth element of the array you are using. So index 0 means no element.
	{
		for(int sum = 0; sum <= s; sum++)
		{
			if(A[index-1] > sum)
				ways[index][sum] = ways[index-1][sum];
			else
				ways[index][sum] = ways[index-1][sum] + ways[index-1][sum-A[index-1]];
// 			cout<<ways[index][sum]<<" ";		// use this to print the dp table 
		}
		cout<<endl;
	}
	return ways[n][s];
}