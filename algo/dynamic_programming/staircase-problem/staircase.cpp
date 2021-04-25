/* There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase.
 * The order of the steps matters.
 * 
 * ways(n) = ways(n-step1) + ways(n-step2) + ways(n-step3) + ... This counts all the possible ways of climbing stairs, where order of the steps matter. If the order didnot matter the problem becomes similar to coin
 * change problem.
 * 
 */
#include <bits/stdc++.h>

using namespace std;

int total_steps(int step[], int N, int m);

int main(){
	int N = 6;

	int step[3]={1, 3, 5};
	int m = sizeof(step)/sizeof(step[0]);
	
	int result = total_steps(step, N, m);
	
	cout<<result<<endl;
	
	return 0;
}

int total_steps(int step[], int N, int m){
	int table[1+N] = {0};
	table[0] = 1;

	for(int j = 0; j<=N; j++){
		for(int i = 0; i<m; i++){
			table[j] += (j-step[i] >= 0)? table[j-step[i]]:0;
		}
	}

	return table[N];
	
}