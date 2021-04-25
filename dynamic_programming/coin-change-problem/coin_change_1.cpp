#include <bits/stdc++.h>

using namespace std;

int count_dp(int s[], int n, int dp[], int );
int count_rec(int s[], int m, int n);

int main(){
	int n = 4;
	int s[4] = {2, 3, 5, 6};
	int m = sizeof(s)/sizeof(s[0]);
	
	sort(s, s+m);
	
// 	int dp[1+n] = {0};
	
// 	for(int i=0;i<=n;i++){
// 		dp[i] = -1;
// 	}
// 	int result = count_dp(s, n, dp, m-1);
	int result = count_rec(s, m-1, n);
	
	cout<<"No of ways = "<<result<<endl;
}

int count_rec(int s[], int m, int n){
	if(n<0) return 0;
	
	if(n==0) return 1;
	
// 	if(n < s[0]) return 0;
	
	if(m<0 && n>=1) return 0;
	
	int result = count_rec(s, m-1, n) + count_rec(s, m-1, n-s[m-1]);
	
	return result;
}

int count_dp(int s[], int n, int dp[], int i){
	if(dp[n]!= -1) return dp[n];
	
	if(n<0) return 0;
	
	if(n==0) return 1;
	
	if(n>0 && n<s[0]) return 0;
	
	/*if(n<){
		
	}else{
		
	}*/
	
}