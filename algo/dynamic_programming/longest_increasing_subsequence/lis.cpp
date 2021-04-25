/* Given a list of integers find the length of longest subsequence such that the elements of the subsequence is in increasing order */

#include <bits/stdc++.h>

using namespace std;

int lis(int arr[], int n, vector<int> &result_lis);

int main(){		//0, 1,  2, 3, 4, 5, 6
	int arr[7] = {2, 3, 4, 5, 0, 6, 1};
	
	vector<int> result_lis;
	
	int result = lis(arr, sizeof(arr)/sizeof(arr[0]), result_lis);
	
	cout<<"result = "<<result<<endl;
	
	return 0;
}


int lis(int arr[], int n, vector<int> &result_lis){
	int T[n] = {0};
	
	int max = 1;
	
	for(int i=0; i<n; i++){
		T[i] = 1; // longest increasing subsequence at each point is atleast 1 as the element at ith location is a subset in itself
		int max_j = 1;
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i]){
				
				if(max_j < 1 + T[j])
					max_j = 1+T[j];
			}
		}
		T[i] = max_j;
		cout<<T[i]<<endl;
		if(max < T[i])	max = T[i];
	}
	
	return max;
}