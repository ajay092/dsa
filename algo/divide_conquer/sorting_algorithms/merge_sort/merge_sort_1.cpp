#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &arr, int left, int right);
void merge(vector<int> &arr, int left, int right);

int main()
{
    vector<int> input_arr = {1, 2, 100, 4, 5};

    merge_sort(input_arr, 0, input_arr.size() - 1);

    for(auto &x : input_arr) 
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

void merge_sort(vector<int> &arr, int left, int right)
{
    if (left >= right)
    return;

    int mid = (left + right) / 2;

    // sort left half of the array
    merge_sort(arr, left, mid);

    // sort right half of the array
    merge_sort(arr, mid + 1, right);

    // merge the left and right halves
    merge(arr, left, right);
}

void merge(vector<int> &arr, int left, int right)
/*
code to merge the array between left and right indices
*/
{
    int mid = (left + right) / 2;
    int i = 0 ,j = 0;
    
    vector<int> temp_arr;

    for (i = left, j = mid + 1; i <= mid && j <= right;)
    {
        if(arr[i] <= arr[j])
        {
            temp_arr.push_back(arr[i++]);
        }
        else
        {
            temp_arr.push_back(arr[j++]);
        }
    }

    while (j <= right)
    {
        temp_arr.push_back(arr[j++]);
    }
    while (i <= mid)
    {
        temp_arr.push_back(arr[i++]);
    }

    for(i = 0; i < temp_arr.size(); i++)
    {
        arr[left + i] = temp_arr[i];
    }
}