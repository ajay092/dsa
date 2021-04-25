/* Given the weights and their price of n items, and a knapsack that can carry a maximum weight of 'W',, find a combination of items such that the total value of the items is maximum.
 */

#include <bits/stdc++.h>

using namespace std;

int knapsack(int wt[], int val[], int n, int W);
int knapsack_space_optimised(int wt[], int val[], int n, int W);

int main(){
	int wt[] = {2, 3, 4, 5}; // weights of the items
	int val[] = {1, 2, 5, 6}; // their values
	int n = sizeof(wt)/sizeof(wt[0]); // siz of the list
	int W = 8; // maximum weight the knapsack can carry
	
	int result = knapsack_space_optimised(wt, val, n, W);
	
	cout<<result<<endl;
	
	return 0;
}

int knapsack(int wt[], int val[], int n, int W){
	int T[1+n][1+W] = {0}; // we create a table that stores the maximum value obtainable for a given weight W(col) and n(rows) items.

	for(int item=0; item<=n;item++){
		for(int capacity=0;capacity<=W;capacity++){
			if(item==0 || capacity==0) T[item][capacity] = 0;
			else if(wt[item-1] > capacity)								// if the current item is heavier than max capacity
				T[item][capacity] = T[item-1][capacity];		// exclude that item and pick from the rest of the items
			else {
				T[item][capacity] = max(T[item-1][capacity], val[item-1]+T[item-1][capacity-wt[item-1]]); // or pick the current item and fill the remaining weight from the rest of the items
			}
		}
	}
	return T[n][W];
}

int knapsack_space_optimised(int wt[], int val[], int n, int W){
	int T[2][1+W] = {0}; // we create a table that stores the maximum value obtainable for a given weight W(col) and n(rows) items.
	
	for(int capacity=0; capacity<=W; capacity++){
		T[0][capacity] = 0;
		T[1][capacity] = 0;
	}
	
	for(int item=1; item<=n; item++){
		for(int capacity=wt[item-1]; capacity<=W; capacity++){
				T[1][capacity] = max(T[0][capacity], val[item-1] + T[0][capacity-wt[item-1]]);
		}
		
		for(int capacity=wt[item-1]; capacity<=W; capacity++){
			T[0][capacity] = T[1][capacity];
		}
	}
	return T[1][W];
}