#include <iostream>
#include "binary-tree.h"
#include <stack>


using namespace std;

Btree* insert_bst(Btree *root, int data);
void inorder(Btree *root);
void preorder(Btree *root);
void postorder(Btree *root);

void inorder_iterative(Btree *root);
void preorder_iterative(Btree *root);
void postorder_iterative_2stack(Btree *root);
void postorder_iterative_1stack(Btree *root);

int main()
{
	Btree *root = new Btree(10);
	root = insert_bst(root, 20);
	root = insert_bst(root, 5);
	root = insert_bst(root, 3);
	
// 	postorder(root);
// 	cout<<endl;
// 	
// 	postorder_iterative_2stack(root);
// 	cout<<endl;
	
	postorder_iterative_1stack(root);
	cout<<endl;
	
	
	
	
	return 0;
}

Btree* insert_bst(Btree *root, int data)
{
	if(!root)
		return new Btree(data);
	
	if(data >= root->data)
	{
		root->right = insert_bst(root->right, data);
	}
	else
	{
		root->left = insert_bst(root->left, data);
	}
	
	return root;
}

void inorder(Btree *root)
{
	if(!root)
		return;
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(Btree *root)
{
	if(!root)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Btree *root)
{
	if(!root)
		return;
	
	postorder(root->left);
	postorder(root->right);
	
	cout<<root->data<<" ";
}

/* Itrerative inorder traversal logic
 * In in-order traversal, for any node, we first visit the left part of the node and then the current node, then at the end the right node. For iterative solution we take a stack, the current node that begins with 
 * the root of the tree and a while loop. If the root is present, we push it to the stack and go to the left of the node. If the current node is null we look at the stack. If the stack is not empty it means that
 * we have traversed the tree and some elements have not been printed. So pop the top element from stack. This must be the most recent node we came from. Print this node and then go to the right of that node. The
 * while loop continues until the current node is null and the stack is empty. 
 */

void inorder_iterative(Btree *root)
{
	if(!root)
		return;
	
	stack<Btree*> s;
	
	while(1)
	{
		if(root)
		{
			s.push(root);
			root = root->left;
		}
		else
		{
			if(s.empty())
				break;
			
			root = s.top();
			s.pop();
			
			cout<<root->data<<" ";
			
			root = root->right;
		}
		
	}
	
}

/* Iterative preorder traversal logic
 * Iterative preorder works very similar to inorder. Here we visit the current node if its presnt and first print it. Then we push it to the stack and go to the left of the current node. If the current node is null
 * check if the stack is empty. If empty then break. If not pop the top element from  the stack and visit its right element.
 */

void preorder_iterative(Btree *root)
{
	if(!root)
		return;
	
	stack<Btree*> s;
	
	while(1)
	{
		if(root)
		{
			cout<<root->data<<" ";
			s.push(root);
			root = root->left;
		}
		else
		{
			if(s.empty())
				break;
			
			root = s.top()->right;
			s.pop();
		}
		
	}
	
}

/* postorder traversal logic
 * In postorder tr
 */

void postorder_iterative_2stack(Btree *root)
{
	if(!root)
		return;
	
	stack<Btree*> s1;
	stack<int> s2;
	
	while(1)
	{
		if(root)
		{
			s2.push(root->data);
			s1.push(root);
			root = root->right;
		}
		else
		{
			if(s1.empty())
				break;
			
			root = s1.top()->left;
			s1.pop();
		}
	}
	
	while(!s2.empty())
	{
		cout<<s2.top()<<" ";
		s2.pop();
	}
}


/* this still doesnot work. Segmnentation fault error.
 */
void postorder_iterative_1stack(Btree *root)
{
	if(!root)
		return;
	
	stack<Btree*> s;
	Btree *curr = root;
	while(curr || !s.empty())
	{
		if(curr)
		{
			if(curr->right)
				s.push(curr->right);
			s.push(curr);
			curr = curr->left;
		}
		else
		{
			curr = s.top();
			cout<<curr->data<<endl;
			s.pop();
			
			if(curr->right && curr->right == s.top())
			{
				s.pop();
				s.push(curr);
				curr = curr->right;
			}
			else
			{
				cout<<curr->data<<" ";
				curr = nullptr;
			}
		}
	}
}