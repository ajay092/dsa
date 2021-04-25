#include <bits/stdc++.h>

using namespace std;

void push_heap(vector<int> &H, int data);
void pop_heap(vector<int> &H);
void heapifyUp(vector<int> &H, int index);
void swap(vector<int> &H, int i, int j);
void print_heap(vector<int> H);
void heapifyDown(vector<int> &H, int index, int n);
void make_heap(vector<int> &H, int n);

void push_heap(vector<int> &H, int data){
	H.push_back(data);
	heapifyUp(H, H.size()-1);
}

void pop_heap(vector<int> &H, int n){
	H[0] = H[n];
	H.pop_back();
	n--;
	heapifyDown(H, 0, n);
}

int top_heap(vector<int> &H){
	
}

void heapifyUp(vector<int> &H, int index){
	int parent = (index-1)/2;
	while(H[index] > H[parent] && index != 0){
		swap(H, index, parent);
		index = parent;
		parent = (index-1)/2;
	}
}


void swap(vector<int> &H, int i, int j){
	int temp = H[j];
	H[j] = H[i];
	H[i] = temp;
}

void print_heap(vector<int> H){
	for(int item : H)
		cout<<item<<" ";
	cout<<endl;
}

void heapifyDown(vector<int> &H, int index, int n){
	if(index > (n-1)/2) return;	// then its a leaf node, so already heapified 
	
	int left = 2*index+1;		//get the left child of root
	int right = ((left + 1) < n)?left+1 : left;	//get the right child of root
	
	if(H[index] >= H[left] && H[index] >= H[right])
		return;
	
	if(H[left] > H[right]){
		swap(H, index, left);
		heapifyDown(H, left, n);
	}else{
		swap(H, index, right);
		heapifyDown(H, right, n);
	}
}

void make_heap(vector<int> &H, int n){
	for(int index = (n-1)/2;index>-1;index--)
		heapifyDown(H, index, n);
}


int main(){
	vector<int> arr = {21, 34, 5, 67, 12, 43, 9, 31, 2, 26};

	make_heap(arr, arr.size()-1);
	
	print_heap(arr);
	
	push_heap(arr, 68);
	push_heap(arr, 1);
	pop_heap(arr, arr.size()-1);
	
	print_heap(arr);
}