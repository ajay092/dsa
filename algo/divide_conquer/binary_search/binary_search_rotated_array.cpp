#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int rotated_binary_search(vector<int> &A, int left, int right, int key);
int get_pivot(vector<int> &A, int left, int right);

int main(){
    vector<int> A = { 8, 9, 10, 101, 1, 2, 3, 4, 5, 6 , 7 };
    int key = 7;
    
    //cout<<pivot<<endl;
    int found = rotated_binary_search(A, 0, A.size()-1, key);
    
    if(found == -1){
        cout<<"Element not present"<<endl;
    }else{
        cout<<"Element is present at "<<1+found<<" location"<<endl;
    }
    return 0;
}



int rotated_binary_search(vector<int> &A, int left, int right, int key){
    int mid = (left + right)/2;

//     cout<<left<<" "<<right<<" "<<mid<<endl;
	if(left > right)
		return -1;
	
    if(key == A[mid])
        return mid;
    
	 if(A[left] <= A[mid]){ // if left half is sorted
		if(A[left] <= key && key <= A[mid]){ // check if key exists here
			return rotated_binary_search(A, left, mid-1, key);
		}else{
			return rotated_binary_search(A, mid+1, right, key);
		}
	}else if(A[mid+1] <= key && key <= A[right]) // if right half is sorted
		return rotated_binary_search(A, mid+1, right, key); // if key exists here then search right half
	else
		return rotated_binary_search(A, left, mid-1, key); // else search left half
}

int get_pivot(vector<int> &A, int left, int right){
    int mid = (left + right)/2;
    
    if(left >= right){
        return 0;
    }else if(A[mid] > A[mid+1])
        return mid;
    else return (get_pivot(A, left, mid-1) + get_pivot(A, mid+1, right)) ;
}