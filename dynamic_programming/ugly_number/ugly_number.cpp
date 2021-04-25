#include <bits/stdc++.h>

using namespace std;


int ugly(int n){
    int i2 = 1, i3 = 1, i5 = 1;
    int ugly[n+1] = {0};
    ugly[1] = 1;
    int next_2 = 0, next_3 = 0, next_5 = 0;
    for(int i = 2;i<=n;i++){
        next_2 = ugly[i2]*2;
        next_3 = ugly[i3]*3;
        next_5 = ugly[i5]*5;
        
//         cout<<i<<"->"<<next_2<<" "<<next_3<<" "<<next_5<<endl;
        
        ugly[i] = min(next_2, min(next_3, next_5));
        if(ugly[i] == next_2) i2++;
        if(ugly[i] == next_3) i3++;
        if(ugly[i] == next_5) i5++;
    }
    return ugly[n];
}

int main(){
    int n = 150;
    int result = ugly(n);
    cout<<result<<endl;
}

