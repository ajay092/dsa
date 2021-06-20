#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &arr);
void quickSort(vector<int> &arr, int start, int end);
int partition(vector<int> &A, int start, int end);

int main()
{
	vector<int> arr = {3, 6, 21, 56, 7, 89, 23, 4, 1, 45};
	
	quickSort(arr, 0, arr.size()-1);
	
	print(arr);
	
	return 0;
}

void print(vector<int> &arr)
{
	for(int x : arr)
		cout<<x<<" ";
	cout<<endl;
}

void quickSort(vector<int> &arr, int start, int end)
{
	if(start < end)
	{
		int pIndex = partition(arr, start, end);
		quickSort(arr, start, pIndex-1);
		quickSort(arr, pIndex+1, end);
	}
}

int partition(vector<int> &arr, int start, int end)
{
	int pivot = arr[end];
	int pIndex = 0;
	
	for(int i = 0; i<end; i++)
	{
		if(arr[i] < pivot)
		{
			swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}
	swap(arr[pIndex], arr[end]);
	
	return pIndex;
}