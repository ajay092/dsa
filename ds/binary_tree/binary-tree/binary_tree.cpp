#include <bits/stdc++.h>
#define INF 32676


using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

Node* insertBST(Node *root, int data){
    if(root == NULL) return new Node(data);
    
    if(data > root->data)
        root->right = insertBST(root->right, data);
    else
        root->left = insertBST(root->left, data);
    
    return root;
}

void printInOrder(Node *root){
    if(root == NULL) return;
    stack<Node *> s;
    Node *curr = root;
    while(curr || !s.empty()){
        while(curr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        cout<<curr->data<<" ";
        s.pop();
        curr = curr->right;
    }
    cout<<endl;
}

Node* lca(Node *root, int p, int q){
    if(root == NULL) return root;
    
    if(root->data == p || root->data == q) return root;
    
    Node *left = lca(root->left, p, q);
    Node *right = lca(root->right, p, q);
    
    if(left != NULL && right != NULL) return root;
    
    if(left == NULL && right == NULL) return NULL;
    
    return (left)?left : right ;
    
}

int main(){
    int data, i = 0;
    int p = 120, q = 1100;
    Node *root = NULL;
    
    while(i < 10){
        cin >> data;
        root = insertBST(root, data);
        i++;
    }    
    printInOrder(root);
    Node *LCA = lca(root, p, q);
    int lca_data = (LCA)?LCA->data : INF;
    cout<<"Lowest common Ancestor of "<<p<<" and "<<q<<" is: "<<lca_data<<endl;
}

