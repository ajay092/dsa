#include <bits/stdc++.h>

using namespace std;

int maxVal(int l[], int p[], int m);

int main(){
    int m = 8;
    int l[8]={1, 2, 3, 4, 5, 6, 7, 8};
    int p[8]={1, 5, 8, 9, 10, 17, 17, 20};

    
    for(int i=0;i<=m;i++){
        int result = maxVal(l, p, i);
        cout<<i<<" -> "<<result<<endl;
    }
    
    return 0;
}

int maxVal(int l[], int p[], int m){
    int table[1+m] = {0};
    
    for(int i=0;i<m;i++){
        table[i+1] = p[i];
    }
//     cout<<table[1]<<endl;
    
    
    for(int i=2;i<=m;i++){
        int price = 0, max_price = 0;
        for(int j=0;j<=i/2;j++){
            price = table[j] + table[i-j];
            if(price > max_price)
                max_price = price;
        }
        table[i] = max_price;
    }
    return table[m];
}