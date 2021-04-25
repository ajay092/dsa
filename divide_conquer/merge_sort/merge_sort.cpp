#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int> &A, int left, int right);
void merge(vector<int> &A, int left, int mid, int right);

int main(){
	vector<int> A = {3, 9, 4, 6, 2, 0, 3, -6, 98, 34 ,2 , 1, 55};
// 	vector<int> A = {3, 9, 4};
	
	mergeSort(A, 0, A.size()-1);
	
	for(auto x : A)
		cout<<x<<" ";
	cout<<endl;
}

void mergeSort(vector<int> &A, int left, int right){
	if(left < right){
	int mid = (left+right)/2;
// 	cout<<left<<" "<<mid<<" "<<right<<endl;
	mergeSort(A, left, mid);
	mergeSort(A, mid+1, right);
	
	merge(A, left, mid, right);
		
	}
}

void merge(vector<int> &A, int left, int mid, int right){
	vector<int> temp;
	
	int i = left, j = mid+1;
	
	while(i<=mid && j<=right){
		if(A[i] <= A[j])
			temp.push_back(A[i++]);
		else
			temp.push_back(A[j++]);
	}
	while(i<=mid){
		temp.push_back(A[i++]);
	}
	while(j<=right){
		temp.push_back(A[j++]);
	}
	
	i=left;
	for(auto x:temp){
		A[i++] = x;
	}
}