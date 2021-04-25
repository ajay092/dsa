#include <bits/stdc++.h>

using namespace std;

int subsetSum(int s[], int sum, int index);
int subsetSum_space_optimized(int s[], int sum, int index);

int main(){
    int s[6] = {1, 3, 4, 5, 10, 12};
    int m = sizeof(s)/sizeof(s[0]);
    sort(s, s+m);
    
    int sum = 13;
    
    int result = subsetSum(s, sum, --m);
    
    cout<<result<<endl;
    
    return 0;
}

int subsetSum(int s[], int sum, int index){
    
    if(sum<0) return 0;
    
    if(index < 0 && sum > 0) return 0;
    
    if(sum == 0){
//         cout<<sum<<"  "<<index<<endl;
        return 1;
    }else if(sum<s[index]){
        return subsetSum(s, sum, index-1);
    }else{
        return subsetSum(s, sum, index-1) + subsetSum(s, sum-s[index], index-1);
    }
}


int subsetSum_space_optimized(int s[], int sum, int index){
    
    int table[1+sum]={0};
    
    table[0] = 1;
    
    for(int i=0;i<=index;i++){
        int temp[1+sum]={0};
        copy(table, table+1+sum, temp);
        for(int j=s[i];j<=sum;j++){
            table[j] = table[j] + temp[j-s[i]];
        }
    }
    return table[sum];
}