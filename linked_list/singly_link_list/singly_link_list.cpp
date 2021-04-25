#include "singly_link_list.h"

using namespace std;

LinkList::LinkList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

void LinkList::createList(const vector<int> &arr)
{
	Node *ptr = nullptr;
	for(int i = 0; i < arr.size(); i++)
	{
		if(i==0)
		{
			this->head = new Node(arr[i]);
			ptr = head;
			this->tail = head;
			this->size = 1;
		}
		else
		{
			ptr->next = new Node(arr[i]);
			ptr = ptr->next;
			this->tail = ptr;
			this->size++;
		}
	}
}

void LinkList::printList()
{
	Node *ptr = this->head;
	while(ptr)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

void LinkList::push_back(int data)
{
	Node *temp = new Node(data);
	
	temp->next = this->tail->next;
	
	this->tail->next = temp;
	
	this->tail = temp;
	
	this->size++;
}

void LinkList::push_front(int data)
{
	Node *temp = new Node(data);
	
	temp->next = this->head;
	
	this->head = temp;
		
	this->size++;
}

void LinkList::pop_back()
{
	Node *curr = head;
	
	while(curr->next != this->tail)
	{
		curr = curr->next;
	}
	
	curr->next = this->tail->next;
	
	Node *temp = this->tail;
	
	this->tail = curr;
	
	delete temp;
	
	this->size--;
}

void LinkList::pop_front()
{
	Node *temp = this->head;
	
	this->head = this->head->next;
	
	delete temp;
		
	this->size--;
}

int LinkList::pop_at(Node* &ptr)
{
	Node *temp = ptr;
	
	int val = temp->data;
	
	ptr = ptr->next;
	
	delete temp;
	
	this->size--;
	
	return val; 
}

void LinkList::quick_sort(Node *start, Node *end)
{
	if(start == end) return;
	
	Node *pIndex = qs_partition(start, end);
	
	cout<<start->data<<"  "<<pIndex->data<<endl;
	
	Node *left_end = start, *right_start = pIndex->next;
	while(left_end->next!= pIndex)	left_end = left_end->next;
	quick_sort(start, left_end);
	quick_sort(right_start, this->tail);
	
}

Node* LinkList::qs_partition(Node *start, Node *end)
{
	Node *pivot = end;
	
	Node *curr = start;
	
	while(curr != end)
	{
		if(curr->data > pivot->data)
		{
			push_back(pop_at(curr));
		}
		else
		{
			curr = curr->next;
		}
	}
	return pivot;
}

// rotateList(int k);