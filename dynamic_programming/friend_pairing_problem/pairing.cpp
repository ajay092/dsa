#include <bits/stdc++.h>

using namespace std;

int pairs(int n);

int main(){
    int n = 16;
    
    int result = pairs(n);
    
    cout<<result<<endl;
    
    return 0;
}

int pairs(int n){
   int table[1+n] = {0};
   table[1] = 1;
   table[2] = 2;
   for(int i=3;i<=n;i++)
    table[i] = table[i-1] + (i-1)*table[i-2];   
    
   return table[n];
}