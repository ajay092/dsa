#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &H, int i, int j);
void make_heap(vector<int> &H);
void heapify_down(vector<int> &H, int index);
void print(vector<int> &arr);
void heapify_up(vector<int> &H, int index);
void push_heap(vector<int> &H, int val);
void pop_heap(vector<int> &H);

int main()
{
	vector<int> arr = {2, 3, 6, 7, 9, 23, 43, 5, 67, 89, 1};
	
	print(arr);
	
	make_heap(arr);
	
	print(arr);
	
	push_heap(arr, 100);
	
	print(arr);
	
	pop_heap(arr);
	
	print(arr);
	
	return 0;
}

void heapify_up(vector<int> &H, int index)
{
	if(index <= 0)
		return;
	
	int parent = (index-1)/2;
	
	while(H[parent] < H[index] && index > 0)
	{
		swap(H, index, parent);
		index = parent;
		parent = (index-1)/2;
	}
}

void push_heap(vector<int> &H, int val)
{
	H.push_back(val);
	int n = H.size();
	
	heapify_up(H, n-1);
}

void pop_heap(vector<int> &H)
{
	int n = H.size()-1;
	H[0] = H[n];
	
	H.pop_back();
	
	heapify_down(H, 0);
}

void make_heap(vector<int> &H)
{
	int n = H.size();
	
	for(int index = (n-2)/2; index > -1; index--)
		heapify_down(H, index);
}

void heapify_down(vector<int> &H, int index)
{
	int n = H.size();
	
	if(index > (n-2)/2)
		return;
	
	
	int left = 2*index+1;
	int right = (left+1 < n)? left+1 : left;
	
	if(H[index] >= H[left] && H[index] >= H[right])
		return;
	
	if(H[left] >= H[right])
	{
		swap(H, index, left);
		heapify_down(H, left);
	}
	else
	{
		swap(H, index, right);
		heapify_down(H, right);
	}
}

void print(vector<int> &arr)
{
	for(auto x : arr)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}

void swap(vector<int> &H, int i, int j)
{
	int temp = H[i];
	H[i] = H[j];
	H[j] = temp;
}