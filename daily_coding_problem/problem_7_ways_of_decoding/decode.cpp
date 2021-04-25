#include <bits/stdc++.h>

using namespace std;

int decode(string &message){
	int result = 0;
	int length = message.length();
	int table[1+length]{0};
	table[0] = 1;
	table[1] = 1;
	
	for(int i = 2;i<=length;i++){
		table[i] = table[i-1];
		
	if(stoi(message.substr(i-2,2)) <= 26)
		table[i] += table[i-2];
	}
	
	return table[length];
}

int main(){
	string message = "111";
	
	int result = decode(message);
	
	cout<<result<<endl;
	return 0;
}

