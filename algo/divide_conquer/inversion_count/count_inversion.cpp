#include <bits/stdc++.h>

using namespace  std;

int countInversions(vector<int> &V, int start, int end);

int main(){
    vector<int> V = {3, 2, 5, 1, 4};
    
    int inversions = countInversion(V, 0, V.size()-1);
    
    cout<<"Number of inversions = "<<inversions<<endl;
    return 0;
}

int countInversion(vector<int> &V, int start, int end){
    int mid = (start+end)/2;
    
    
    return countInversion(V, start, mid) + countInversion(V, mid+1, end);
}