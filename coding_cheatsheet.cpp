#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>

#include <vector>
#include <list>

#include <queue>
#include <stack>

#include <map>
#include <set>

#include <unordered_map>
#include <unordered_set>

//==============
priority queue
//==============
include <queue>
priority_queue<int, vector<int>, greater<int> > que;
class comparator
{
	bool operator()(int a, int b)
	{
		return (a < b);
	}
};
priority_queue<int, vector<int>, comparator > que;

//==============
vector
//==============
1) size()
2) resize()
3)