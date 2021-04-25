#include <iostream>
#include <vector>

using namespace std;

int ways(vector<int> &steps, int S);

int main()
{
	vector<int> steps = {1, 3, 5};
	int stairs = 5;
	
	int ans = ways(steps, stairs);
	
	cout<<ans<<endl;
	
	return 0;
}

int ways(vector<int> &steps, int S)
{
	int n = steps.size();
	
	int table[1+S];
	
	for(int stairs = 0; stairs <= S; stairs++)
		{
			if(stairs==0)
				table[stairs] = 1;
			else
				table[stairs] = 0;
		}

	for(int stairs = 0; stairs <= S; stairs++)
	{
		for(int item = 1; item <= n; item++)
		{
			if(stairs - steps[item-1] >= 0)
				table[stairs] += table[stairs-steps[item-1]];
			
		//cout<<table[stairs]<<" ";
		}
		//cout<<endl;
	}
	
	
	return table[S];
}