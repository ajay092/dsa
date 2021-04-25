#include <bits/stdc++.h>

using namespace std;

int max_sum(int arr[5], int n);

int main(){
	int arr[5] = {-5, -1, 12, -5, 13};
	
	int result = max_sum(arr, 5);
	
	cout<<result<<endl;
	return 0;
}

int max_sum(int arr[5], int n){
	int table[1+n]{0};
	
	table[0] = 0;
	table[1] = arr[0];
	table[2] = max(arr[0], arr[1]);
	
	for(int i=3; i<=n; i++){
		int s1 = arr[i-1] + table[i-2];
		int s2 = table[i-1];
		int s3 = arr[i-1];
		table[i] = max(s1, max(s2, s3));
	}
	return table[n];
}