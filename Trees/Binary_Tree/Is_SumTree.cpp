#include<bits/stdc++.h>	
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node *right;
};
bool isLeaf(Node *node)
{
	if(node == NULL)
		return false;
	if(node->left == NULL && node->right == NULL)
		return true;
	return false;
}
bool isSumTree(Node *node)
{
	int ls,rs;
	if(node == NULL || isLeaf(node))
		return true;
	if(isSumTree(node->left) && isSumTree(node->right))
	{
		if(node->left == NULL)
			ls = 0;
		else if(isLeaf(node->left))
			ls = node->left->data;
		else
			ls = 2*(node->left->data);
			
		if(node->right == NULL)
			rs = 0;
		else if(isLeaf(node->right))
			rs = node->right->data;
		else
			rs = 2*(node->right->data);
			
		if(node->data == ls + rs)
			return true;
	}
	return false;
}
Node *newNode(int d)
{
	Node *temp = new Node;
	temp->data = d;
	temp->left = temp->right = NULL;
	return temp;
}
int main()
{
	struct Node *root  = newNode(26); 
    root->left         = newNode(10); 
    root->right        = newNode(3); 
    root->left->left   = newNode(4); 
    root->left->right  = newNode(6); 
    root->right->right = newNode(3); 
    if(isSumTree(root)) 
        cout<<"The given tree is a SumTree ";
    else
        cout<<"The given tree is not a SumTree "; 
    return 0; 		
}
