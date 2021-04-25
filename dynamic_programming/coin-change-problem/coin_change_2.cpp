/* Problem statement: Given a list of available coins, find the total number of ways of making a certain value N using an infinite supply of the coins from the list.
 * This problem will be solved using dynamic programing method.
 */

#include <bits/stdc++.h>

using namespace std;

int count_dp_memo(int coin[], int dp[][4],int N, int m);
int count_recur(int coin[], int N, int m);
int count_dp_tab(int coin[], int N, int m);
int count_dp_tab_space_optimized(int coin[], int N, int m);
	
int main(){
    int N = 10;
    int coin[2] = {1, 2};
    int m = sizeof(coin)/sizeof(coin[0])-1;
    int dp[1+N][4] = {0};
    for(int i=0;i<=N;i++)
        for(int j=0;j<=m;j++)
            dp[i][j] = -1;
//     int n_ways = count_dp_memo(coin, dp, N, m);
    int n_ways = count_dp_tab(coin, N, m);
//     int n_ways = count_recur(coin, N, m);
    cout<<n_ways<<endl;
}

int count_recur(int coin[], int N, int m){
    if(N<0) return 0;
    
    if(N==0) return 1;
    
    if(m<0 && N>=1) return 0;
//     cout<<"n = "<<N<<", m = "<<m<<endl;
//     cout<<"n = "<<N<<", m = "<<m-1<<"\t";
//     cout<<"n = "<<N-coin[m]<<", m = "<<m-1<<endl;
    return count_recur(coin, N, m-1)			// the mth coin is not used, so make N from the remaining m-1 coins
			+ count_recur(coin, N-coin[m], m);	// the mth coin is used once, so now we gotta make N-coin[m](remaining value) using all the coins until m(as mth coin can be used infinite number of times)
}

int count_dp_memo(int coin[],int dp[][4], int N, int m){
    if(N < 0) return 0;
    
    if(m<0) return 0;
    
    int result = 0;
    
    if(dp[N][m] != -1)
        return dp[N][m];
    if(N==0)
        result = 1;
    else {
        result = count_dp_memo(coin, dp, N, m-1)                         // excluding the mth coin
                            + count_dp_memo(coin, dp, N-coin[m], m);     // including 1 mth coin
    }
    dp[N][m] = result;
    
    return result;
}

int count_dp_tab_space_optimized(int coin[], int N, int m){
    int table[1+N] = {0};
    
    table[0] = 1;
    
    for(int i = 0;i<=m;i++){
        for(int j = coin[i];j<=N;j++){
            table[j] = table[j] + table[j-coin[i]];
        }
    }
    
    return table[N];
}

int count_dp_tab(int coin[], int N, int m){
	m++;
	int T[1+m][1+N];
    
	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=N; j++)
		{
			T[i][j] = 0;
			if(i==0)
				T[i][j] = 0;
			if(j==0)
				T[i][j] = 1;
		}
	}
	
    for(int i = 1;i<=m;i++){
        for(int j = coin[i-1];j<=N;j++){
            T[i][j] = T[i-1][j] + T[i][j-coin[i-1]];
        }
    }
    
    return T[m][N];
}
    
