#include <bits/stdc++.h>

using namespace std;

int ways_of_sum(int list[], int state[], int sum);

int main(){
    int list[3] = {1, 3, 5};
    int sum = 6;
    int state[1+sum];
    for(int i=0;i<=sum;i++)
        state[i] = -1;
    
    int result = ways_of_sum(list, state, sum);
    
    cout<<result<<endl;
}

int ways_of_sum(int list[], int state[], int sum){
    int result = 0;
    if(sum < 0){
        return 0;
    }else if(sum == 0 || sum ==1){
        result = 1;
    }else if(state[sum] != -1){
        return state[sum];
    }else{
        for(int i=0;i<3;i++){
            result += ways_of_sum(list, state, sum-list[i]);
        }
        
    }
    
    state[sum] = result;
    
    return result;
}