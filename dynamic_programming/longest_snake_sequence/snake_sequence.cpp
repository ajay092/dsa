#include <bits/stdc++.h>

using namespace std;

int snake_sequence(int arr[][4], int m, int n);

int main(){
	int arr[4][4] = {{9, 6, 5, 2},
					 {8, 7, 6, 5},
					 {7, 3, 1, 6},
					 {1, 1, 1, 7}};

	int result = snake_sequence(arr, 4, 4);
	
	cout<<result<<endl;
	
	return 0;
}

int snake_sequence(int arr[][4], int m, int n){
	int T[1+m][1+n] = {0};
	
	for(int i = 1; i <=m; i++){
		for(int j = 1; j<=n; j++){
			if(i==1 && j==1) T[i][j] = 1;
			else{
				int top = (i>1)? arr[i-2][j-1]: arr[i-1][j-1];
				int left = (j>1)? arr[i-1][j-2]: arr[i-1][j-1];
				
				int snake_top = (abs(top-arr[i-1][j-1]) == 1)?T[i-1][j] : 0;
				int snake_left = (abs(left-arr[i-1][j-1]) == 1)?T[i][j-1] : 0;
				
				T[i][j] = 1+ max(snake_top, snake_left);
// 				
				cout<<i<<" "<<j<<" ---> ";
				cout<<snake_top<<"\t"<<snake_left<<endl;
				
			}
		}
	}
	
	return T[m][n];
}