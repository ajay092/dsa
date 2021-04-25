#include <iostream>
#include "binary-tree.h"

using namespace std;

Btree::Btree(int data)	//constructor
{
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}