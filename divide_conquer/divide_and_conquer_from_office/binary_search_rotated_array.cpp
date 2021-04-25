#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int binary_search(vector<int> &A, int left, int right, int key);
int get_pivot(vector<int> &A, int left, int right);

int main(){
    vector<int> A = { 1, 2, 3, 4, 5, 8, 9, 10};
    int key = 9;
    int pivot = get_pivot(A, 0, A.size()-1);
    //cout<<pivot<<endl;
    int found = binary_search(A, 0, pivot, key);
    if(found == -1){
        found = binary_search(A, pivot+1, A.size()-1, key);
    }
    
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

int get_pivot(vector<int> &A, int left, int right){
    int mid = (left + right)/2;
    
    if(left >= right){
        return 0;
    }else if(A[mid] > A[mid+1])
        return mid;
    else return (get_pivot(A, left, mid) + get_pivot(A, mid+1, right) ) ;
}