#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
	
	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

class compare
{
public:
    bool operator() (Node a, Node b)
    {
        return a.data < b.data ;
    }
};

int main()
{
	Node a = Node(10);
	Node b = Node(20);
	
	priority_queue<Node, vector<Node>, compare> que;
	
	que.push(a);
	que.push(b);
	
	cout<<que.top().data<<endl;
	
	return 0;
}