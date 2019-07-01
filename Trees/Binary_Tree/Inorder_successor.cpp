#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node *right;
};
Node *newNode(int d)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=d;
	temp->left=temp->right=NULL;
	return temp;
}
void inorder(Node *root,int val,int &flag)
{
	if(root!=NULL)
	{
		inorder(root->left,val,flag);
		if(root->data == val || flag==1)
		{
			if(flag==1)
			{
				cout<<root->data;
				flag=0;
			}
			else
				flag=1;
		}
		inorder(root->right,val,flag);
	}
}
int main()
{
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6); 
    int flag=0;
    inorder(root,3,flag);
}
