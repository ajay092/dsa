#include <bits/stdc++.h>

using namespace std;

int max_gold(int table[][4], int n);

int main(){
	int mat[4][4] = {{10, 33, 13, 15}, {22, 21, 4, 1}, {5, 0, 2, 3}, {0, 6, 14, 2}};
	int n = 4;
	int result = max_gold(mat, n);
	
	cout<<result<<endl;
	
	return 0;
}

int max_gold(int table[][4], int n){	
	int max_coins = 0;
	for(int col=n-1;col>=0;col--){
		for(int row=0;row<n;row++){
			int right = (col == n-1)? 0 : table[row][col+1];
			int right_up = (row==0 || col==n-1)? 0 : table[row-1][col+1];
			int right_down = (row==n-1 || col==n-1)? 0 : table[row+1][col+1];
			
			table[row][col] += max(right, max(right_up, right_down));
			if(table[row][col] > max_coins)
				max_coins = table[row][col];
		}
	}
	return max_coins;
}