#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double median(vector<int> &A);

int main(){
    vector<int> A = {1, 2, 3, 5};
    
    double med = median(A);
    cout<<med<<endl;
    
    return 0;
}

double median(vector<int> &A){
    int n = A.size();
    if(n%2 == 1)
        return A[n/2];
    else return 0.5*(A[n/2-1] + A[n/2]);
    
}