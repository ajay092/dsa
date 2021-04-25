/* Given a string return the largest substring that is a palindrome*/ 
#include <bits/stdc++.h>

using namespace std;

int lps(string str);
void print_lps(string str, int T[][6]);

int main(){
	string str = "agbdba";
	
	int result = lps(str);
	
	cout<<result<<endl;
	
	return 0;
}

int lps(string str){
	int n = str.length();
	
	int T[6][6] = {0};
	
	for(int i=0; i<n; i++){
		T[i][i] = 1;
	}
	
	for(int l = 2; l<=n; l++){
		for(int i=0; i<=n-l; i++){
			int j = i+l-1;
			if(str.at(i) == str.at(j)){
				T[i][j] = T[i+1][j-1] + 2;
			}else{
				T[i][j] = max(T[i+1][j], T[i][j-1]);
			}
		}
	}
	print_lps(str, T);
	return T[0][n-1];
}

void print_lps(string str, int T[6][6]){
	int n = str.length();
	int i = 0, j= n-1, index=0;
	int rl = T[0][n-1] -1;
	vector<char> result;
	result.resize(rl+1);
	while(i<=j){
		
		if(str.at(i) == str.at(j)){
			result[index] = str.at(i);
			result[rl-index] = result[index];
			index++;
			i++;
			j--;
		}else{
			if(T[i+1][j] > T[i][j-1]){
				i++;
			}else{
				j--;
			}
		}
	}
	for(char ch : result) cout<<ch;
	cout<<endl;
}