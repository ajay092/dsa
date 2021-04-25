#include <bits/stdc++.h>

using namespace std;

int knapsack_dp(int n, int W, int wt[], int val[]);
int knapsack_dp_space_optimized(int n, int W, int wt[], int val[]);

int main()
{
	int n = 4;
	int W = 8;
	int wt[n] = {2, 3, 4, 5};
	int val[n] = {1, 2, 5, 6};
	
	int result = knapsack_dp_space_optimized(n, W, wt, val);
	
	cout<<result<<endl;
	
	return 0;
}

int knapsack_dp(int n, int W, int wt[], int val[])
{
	int tab[1+n][1+W] = {0};
	
	for(int item=0; item<=n; item++)
	{
		for(int capacity=0; capacity<=W; capacity++)
		{
			if(wt[item-1] > capacity)
				tab[item][capacity] = tab[item-1][capacity];
			else
			{
				tab[item][capacity] = max(tab[item-1][capacity] , val[item-1]+tab[item-1][capacity-wt[item-1]]);
			}
			
		}
	}
	return tab[n][W];
}

int knapsack_dp_space_optimized(int n, int W, int wt[], int val[])
{
	int T[2][1+W] = {0};
	
	for(int capacity=0; capacity<=W; capacity++)
	{
		T[0][capacity] = 0;
		T[1][capacity] = 0;
	}
	for(int item=0; item<=n; item++)
	{
		for(int capacity=0; capacity<=W; capacity++)
		{
			if(wt[item-1] > capacity)
				T[1][capacity] = T[0][capacity];
			else
			{
				T[1][capacity] = max(T[0][capacity] , val[item-1]+T[0][capacity-wt[item-1]]);
			}
			
		}
		for(int capacity=0; capacity<=W; capacity++)
		{
			T[0][capacity] = T[1][capacity];
		}
		
	}
	return T[1][W];
}


