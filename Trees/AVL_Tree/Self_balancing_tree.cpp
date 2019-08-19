#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	Node *left,*right;
	int height;
};
Node *newNode(int k)
{
	Node *newnode = new Node;
	newnode->key = k;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->height = 1;
	return newnode;
}
int height(Node *node)
{
	if(node == NULL)
		return 0;
	return node->height;
}
int getbalance(Node *node)
{
	if(node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;
	//Perform rotation
	y->left = x;
	x->right = T2;
	//Update heights
	x->height = 1+ max(height(x->left),height(x->right));
	y->height = 1+ max(height(y->left),height(y->right));
	//Return new root
	return y;
}
Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Update heights  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    // Return new root  
    return x;  
}  
Node *insert(Node *node,int k)
{
	if(node == NULL)
		return(newNode(k));
	if(k < node->key)
		node->left = insert(node->left,k);
	else if(k > node->key)
		node->right = insert(node->right,k);
	else
		return node;
	
	node->height = 1 + max(height(node->left),height(node->right));
	
	int balance = getbalance(node);
	
	//left left case
	if(balance > 1 && k < node->left->key)
		return rightRotate(node);
	//right right case
	if(balance < -1 && k > node->right->key)
		return leftRotate(node);
	//left right case
	if(balance > 1 && k > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	//right left case
	if(balance < -1 && k < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  
int main()
{
	Node *root = NULL;
	root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  
    preOrder(root);
    return 0;
}
