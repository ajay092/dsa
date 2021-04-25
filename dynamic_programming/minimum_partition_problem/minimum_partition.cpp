#include <iostream>
#include <vector>

using namespace std;

int minPartition(vector<int> &nums);

int main()
{
	vector<int> nums = {3, 1, 4, 2, 2, 1};
	
	cout << minPartition(nums) << endl;
	
	return 0;
}

int minPartition(vector<int> &nums)
{
	int n = nums.size();
	int total_sum = 0;
	
	for(int &x : nums)
	{
		total_sum += x;
	}
	int s = total_sum/2;
	
	bool dp[1+n][1+s];
	
	fill(dp[0], dp[0]+(1+n)*(1+s), false);
	
	for(int i=0; i<=n; i++)
	{
		dp[i][0] = 1; 
	}
	
	for(int idx=1; idx<=n; idx++)
	{
		for(int sum=1; sum<=s; sum++)
		{
			if(nums[idx-1] > sum)
			{
				dp[idx][sum] = dp[idx-1][sum];
			}
			else
			{
				dp[idx][sum] = dp[idx-1][sum] || dp[idx-1][sum-nums[idx-1]];
			}
		}
	}
	int max_sum = 0;
	for(int sum=s; sum>0; sum--)
	{
		if(dp[n][sum])
		{
			max_sum = sum;
			break;
		}
	}
	return abs(total_sum - 2*max_sum);
}