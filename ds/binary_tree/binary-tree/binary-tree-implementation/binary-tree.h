#ifndef BTREE
#define BTREE

#include <iostream>

using namespace std;

class Btree
{
private:
	
public:
	int data;
	Btree *left;
	Btree *right;
	Btree(int data);
};

#endif