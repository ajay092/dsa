#include <bits/stdc++.h>

using namespace std;

class Node{
	public:
		int data;
		Node *left;
		Node *right;
		
		Node (int data){
			this->data = data;
			left = NULL;
			right = NULL;
		}
};

	Node* insertBST(Node *root, int data){
		if(root == NULL) return new Node(data);
		
		if(data <= root->data)
			root->left = insertBST(root->left, data);
		else	
			root->right = insertBST(root->right, data);
		
		return root;
	}
	
	void inOrder(Node *root){
		if(root == NULL)	return;
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
	
	void preOrder(Node *root){
		if(root ==NULL)	return;
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
	
	void postOrder(Node *root){
		if(root ==NULL)	return;
		inOrder(root->left);
		inOrder(root->right);
		cout<<root->data<<" ";
	}
	
	void levelOrder(Node *root){
		if(root == NULL) return;
		
		queue<Node *> q;
		q.push(root);
		while(!q.empty()){
			Node *root = q.front();
			
			cout<<root->data<<" ";
			q.pop();
			
			if(root->left)
				q.push(root->left);
			if(root->right)
				q.push(root->right);
		}
	}

	int kSmallest(Node *root, int k){
		stack<Node *> s;
		Node *curr = root;
		s.push(curr);
		int count = 0;
		while(!s.empty()){
			while(curr){
				s.push(curr);
				curr = curr->left;
			}
			curr = s.top();
			s.pop();
			count++;
			//cout<<count<<endl;
			if(count==k && !s.empty()) return curr->data;
			curr = curr->right;
		}
		cout<<"Invalid k value...returning garbage\n";
		return -36727;
	}

int main(){
	int data;
	int k = 10;
	Node *root = NULL;
	for(int i = 0; i<10; i++){
		cin >> data;
		root = insertBST(root, data);
	}
	
	inOrder(root);
	cout<<endl;
	
	cout<<kSmallest(root, k)<<endl;
	
	cout<<endl;
	
}