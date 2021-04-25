#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& arr, int key, int left, int right);

int main()
{
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int key;
	
	cout<<"Enter Key to search ";
	cin >> key;
	
	int result = search(arr, key, 0, arr.size()-1);
	
	if(result == -1)
		cout<<"Key not found"<<endl;
	else
		cout<<key<<" is present at index = "<<result<<endl;
}

int search(vector<int>& arr, int key, int left, int right)
{
	int mid = (left+right)/2;
	
	if(right < left)
		return -1;
	
	int result = 0;
	
	if(arr[mid] == key)
		return mid;
	else if(key < arr[mid])
		result = search(arr, key, left, mid-1);
	else if(key > arr[mid])
		result = search(arr, key, mid+1, right);
}