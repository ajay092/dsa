#include <bits/stdc++.h>

using namespace std;

void quickSort(vector<int> &V, int left, int right);
int partition(vector<int> &V, int left, int right);
void swap(int &a, int &b);

int main(){
                //   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 
    vector<int> V = {4, 7, 9, 2, 4, 1, 7, 5, 2, 8, 9,  3,   6,  1,  3};
    
    quickSort(V, 0, V.size()-1);
    
    for(auto v:V)
        cout<<v<<" ";
    cout<<endl;
    
    return 0;
}

void quickSort(vector<int> &V, int left, int right){
    if(left < right){
    int pi = partition(V, left, right);
    
    quickSort(V, left, pi-1);
    quickSort(V, pi+1, right);
    }
}

int partition(vector<int> &V, int left, int right){
    int pivot = V[right];
    int p_index = left;
    
    for(int i=left;i<right;i++){
    
        if(V[i] < pivot){
            if(i!=p_index)
            swap(V[i], V[p_index]);
            p_index++;
        }
    }
    
    swap(V[right], V[p_index]);
    
    return p_index;
}

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}