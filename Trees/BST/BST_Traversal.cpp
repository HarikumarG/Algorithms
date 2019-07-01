#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *left,*right;
};
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);	
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);	
		cout<<root->data<<" ";
	}
}
node *newnode(int key)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->left=temp->right=NULL;
	temp->data=key;
	return temp;
}
node *insert(node *root,int key)
{
	if(root==NULL)
		return newnode(key);
	else if(root->data>key)
		root->left=insert(root->left,key);
	else if(root->data<key)
		root->right=insert(root->right,key);
	return root;
}
int main()
{
	struct node *root=NULL;
	root=insert(root,50);
	insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    cout<<"In order\n";
    inorder(root);
    cout<<"\nPre order\n";
    preorder(root);
    cout<<"\nPost order\n";
    postorder(root);
    return 0;
}