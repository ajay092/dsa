#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quick_sort(vector<int>& arr, int left, int right);
int getPivotIndex(vector<int>& arr, int left, int right);

int main()
{
	vector<int> arr = {2, 56, 7, 45, 34, 50, 98, 45, 76, 10, 32, 78};
	
	quick_sort(arr, 0, arr.size()-1);
	
	for(int x:arr)
		cout<<x<<"\t";
	
	cout<<endl;
	
}

void quick_sort(vector<int>& arr, int left, int right)
{
	if (right < left)
		return;
	
	int mid = getPivotIndex(arr, left, right);
	
	quick_sort(arr, left, mid-1);
	quick_sort(arr, mid+1, right);
}

int getPivotIndex(vector<int>& arr, int left, int right)
{
	int index = left;
	int pivot = arr[right];
	
	for(int i = left; i<right; i++)
	{
		if(arr[i] < pivot)
		{
			swap(arr[i], arr[index]);
			index++;
		}
	}
	swap(arr[right], arr[index]);
	return index;
}