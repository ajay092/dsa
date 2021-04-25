#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <iostream>

using namespace std;

class segmentTree{
private:
	int arr[size];
	int size;
public:
	void setArray();
	void getSum(int start, int end);
};
#endif