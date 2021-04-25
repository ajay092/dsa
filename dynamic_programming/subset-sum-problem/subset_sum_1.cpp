/* Given an array of positive integers find the total number of unique ways of making a sum of N using the elements of the array.
 *  
 */
#include <bits/stdc++.h>

using namespace std;

int ways_of_sum(int arr[], int N, int m);

int main(){
	int arr[4] = {2, 4, 6, 10};
	int N = 16;
	int m = sizeof(arr)/sizeof(arr[0]);
	
	int result = ways_of_sum(arr, N, m);
	
	cout<<result<<endl;
	
	return 0;
}

int ways_of_sum(int arr[], int N, int m){
	int table[1+m][1+N] = {0};
	
	for(int i = 0; i<=m; i++){
		for(int j = 0; j<=N; j++){
			if(j==0) table[i][j] = 1;
			else{
			if(arr[i-1] > j)
				table[i][j] = table[i-1][j];
			else
				table[i][j] = table[i-1][j] + table[i-1][j-arr[i-1]];
			}
		}
	}
	
	return table[m][N];
}