#include <bits/stdc++.h>
#define N 3
#define INF 10000000

using namespace std;

int optimal_bst(int keys[], int freq[], int n);
int sum_freq(int freq[], int i, int j);

int main(){
	int keys[N] = {10, 12, 20};
	int freq[N] = {34, 8, 50};
	
	int result = optimal_bst(keys, freq, N);
	
	cout<<result<<endl;
}

int sum_freq(int freq[], int i, int j){	 // a helper function to calculate the sum of frequencies from ith index to jth index
	int result = 0;
	for(int index = i; index <= j; index++)
		result += freq[index];
	return result;
}

int optimal_bst(int keys[], int freq[], int n){
	int cost[n][n];
	
	for(int i=0; i<n; i++){		// first fill out the diagonal elements, 
		cost[i][i] = freq[i];
	}
	
	for(int l = 2; l<=n; l++){		// iterate over length(l) of (i,j) starting from 2 till n
		for(int i=0; i<=n-l; i++){	// find range of i
			int j = i+l-1;			// obtain j from i, since you know the length between i and j
			int min_cost = INF;
			for(int root = i; root<=j; root++){
				int c = ((root>i)?cost[i][root-1]:0) +  ((root<j)?cost[root+1][j]:0) ; 
				if(min_cost > c)
					min_cost = c;
			}
			cost[i][j] = min_cost + sum_freq(freq, i, j);
		}
	}
	return cost[0][n-1];
}

