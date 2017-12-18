#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *left,*right;
};
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}
struct node *newnode(int key)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node *insert(struct node *node_n,int k)
{
	if(node_n==NULL)
	{
		return newnode(k);
	}
	if(k<node_n->data)
	{
		node_n->left=insert(node_n->left,k);
	}
	else if(k>node_n->data)
	{
		node_n->right=insert(node_n->right,k);
	}
	return node_n;
}
int main()
{
	struct node *root=NULL;
	root=insert(root, 50);
	insert(root, 40);
    insert(root, 30);
    insert(root, 20);
    insert(root, 45);
    insert(root, 25);
    insert(root, 35);
    insert(root, 32);
    insert(root, 60);
    insert(root, 70);
    insert(root, 65);
    insert(root, 90);
    insert(root, 80);
    cout<<"\nPrinting in inorder traversal";
    inorder(root);
    cout<<"\nPrinting in preorder traversal";
    preorder(root);
    cout<<"\nPrinting in postorder traversal";
    postorder(root);
    return 0;
}