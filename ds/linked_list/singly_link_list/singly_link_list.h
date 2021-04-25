#ifndef SINGLY_LINK_LIST_H
#define SINGLY_LINK_LIST_H

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int new_data): data(new_data), next(nullptr) {}
};

class LinkList
{
	private:
	public:
		Node *head;
		Node *tail;
		int size;
		LinkList();
		void createList(const vector<int> &arr);
		void printList();
		
		void push_back(int data);
		void push_front(int data);
		
		void pop_back();
		void pop_front();
		int pop_at(Node* &ptr);
		
		void quick_sort(Node *start, Node *end);
		Node* qs_partition(Node *start, Node *end);
// 		rotateList(int k);
};
#endif