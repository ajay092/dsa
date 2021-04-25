/* Given two strings find the length of the longest subsequence common to both strings. Additionaly print the longest subsequence.*/

#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2, string &result_lcs);
	
int main(){
	string s1 = "XMJYAUZQPQP";
	string s2 = "MZJAWXUPQ";
	string result_lcs = "";
	int result = lcs(s1, s2, result_lcs);
	
	cout<<result<<endl;
	cout<<result_lcs<<endl;
	
	return 0;
}

int lcs(string s1, string s2, string &result_lcs){
	int l1 = s1.length();
	int l2 = s2.length();
	int T[1+l1][1+l2] = {0};
	
	for(int i=0; i<=l1; i++){
		for(int j=0; j<=l2; j++){
			T[i][j] = 0;
		}
	}
	
	for(int i=1; i<=l1; i++){
		for(int j=1; j<=l2; j++){
			char c_s1 = s1.at(i-1);
			char c_s2 = s2.at(j-1);
			if(c_s1 == c_s2){
				T[i][j] = 1 + T[i-1][j-1];
			}else{
				T[i][j] = max(T[i-1][j], T[i][j-1]);
			}
		}
	}
	
	/* The while loop iteratively finds the longest common subsequence using the DP table T[][]. In this we take two pointers 'i' & 'j'(the pointers to the current element of the first and the second string respectively)
	 * & start at the bottom right corner of the table i.e. T[i][j], so i=l1 & j=l2. If the characters at the pointers are same they are a part of the LCS so I insert it to my result LCS string. If they aren't same I
	 * will decrement the pointer of the string which gives me longest LCS.
	 */
	
 	int i = l1, j = l2;
	while(i>0 && j>0){
		char c_s1 = s1.at(i-1);
		char c_s2 = s2.at(j-1);
		if(c_s1 == c_s2){
			result_lcs.insert(0, 1, c_s1);
			i--;
			j--;
		}else{
			if(T[i-1][j] > T[i][j-1]){
				i--;
			}else{
				j--;
			}
		}
	}
	
	
	/*
	int i = 1, j = 1;
	while(i<=l1 && j<=l2){
		char c_s1 = s1.at(i-1);
		char c_s2 = s2.at(j-1);
		if(c_s1 == c_s2){
			result_lcs.push_back(c_s1);
			i++;
			j++;
		}else{
			if(T[i+1][j] > T[i][j+1]){
				i++;
			}else if(T[i][j+1] > T[i+1][j]){
				j++;
			}else{
				i++;
				j++;
			}
		}
	}
	*/
	
	
	return T[l1][l2];
}
