#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int binary_search(vector<int> &A, int left, int right, int key);

int main(){
    vector<int> A = {1, 2, 3, 4, 5, 8};
    int key = 8;
    
    int found = binary_search(A, 0, A.size()-1, key);
    if(found == -1){
        cout<<"Element not present"<<endl;
    }else{
        cout<<"Element is present at "<<1+found<<" location"<<endl;
    }
    return 0;
}

int binary_search(vector<int> &A, int left, int right, int key){
    int mid = (left + right)/2;

//     cout<<left<<" "<<right<<" "<<mid<<endl;

    if(key == A[mid])
        return mid;
    else if(left > right)
        return -1;
    else if(key < A[mid])
       return binary_search(A, 0, mid-1, key);
    else if(key > A[mid])
        return binary_search(A, mid+1, right, key);
}