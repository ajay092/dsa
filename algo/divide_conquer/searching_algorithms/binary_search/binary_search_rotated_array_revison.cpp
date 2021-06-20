#include <iostream>
#include <vector>

int get_pivot_index(std::vector<double> &A, int left, int right);
int binary_search(std::vector<double> &A, int left, int right, double key);

int main()
{
	std::vector<double> A = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
	
	double key = 10;
	
	int n = A.size();
	
	int pivot_index = get_pivot_index(A, 0, n);
	
	if(pivot_index == -1)		return 0;
	
	int result;
	if(key <= A[n-1])
	{
		result = binary_search(A, pivot_index, n-1, key);
	}
	else
	{
		result = binary_search(A, 0, pivot_index-1, key);
	}
	
	if(result == -1)
	{
		std::cout << "Key is not present in the array" << std::endl;
	}
	else
	{
		std::cout << "Key's index = "<< result << std::endl;
	}
		
	return 0;
}


int binary_search(std::vector<double> &A, int left, int right, double key)
// this function returns the index of the key in the array A if found, else it returnns -1
{
	if(left > right)
	{
		return -1;
	}
	
	int mid = (left + right)/2;
	
	if(key == A[mid])
	{
		return mid;
	}
	else if(key < A[mid]) 
	{
		return binary_search(A, left, mid-1, key);
	}
	else if(key > A[mid])
	{
		return binary_search(A, mid+1, right, key);
	}
}

int get_pivot_index(std::vector<double> &A, int left, int right)
// returns the index of the first element of the rotated part
{	
	if(A[left] <= A[right] || left > right)
	{
		std::cout << "The given array is not rotated" << std::endl;
		return -1;
	}
	
	int mid = (left + right)/2;
	
	//if(A[mid] < )
	
	if(A[left] <= A[mid]) // if true it means that left half is sorted
	{
		return get_pivot_index(A, mid+1, right);	// pivot must be between mid and right 
	}
	else if(A[mid] < A[right])
	{
		return get_pivot_index(A, left, mid-1);
	}
}