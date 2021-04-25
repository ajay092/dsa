#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

vector<int> k_sorted(vector< list<int> > &arr);

int main()
{
	vector< list<int> > arr = {{1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}};
	
	vector<int> result = k_sorted(arr);
	
	for(auto &x : result)
		cout<<x<<"\t";
	cout<<endl;
	
	return 0;
}

vector<int> k_sorted(vector< list<int> > &arr)
{
	vector<int> result;
	
	priority_queue<pi, vector<pi>, greater<pi> > min_heap;
	
	for(int row=0; row<arr.size();row++)
	{
		min_heap.push(make_pair(arr[row].front(), row));
	}
	
	while(!min_heap.empty())
	{
		pi p = min_heap.top();
		min_heap.pop();
		result.push_back(p.first);
		arr[p.second].pop_front();
		
		if(!arr[p.second].empty())
		min_heap.push(make_pair(arr[p.second].front(), p.second));
	}
	return result;
}